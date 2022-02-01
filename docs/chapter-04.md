# Entrada y salida estándar

<a id="header"></a>

### Contenido

- [Datos numéricos y cadenas de caracteres][Section-01]
- [Flujos de E/S estándar][Section-02]
- [Salida con formato][Section-03]
- [Entrada con formato][Section-04]
- [Carácter fin de fichero][Section-05]
- [Carácter \n][Section-06]
    - Limpiar el buffer de la entrada estándar
- [Leer un carácter de la entrada estándar][Section-07]
- [Escribir un carácter en la salida estándar][Section-08]
- [Funciones getch y getche][Section-09]
- [Limpiar la pantalla][Section-10]
- [Notas de los ejercicios resueltos][Section-11]

[Inicio][Index]

Cuando se ejecuta un programa, sucede fundamentalmente 3 tareas:

1. **Entrada** de los datos: (teclado o fichero) se almacenan en memoria.
1. **Proceso** de los datos: resultados se almacenan en memoria.
1. **Salida**: una copia de los datos en memoria (pantalla, impresora, fichero).

## Datos numéricos y cadenas de caracteres

- Datos leídos asignados a variables:

```
variable operador_de_asignación valor
         ~~~~~~~~~~~~~~~~~~~~~~
```

## Flujos de E/S estándar

- Obtener información desde o enviar a:
    - Fichero en el disco.
    - Memoria del ordenador.
    - Otro programa.
    - Internet, etc.
- **Flujo** (**Stream**):
    - Estructura de datos (bytes) intermediario entre el programa y el origen o destino.
    - Sin importar de dónde viene o a dónde va.
- Cuando se ejecuta un programa **C/C++** son abiertos automáticamente dos flujos:
    - **stdin** (*standard input*)
    - **stdout** (*standard output*)
- En **C**:
    - stdin: teclado
    - stdout: pantalla

## Salida con formato

- `printf`:
    - Escribe caracteres (bytes) en stdout.
    - Devuelve un valor entero igual al número de caracteres escritos.
    - Su declaración se encuentra en `stdio.h`.

```c
int printf( const char *formato /* [, argumento] ... */ );
```

- *formato*:
    - Cómo va a ser la salida.
    - Cadena de caracteres formada por caracteres ordinarios, secuencias de escape y especificaciones de formato.
- *argumento*:
    - Valor(es) a escribir.
    - Si hay más que especificaciones de formato, se ignoran.

```
%[ flags ][ ancho ][ .precisión ][ { h | l | L } ]tipo
```

Flags|Significado
:---|:---
`-`|Justifica a la izquierda, dentro del **ancho** especificado (por defecto derecha).
`+`|Antepone `+` ó `-` al valor (por defecto sólo `-`).
`0`|Rellena con ceros no significativos hasta alcanzar el ancho mínimo.
*blanco*|Antepone un espacio en blanco si es positivo. Si se usa con `+` se ignora.
`#`|Cuando se usa con `o`, `x` ó `X` antepone `0`, `0x`, `0X`.<br />Cuando se usa con `e`, `E`, `f` fuerza a que tengan un punto decimal.<br />Cuando se usa con `g`, `G` fuerza a que tengan un punto decimal y evita que los ceros arrastrados sean truncados.<br />Se ignora con `c`, `d`, `i`, `u`, `s`.

- *ancho*:
    - Mínimo número de posiciones para la salida.
    - Si el valor ocupa más posiciones, el ancho es incrementado en lo necesario.
- *precisión*:
    - Depende del tipo de salida.
- *tipo*:

Carácter|Salida
:---:|:---
`d`|(`int`) Enteros con signo en base 10.
`i`|(`int`) Enteros con signo en base 10 (8 o 16, depende de con qué inicie).
`u`|(`int`) Enteros sin signo en base 10.
`o`|(`int`) Enteros sin signo en base 8.
`x`|(`int`) Enteros sin signo en base 16 (01...abcdef).
`X`|(`int`) Enteros sin signo en base 16 (01...ABCDEF).
`f`|(`double`) Valor con signo de la forma: `[-]dddd.dddd`.<br />(Número de decimales por defecto: 6)
`e`|(`double`) Valor con signo, de forma: `[-]d.dddde[±]ddd`.
`E`|(`double`) Valor con signo, de forma: `[-]d.ddddE[±]ddd`.
`g`|(`double`) Valor con signo, en formato `e` o `f`.<br />(El que sea más compacto para el valor y precisión dados)
`G`|(`double`) Igual que `g` pero con *E*.
`c`|(`int`) Un sólo carácter, byte menos significativo.
`s`|(**cadena de caracteres**) Hasta el primer carácter nulo: `'\0'`.

