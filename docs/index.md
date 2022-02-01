# C/C++ Curso de Programación: Resumen

<a id="header"></a>

[Inicio][Index]

Este libro se centra exclusivamente en el lenguaje de programación **C** con algunas acotaciones muy puntuales sobre **C++**.

## Capítulos

1. [Fases en el desarrollo de un programa](chapter-01.md)
1. [Elementos del lenguaje C](chapter-02.md)
1. [Estructura de un programa](chapter-03.md)
1. [Entrada y salida estándar](chapter-04.md)
1. [Sentencias de control](chapter-05.md)
1. [Tipos estructurados de datos](chapter-06.md)
1. [Punteros](chapter-07.md)
1. [Más sobre funciones](chapter-08.md)
1. [Trabajar con ficheros](chapter-09.md)
<!-- 1. [El preprocesador de C](chapter-10.md) -->
<!-- 1. [Estructuras dinámicas](chapter-11.md) -->
<!-- 1. [Algoritmos](chapter-12.md) -->

## Instalaciones

Compilador para Windows:

- Descargar e instalar [Mingw-builds][Mingw]
- Establecer nueva variable de entorno para `C:\MinGW\bin`
- Instalar a través de terminal:

```bash
# Compilador para C
mingw-get install gcc

# Compilador para C++
mingw-get install g++
```

Extensiones para [VS Code][VSCode]:

- [C/C++ Extension Pack][CCppExtensionPack] (*Microsoft*)
    - [C/C++][CCpp] (*Microsoft*)
    - [C/C++ Themes][CCppThemes] (*Microsoft*)
    - [CMake][CMake] (*twxs*)
    - [CMake Tools][CMakeTools] (*Microsoft*)
    - [Doxygen Documentation Generator][DoxygenDocGen] (*Christoph Schlosser*)
    - [Better C++ Syntax][BetterCppSyntax] (*Jeff Hykin*)
    - [Remote - WSL][RemoteWSL] (*Microsoft*)
    - [Remote - Containers][RemoteContainers] (*Microsoft*)
    - [Remote - SSH][RemoteSSH] (*Microsoft*)
- [C/C++ Compile Run][CCppCompileRun] (*danielpinto8zz6*)

## Compilación y ejecución

Compilación:

```bash
# Con código objeto
gcc main.c -o main.o

# Con ejecutable
gcc main.c -o main
# ó
gcc main.c -o main.exe
```

Ejecución:

```bash
# Ruta desde la posición actual
./main.exe
```

[Inicio][Index] - [Arriba][Header]

<!-------------------------------------------------------------------------
 !  Links
-------------------------------------------------------------------------->

[Index]:    ../README.md
[Header]:   #header

[Mingw]:    https://www.mingw-w64.org/
[VSCode]:   https://code.visualstudio.com/

[CCppExtensionPack]:    https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack
[CCpp]:                 https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools
[CCppThemes]:           https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-themes
[CMake]:                https://marketplace.visualstudio.com/items?itemName=twxs.cmake
[CMakeTools]:           https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools
[DoxygenDocGen]:        https://marketplace.visualstudio.com/items?itemName=cschlosser.doxdocgen
[BetterCppSyntax]:      https://marketplace.visualstudio.com/items?itemName=jeff-hykin.better-cpp-syntax
[RemoteWSL]:            https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-wsl
[RemoteContainers]:     https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers
[RemoteSSH]:            https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-ssh
[CCppCompileRun]:       https://marketplace.visualstudio.com/items?itemName=danielpinto8zz6.c-cpp-compile-run
