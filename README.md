# mivip

## The mivip emulator.

In this repository you can find the emulator and the wiki for the Mivip processors. To see its specifications click here.

## Dependencies

glibc, uClibc, or other standard library
gcc, TDM-GCC, MinGW-gcc, bcc, DJGPP, OpenWatcom or other C99 compiler (Ansi C)
make or an alternative Makefiles renderer
Get the sources

To obtain the source code of the emulator you have two options:

Clone the repository: to clone the repository, enter one of the following commands in your terminal
git clone "https://github.com/Mivip-org/mivip.git"
git clone "https://git.code.sf.net/p/mivip/code.git myivip"
Download the files: to download the files, go to the URL https://github.com/Mivip-org/mivip and click on the "download" button or simply click on the following link: 📦
Compile

There are two ways to compile the mivip emulator:

Dynamically (recommended for personal use, default): When compiling myivip dynamically the output of the compilation process is a shared library (dll, so). This library can weigh approximately 12,027 KiB (12,316 bytes) and calls the standard library at runtime.
Statically (recommended for distribution): When compiling myivip statically the output of the compilation process is an executable (a.out, elf). This executable can weigh 715,460 KiB (732,632 bytes), although this depends on the libraries with which it has been compiled since they are incorporated into it.
To compile the mivip emulator enter one of the following commands in your preferred terminal:

cd ./mivip
# Compile dynamically
make shared # or just 'make'
# Compile statically
make static

`` `sh
cd ./mivip
# Compile dynamically
make shared # or just 'make'
# Compile statically
make static
`` ''

## Install
### Debian GNU / Linux and derivatives (Ubuntu, Linux Mint, Devuan, Bebian, Raspbian, etc.)
To install myivip on the Debian OS, go to the _ "[releases] (https://github.com/Mivip-org/mivip/releases)" _ section of the GitHub repository and download the latest version deb package available or go to the _ "[files] (https://sourceforge.net/projects/mivip/files/)" _ section of the project on SourceForge and download the latest version deb package from there.
### Other GNU / Linux distributions
To install mivip on a GNU / Linux distribution other than Debian or one of its derivatives, go to the _ "[releases] (https://github.com/Mivip-org/mivip/releases)" _ section of the repository at GitHub and download the emulator executable. ** It is possible ** that the aforementioned binary does not work on your distribution.
### Microsoft Windows (> = 5.1.26)
To install myivip on a version of Microsoft Windows greater than or equal to ** 5.1.26 ** (Microsoft Windows XP), go to the section _ "[releases] (https://github.com/Mivip-org/mivip/ releases) "_ from the repository on GitHub and download the installer indicated there.
### Microsoft Windows (<5.1.26)
To install myivip on Microsoft Windows versions less than ** 5.1.26 **, follow the installation steps for DOS systems (below).
### DOS (DR-DOS, QDOS, MS-DOS, PC-DOS, FreeDOS etc.)
To install myivip on a DOS system, go to the _ "[releases] (https://github.com/Mivip-org/mivip/releases)" _ section of the GitHub repository and download the installer or compressed file indicated there that suits you best.
### From sources
To install myivip from previously compiled sources enter the following command in any terminal.
`` `sh
make install
`` ''
This will install ** only ** the emulator binary. It will not install samples or associate MIMEtypes with myivip. It will also not create a launcher in the application menu.

## Documentation
All documentation about the mivip emulator is available on the [wiki for this repository] (https://github.com/Mivip-org/mivip/wiki). This documentation is available entirely in Spanish (Argentina) and partially in English (United States).

## License
The mivip emulator and its source code for GNU / Linux systems is licensed under the GPL v2.0 license.

The mivip emulator and its source code for DOS and Microsoft Windows systems is currently released under a GPL v2.0 license, although the tools and documentation necessary to compile it are not provided on these platforms.

The documentation and wiki for the mivip emulator are licensed under the [Creative Commons Attribution 4.0 International License] (http://creativecommons.org/licenses/by/4.0/).