- *ancho* y *precisión* pueden ser sustituidos por `*`, toman el valor del siguiente argumento entero.
- *precisión*:

Tipo|Significado
:---|:---
`d`, `i`, `u`, `o`, `x`, `X`|Mínimo número de dígitos que se tienen que escribir. Si es necesario se rellenan con ceros. Si excede, no se trunca.
`e`, `E`, `f`|Número de dígitos después del punto decimal. Por defecto 6. Valor redondeado.
`g`, `G`|Máximo número de dígitos significativos. Por defecto 6.
`c`|Ningún efecto
`s`|Máximo número de caracteres que se escribirán, el exceso se ignora.

Tipo|Significado
:---:|:---
`h`|Prefijo de `d`, `i`, `o`, `x`, `X` para especificar argumento `short int`.<br />Prefijo de `u` para especificar argumento `short unsigned int`.
`l`|Prefijo de `d`, `i`, `o`, `x`, `X` para especificar argumento `long int`.<br />Prefijo de `u` para especificar argumento `long unsigned int`.<br />Prefijo de `e`, `E`, `f`, `g`, `G` para especificar un `double` antes que un `float`.
`L`|Prefijo de `e`, `E`, `f`, `g`, `G` para especificar `long double`. No compatible con **ANSI C**.

## Entrada con formato

- `scanf`:
    - Lee bytes (caracteres ASCII) de stdin.
    - Cada argumento es pasado por referencia.
    - Devuelve el número de argumentos leídos y asignados.
    - Su declaración se encuentra en `stdio.h`.

```c
int scanf( const char *formato /* [, argumento] ... */ );
```

- *formato*:
    - Interpreta cada dato de entrada.
    - Por espacios en blanco, caracteres ordinarios y especificaciones de formato.
    - Si un carácter en `stdin` no es compatible con el tipo especificado por el formato, la entrada de datos se interrumpe.
- *argumento*:
    - Variable por referencia.
- Cuando se especifica más de un argumento, los valores tecleados hay que separarlos por uno o más espacios (`' '`, `\t`, `\n`) o por el carácter que se especifique en el formato.
- Un espacio en blanco antes o después de una especificación de formato, hace que `scanf` lea todos los espacios, pero no almacene, hasta encontrar un carácter distinto de espacio en blanco.
- Si se usa otro separador, colocar un espacio antes y después de él.
- No es aconsejable no incluir espacios en blanco.
- **Buffer**:
    - Memoria intermedia asociada con `stdin`.
    - Permite modificar la entrada antes de presionar `ENTER`.

```
+---------+      +--------+   ENTER    +--------+
| Teclado | ---> | Buffer | ---------> | U.C.P. |
+---------+      +--------+            +--------+
                       |                  |
                       |   +----------+   |
                       +-> | Pantalla | <-+
                           +----------+
```

- Lo que hay en el buffer realmente es una cadena de caracteres.

```
%[ * ][ ancho ][ { h | l } ]tipo
```

Elemento|Significado
:---|:---
`*`|Suprime la asignación del siguiente dato en la entrada.
*ancho*|Máximo número de caracteres a leer.
`h`|Prefijo con `d`, `i`, `n`, `o`, `x` para argumento `short int`.<br />Prefijo con `u` para argumento `short unsigned int`.
`l`|Prefijo con `d`, `i`, `n`, `o`, `x` para argumento `long int`.<br />Prefijo con `u` para argumento `long unsigned int`.<br />Prefijo con `e`, `f`, `g` para argumento `double`.
*tipo*|Similar a `printf`.

- Se puede generar una pausa con:

```c
printf( "Pulse <Entrar> para continuar" );
scanf( "%c", &car );
```

## Carácter fin de fichero

- Un dispositivo de entrada o de salida es manipulado por **C** como un fichero de datos.
- Un **fichero de datos** es una colección de información.
- Los datos introducidos y visualizados son cada uno una colección de información.
- Fichero: principio y final.
- Final de fichero (teclado):
    - `Ctrl + D` (UNIX)
    - `Ctrl + Z` (Windows)
- Fichero o dispositivo siempre es manejado a través de un flujo: fin de flujo equivalente a fin de fichero.
- Cuando `scanf` intenta leer fin de fichero devuelve la constante `EOF` (`stdio.h`).

## Carácter \n

- `ENTER`:
    - Al introducir datos por teclado: carácter `\n`, se corresponde con un `LF`.
    - En la salida `\n` produce un: `CR + LF` (ASCII 13 y 10).
