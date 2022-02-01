# Fases en el desarrollo de un programa

<a id="header"></a>

### Contenido

- [¿Qué es un programa?][Section-01]
- [Lenguajes de programación][Section-02]
    - Compiladores
    - Intérpretes
- [¿Qué es C?][Section-03]
- [Historia del lenguaje C][Section-04]
    - Lenguaje C++
- [Realización de un programa en C][Section-05]
    - Edición de un programa
    - Compilar y ejecutar el programa
        - Biblioteca de funciones
    - Depurar un programa

[Inicio][Index]

## ¿Qué es un programa?

- Serie de instrucciones dadas al ordenador.
- Al ejecutar un programa vemos los resultados que éste produce, mas no vemos el guión.

## Lenguajes de programación

1. **Lenguaje máquina**:
    - **Bits**: 0 y 1.
    - **Byte**: 8 bits (Para representar un carácter).
1. **Lenguaje ensamblador**:
    - Códigos nemotécnicos que representan tareas.
    - Cada ordenador tiene su propio lenguaje ensamblador.
    - Lenguajes orientados a la máquina.

```
                            +-------------+
Programa escrito            | Programa    |            Programa escrito
en ensamblador      --->    | Ensamblador |    --->    en lenguaje máquina
                            +-------------+
```

3. **Lenguajes de alto nivel**:
    - Lenguajes orientados al problema.
    - Traducción llevada a cabo por el programa **compilador**.
    - Cada sentencia se descompone en varias instrucciones en ensamblador.
    - A diferencia del ensamblador, no se requiere del conocimiento de la estructura del procesador del ordenador.

### Compiladores

```
                                  +------------+
Programa escrito en un    --->    | Compilador |    --->    Programa escrito
lenguaje de alto nivel            +------------+            en lenguaje máquina
```

### Intérpretes

- Genera la traducción y ejecución simultáneamente.
- Pérdida de velocidad en la ejecución del programa.

## ¿Qué es C?

- Lenguaje de programación de alto nivel.
- El código producido por el compilador **C** está muy optimizado en tamaño, lo que redunda en una mayor velocidad de ejecución.
- **C** es independiente de la plataforma sólo en código fuente, cada plataforma diferente debe proporcionar el compilador adecuado.

## Historia del lenguaje C

- Principales características:
    - Programación estructurada.
    - Economía en las expresiones.
    - Abundancia en operadores y tipos de datos.
    - Codificación en alto y bajo nivel simultáneamente.
    - Reemplaza ventajosamente la programación en ensamblador.
    - Utilización natural de las funciones primitivas del sistema.
    - No está orientado a ningún área en especial.
    - Producción de código objeto altamente optimizado.
    - Facilidad de aprendizaje.
- **BCPL** -> **B** -> **C** (Dennis Ritchie - **UNIX**).
- Pensado para ser altamente transportable a nivel de código fuente y para programar lo improgramable.
- Inconvenientes:
    - Carece de instrucciones de entrada y salida.
    - Carece de instrucciones para manejo de cadena de caracteres, trabajo que queda para la biblioteca de funciones, lo que favorece la pérdida de transportabilidad.

### Lenguaje C++

- **C** -> **C con Clases** -> **C++**.

## Realización de un programa en C

- Entorno de desarrollo **C/C++**:
    1. Editor de texto.
    1. Compilador C/C++ (+ Enlazador).
    1. Depurador.

### Edición de un programa

- Extensión del fichero: `.c` ó `.cpp`.
- Escribir el código en el editor de textos.
- Directrices: `#`, procesadas por el preprocesador de **C** cuando se invoca al compilador, pero antes de iniciarse la compilación.
- Guardar el programa escrito, en el disco.

### Compilar y ejecutar el programa

```bash
# Línea de comandos Windows
cl saludo.c

# Línea de comandos UNIX
# Por defecto: a.out
cc saludo.c -o saludo
```

- **Compilar**: traducir el programa fuente a lenguaje máquina.
- Posteriormente **enlazarlo** con las funciones necesarias de la biblioteca de C.
- **Errores de compilación**: sintaxis y reglas del compilador.

#### Biblioteca de funciones

- Fichero separado en el disco que contiene las funciones que realizan las tareas más comunes (`.lib` en Windows o `.a` en UNIX).

```
                         Programa fuente          +---------------------+
                               ↓                  | Programa ejecutable |
Ficheros de      --->    Preprocesador            +---------------------+
cabecera (.h)            -------------                  ↑
~~~~~~~~~~~~~                  ↓                    Enlazador          <---    Biblioteca
                         Programa fuente            ---------                  de funciones
                               ↓                        ↑                      ~~~~~~~~~~~~
                         Compilador         --->    Programa objeto
                         ----------                 (.obj | .o)
```

- **Errores durante la ejecución**.
- Detener la ejecución: `Ctrl + C`.

### Depurar un programa

- En la ejecución, solución incorrecta: análisis minucioso de cómo se comporta el programa a lo largo de su ejecución: **depuración**.

[Inicio][Index] - [Arriba][Header]

<!-------------------------------------------------------------------------
 !  Links
-------------------------------------------------------------------------->

[Index]:        ../README.md
[Header]:       #header

[Section-01]:   #¿qué-es-un-programa
[Section-02]:   #lenguajes-de-programación
[Section-03]:   #¿qué-es-c
[Section-04]:   #historia-del-lenguaje-c
[Section-05]:   #realización-de-un-programa-en-c
