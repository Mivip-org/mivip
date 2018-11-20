/*
 * mivip.c
 * 
 * Copyright 2018 Alvarito050506 <donfrutosgomez@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <string.h>

unsigned char gpr[5];
FILE *fd;
unsigned char text[512];
char vid[25] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
char* regev(int pos)
{
	char* reg;
	switch(text[pos])
	{
		case 0x01:
			reg = "A0";
		break;
		case 0x02:
			reg = "B1";
		break;
		case 0x03:
			reg = "C0";
		break;
		case 0x04:
			reg = "D1";
		break;
		case 0x0a:
			reg = "Y0";
		break;
		default:
			reg = "ERR";
		break;
	}
	return reg;
}
int regas(int pos, unsigned char val)
{
	if (text[pos] != 0x0a)
	{
		gpr[text[pos]-1] = val;
	} else
	{
		gpr[4] = val;
	}
	return 0;
}
int vidas(int pos, unsigned char val)
{
	vid[pos-0xe7] = val;
	return 0;
}
int reginc(int pos)
{
	if (text[pos] != 0x0a)
	{
		gpr[text[pos]-1]++;
	} else
	{
		gpr[4]++;
	}
	return 0;
}
int regdec(int pos)
{
	if (text[pos] != 0x0a)
	{
		gpr[text[pos]-1]--;
	} else
	{
		gpr[4]--;
	}
	return 0;
}
int regval(int pos)
{
	unsigned char retval;
	if (text[pos] != 0x0a)
	{
		retval = gpr[text[pos]-1];
	} else
	{
		retval = gpr[4];
	}
	return retval;
}
int aradd(int pos, int pod)
{
	if (text[pos] != 0x0a)
	{
		gpr[text[pos]-1] = gpr[text[pos]-1] + text[pod];
	} else
	{
		gpr[4] = gpr[4] + text[pod];
	}
	return 0;
}
int arsub(int pos, int pod)
{
	if (text[pos] != 0x0a)
	{
		gpr[text[pos]-1] = gpr[text[pos]-1] + text[pod];
	} else
	{
		gpr[4] = gpr[4] - text[pod];
	}
	return 0;
}
int main(int argc, char **argv)
{
	int i = 0, running = 0;
	char *reg, *reg1;
	fd = fopen(argv[1], "rb");
	fread(text, sizeof(unsigned char), 512, fd);
	while (running == 0)
	{
		reg = regev(i+1);
		reg1 = regev(i+2);
		switch(text[i])
		{
			case 0x05:
				if (text[i+1] > 0xe6)
				{
					vidas(text[i+1], text[i+2]);
					printf("[CPU] mov 0x%x, 0x%x\n", text[i+1], text[i+2]);
					printf("[MEM] 0x%x = %c\n", text[i+1], text[i+2]);
					printf("[VID] %s\n", vid);
				} else if (text[i+1] < 0xe6 && text[i+1] > 0x0a) 
				{
					printf("[CPU] mov %s, 0x%x\n", reg, text[i+2]);
					printf("[ERR] ¡Registro inválido!\n");
					return -2;
				} else
				{
					regas(i+1, text[i+2]);
					printf("[CPU] mov %s, 0x%x\n", reg, text[i+2]);
					printf("[REG] %s = %i\n", reg, text[i+2]);
				}
				i = i + 2;
			break;
			case 0x08:
				printf("[CPU] hlt\n");
				running = 1;
			break;
			case 0x10:
				printf("[CPU] lor %s, %s\n", reg, reg1);
				if (strcmp(reg, "ERR") == 0 || strcmp(reg1, "ERR") == 0) 
				{
					printf("[ERR] ¡Registro inválido!\n");
					return -2;
				}
				regas(i+1, gpr[text[i+2]-1]);
				printf("[REG] %s = %i\n", reg, regval(i+1));
				i = i + 2;
			break;
			case 0x0c:
				printf("[CPU] inc %s\n", reg);
				reginc(i+1);
				printf("[REG] %s = %i\n", reg, regval(i+1));
				i = i + 1;
			break;
			case 0x0d:
				printf("[CPU] dec %s\n", reg);
				regdec(i+1);
				printf("[REG] %s = %i\n", reg, regval(i+1));
				i = i + 1;
			break;
			case 0x0e:
				printf("[CPU] add %s, 0x%x\n", reg, text[i+2]);
				if (regval(i+1) >= 0x80 || text[i+2] >= 0x80)
				{
					printf("[ERR] ¡Overflow!\n");
					return -1;
				}
				aradd(i+1, i+2);
				printf("[REG] %s = %i\n", reg, regval(i+1));
				i = i + 2;
			break;
			case 0x0f:
				printf("[CPU] sub %s, 0x%x\n", reg, text[i+2]);
				arsub(i+1, i+2);
				printf("[REG] %s = %i\n", reg, regval(i+1));
				i = i + 2;
			break;
			default:
			break;
		}
		i++;
	}
	fclose(fd);
	return 0;
}
