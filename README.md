# mivip
The mivip emulator.

En este repositorio se encuentran el emulador y la wiki de los procesadores Mivip. Para ver sus especificaciones haga click [aquí](https://github.com/Mivip-org/specifications).

## Dependencias
+ glibc, uClibc u otra biblioteca estándar
+ gcc, TDM-GCC, MinGW-gcc, bcc, DJGPP, OpenWatcom u otro compilador de C99 (Ansi C)
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
- **Estáticamente (recomendada para distributión):** Al compilar mivip estáticamente la salida del proceso de compilación es un ejecutable (a.out, elf). Este ejecutable puede llegar a pesar 715,460 KiB (732.632 bytes), aunque esto depende de la bibliotecas con las que se haya compilado ya que están incorporadas a él.

Para compilar el emulador de mivip ingrese uno de los siguientes comandos en su terminal preferida:
```sh
cd ./mivip
# Compilar dinámicamente
make shared # o simplemente 'make'
# Compilar estáticamente
make static
```

## Instalar
### Debian GNU/Linux y derivados (Ubuntu, Linux Mint, Devuan, Bebian, Raspbian, etc.)
Para instalar mivip en el sistema operativo Debian, vaya a la sección _"[releases](https://github.com/Mivip-org/mivip/releases)"_ del repositorio en GitHub y descarge el paquete deb de la última versión disponible o vaya a la sección _"[files](https://sourceforge.net/projects/mivip/files/)"_ del proyecto en SourceForge y descarge el paquete deb de la última versión desde ahí.
### Otras distribuciones GNU/Linux
Para instalar mivip en una distribución GNU/Linux que no sea Debian o uno de sus derivados, vaya a la sección _"[releases](https://github.com/Mivip-org/mivip/releases)"_ del repositorio en GitHub y descarge el ejecutable del emulador. **Es posible** que el ya mencionado binario no funcione en su distribución.
### Microsoft Windows (>= 5.1.26)
Para instalar mivip en una versión de Microsoft Windows mayor o igual a **5.1.26** (Microsoft Windows XP), vaya a la sección _"[releases](https://github.com/Mivip-org/mivip/releases)"_ del repositorio en GitHub y descarge el instalador allí indicado.
### Microsoft Windows (< 5.1.26)
Para instalar mivip en versiones de Microsoft Windows menores a **5.1.26**, siga los pasos de instalación para sistemas DOS (a continuación).
### DOS (DR-DOS, QDOS, MS-DOS, PC-DOS, FreeDOS etc.)
Para instalar mivip en un sistema DOS, vaya a la sección _"[releases](https://github.com/Mivip-org/mivip/releases)"_ del repositorio en GitHub y descarge el instalador o el archivo comprimido allí indicado que más le convenga.
### Desde las fuentes
Para instalar mivip desde las fuentes previamente compiladas ingrese el siguiente comando en cualquier terminal.
```sh
make install
```
Esto instalará **solamente** el binario del emulador. No instalará ejemplos o asociará MIMEtypes a mivip. Tampoco crerá un lanzador en el menú de aplicaciones.

## Documentación
Toda la documentación sobre el emulador de mivip está disponible en la [wiki de este repositorio](https://github.com/Mivip-org/mivip/wiki). Esta documentación está disponible completamente en español (Argentina) y parcialmente en inglés (Estados Unidos).

## Licencia
El emulador mivip y su código fuente para sistemas GNU/Linux está liceniado bajo la licencia GPL v2.0.

El emulador mivip y su código fuente para sistemas DOS y Microsoft Windows actualmente está liberado bajo una licencia GPL v2.0, aunque no se facilitan las herramientas ni la documentación necesarias para compilarlo estas plataformas.

La documentación y la wiki del emulador mivip están licenciados bajo la [Creative Commons Attribution 4.0 International License](http://creativecommons.org/licenses/by/4.0/).