- Puede traer problemas con `%g` que no lo lee, entonces la siguiente entrada posiblemente lea `\n` y no nos deje ingresar los datos deseados.
- Solución 1:

```c
scanf( "%*c%c", &car );
//      ~~~
//   se suprime
```

- Solución 2: limpiar el buffer de la entrada estándar.

### Limpiar el buffer de la entrada estándar

- Limpiar el buffer asociado con un flujo de E/S: `fflush` (`stdio.h`).

```c
// Compatibilidad: ANSI, UNIX y Windows
int fflush( FILE *flujo )
```

- Con un flujo desde el origen (**stdin**) `fflush` limpia el buffer (UNIX/Linux no tiene efecto sobre un flujo desde el origen).
- En un flujo hacia el destino, `fflush` escribe el contenido del buffer y limpia el buffer.
- `fflush` retorna **0** si se ejecuta satisfactoriamente o `EOF` si ocurre un error.
- Un buffer asociado a la salida se limpia automáticamente cuando está lleno, cuando se cierra el flujo o cuando el programa finaliza normalmente.

## Leer un carácter de la entrada estándar

- `getchar` leerá el siguiente carácter al último leído (`stdio.h`).

```c
int getchar( void );
```

- Devuelve el carácter leído, o un `EOF` si final de fichero o error.
- No hay problema en almacenarlo en una variable `char`.
- Si el buffer está vacío, `getchar` detendrá la ejecución hasta que tecleemos algo.
    - Esto es equivalente a: `scanf( "%c", &car );`
    - Por lo que lo expuesto para `\n` y **fin de fichero**, es aplicable a `getchar`.

## Escribir un carácter en la salida estándar

- `putchar`, escribirá en el monitor un carácter a continuación del último escrito (`stdio.h`).

```c
int putchar( int c );
```

- Devuelve el carácter escrito, o un `EOF` si ocurre error.
- Puede ser equivalente a `printf`:

```c
// Equivalentes:
putchar( '\n' );
printf( "\n" );
```

## Funciones getch y getche

- `getch`, lee un carácter del teclado, sin visualizarlo en el monitor (*sin eco*) (`conio.h`).
- `getche`, lee un carácter del teclado, visualizándolo en el monitor (*con eco*) (`conio.h`).

```c
// Compatibilidad: Windows
int _getch( void );
int _getche( void );
```

- Leen un carácter del buffer asociado con **stdin**.
- Cuando se ejecutan, la ejecucción se detiene hasta que se pulse una tecla (no es necesario `ENTER`).
- Puede ser un byte o dos bytes de resultado (**código ASCII**).

## Limpiar la pantalla

- La biblioteca de C no proporciona una función para limpiar la pantalla, pero sí la función `system` que envía cualquier orden al sistema operativo (`stdlib.h`).

```c
int system( const char *cadena-de-caracteres );
```

- La cadena de caracteres es pasada al intérprete de órdenes del S.O.

```c
system( "cls" );    // Windows
system( "clear" );  // UNIX
```

## Notas de los ejercicios resueltos

- Para que un carácter especial se visualice, como `%`, hay que duplicarlo: `%%`.
- Desarrollo de un programa, tres bloques en general:

```
+---------+      +---------+      +--------+
| Entrada | ---> | Proceso | ---> | Salida |
+---------+      +---------+      +--------+
```

- Para salir de una función sin hacer nada más: `return` (sentencia).
- Para salir del programa, la función `exit` (`stdlib.h`).

```c
// estado es un valor que se devuelve al proceso
// que invocó al programa para su ejecución.

void exit ( int estado );
```

- Función `sqrt` (raíz cuadrada) (`math.h`).

[Inicio][Index] - [Arriba][Header]

<!-------------------------------------------------------------------------
 !  Links
-------------------------------------------------------------------------->

[Index]:        ../README.md
[Header]:       #header

[Section-01]:   #datos-numéricos-y-cadenas-de-caracteres
[Section-02]:   #flujos-de-es-estándar
[Section-03]:   #salida-con-formato
[Section-04]:   #entrada-con-formato
[Section-05]:   #carácter-fin-de-fichero
[Section-06]:   #carácter-n
[Section-07]:   #leer-un-carácter-de-la-entrada-estándar
[Section-08]:   #escribir-un-carácter-en-la-salida-estándar
[Section-09]:   #funciones-getch-y-getche
[Section-10]:   #limpiar-la-pantalla
[Section-11]:   #notas-de-los-ejercicios-resueltos
