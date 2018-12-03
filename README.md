# mivip
The mivip emulator.

En este repositorio se encuentran el emulador y la wiki de los procesadores Mivip. Para ver sus especificaciones haga click [aquí](https://github.com/Mivip-org/specifications).

## Dependencias
+ glibc, uClibc u otra biblioteca estándar
+ gcc, TDM-GCC, MinGW-gcc u otro compilador de C99 
+ make o un procesador de Makefiles alternativo

## Obtener las fuentes
Para obtener el código fuente del emulador tiene dos opciones:
- Clonar el repositorio: para clonar el repositorio, ingrese en su terminal uno de los siguientes comandos
```sh
git clone "https://github.com/Mivip-org/mivip.git"
git clone "https://git.code.sf.net/p/mivip/code.git mivip"
```
- Descargar los archivos: para descargar los archivos ingrese al URL https://github.com/Mivip-org/mivip y haga click en el botón _"download"_ o, simplemente, haga click en el siguiente enlace: [:package:](https://github.com/Mivip-org/archive/master.zip)

## Compilar
Existen dos maneras de compilar el emulador mivip:
- **Dinámicamente (recomendada para uso personal, predeterminada):** Al compilar mivip dinámicamente la salida del proceso de compilación es una biblioteca compartida (dll, so). Esta biblioteca puede llegar a pesar apróximadamente 12,027 KiB (12.316 bytes) y llama a la biblioteca estándar en tiempo de ejecución.
- **Estáticamente (recomendada para distributión):** Al compilar mivip estáticamente la salida del proceso de compilación es un ejecutable (a.out, elf). Este ejecutable puede llegar a pesar 715,460 KiB (732.632 bytes), aunque esto depende de la bibliotecas con las que se haya compilado ya que están incorporadaa a él.

Para compilar el emulador de mivip ingrese uno de los siguientes comandos en su terminal preferida:
```sh
cd ./mivip
# Compilar dinámicamente
make shared # o simplemente 'make'
# Compilar estáticamente
make static
```

## Instalar
### Debian GNU/Linux
Para instalar mivip en el sistema operativo Debian, vaya a la sección [_"releases"_](https://github.com/Mivip-org/mivip/releases)  del repositorio en GitHub y descarge el paquete deb de la última versión disponible o vaya a la sección [_"files"_](https://sourceforge.net/projects/mivip/files/) del proyecto en SourceForge.net y descarge el paquete deb de la última versión desde ahí.
### Desde las fuentes
Para instalar mivip desde las fuentes previamente compiladas ingrese el siguiente comando en cualquier terminal.
```sh
make install
```
Esto instalará **solamente** el binario del emulador. No instalará ejemplos o asociará MIMEtypes a mivip. Tampoco crerá un lanzador en el menú de aplicaciones.
