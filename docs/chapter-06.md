# Tipos estructurados de datos

<a id="header"></a>

### Contenido

- [Introducción a las matrices][Section-01]
- [Matrices numéricas unidimensionales][Section-02]
    - Definir una matriz
    - Acceder a los elementos de una matriz
    - Trabajar con matrices unidimensionales
    - Iniciar una matriz
    - Matrices asociativas
- [Cadenas de caracteres][Section-03]
    - Leer y escribir una cadena de caracteres
        - Funciones gets y fgets
        - Función puts
    - Trabajar con cadenas de caracteres
    - Funciones de la biblioteca de C
- [Tipo y tamaño de una matriz][Section-04]
- [Matrices multidimensionales][Section-05]
    - Matrices numéricas multidimensionales
    - Matrices de cadenas de caracteres
- [Copiar matrices][Section-06]
- [Trabajar con bloques de bytes][Section-07]
- [Estructuras][Section-08]
    - Crear una estructura
    - Definir variables de un tipo de estructura
    - Acceso a los miembros de una estructura
    - Miembros que son estructuras
    - Operaciones con estructuras
    - Matrices de estructuras
- [Uniones][Section-09]
    - Estructuras variables
- [Campos de bits][Section-10]

[Inicio][Index]

## Introducción a las matrices

- Estructura homogénea, compuesta por varios elementos, del mismo tipo y almacenados consecutivamente en memoria.

```
--+----+----+----+----+----+----+----+----+----+----+----+--
  |    |    | ██ | ██ | ██ | ██ | ██ | ██ | ██ | ██ |    |
--+----+----+----+----+----+----+----+----+----+----+----+--
            ↑
 matriz m --+
```

- Representación mediante variables suscritas o de subíndices.
- Matrices de una dimensión: **listas**.
- Matrices de dos dimensiones: **tablas**.

```
v = [ a₀, a₁, a₂, ..., aᵢ, ..., aₓ, ]
```

```
    ┌                             ┐
m = | a₀₀ a₀₁ a₀₂ ... a₀ⱼ ... a₀ₓ |
    | a₁₀ a₁₁ a₁₂ ... a₁ⱼ ... a₁ₓ |
    | ... ... ... ... ... ... ... |
    | aᵢ₀ aᵢ₁ aᵢ₂ ... aᵢⱼ ... aᵢₓ |
    └                             ┘
```

```
matriz m --+
           ↓
 ---+------+------+------+------+------+------+------+------+------+------+------+------+---
    |      | m[0] | m[1] | m[2] | m[3] | m[4] | m[5] | m[6] | m[7] | m[8] | m[9] |      |
 ---+------+------+------+------+------+------+------+------+------+------+------+------+---
```

- **Subíndices**:
    - Enteros consecutivos.
    - Inician en cero.
    - Pueden ser cualquier expresión entera positiva.
- El número máximo de dimensiones o de elementos, dentro de los límites del compilador, depende de la memoria disponible.
- **Clasificación**:
    - Según su dimensión:
        - Unidimensionales.
        - Multidimensionales.
    - Según su contenido:
        - Numéricas.
        - De caracteres.
        - De estructuras.
        - De punteros.

## Matrices numéricas unidimensionales

### Definir una matriz

```c
tipo nombre[ /* tamaño */ ];
```

- *tipo*: cualquier tipo.
- *tamaño*: constante entera.
- El elemento `m[0]` se lee *"m sub-cero"*.

### Acceder a los elementos de una matriz

```c
nombre[ /* constante | variable | expresión de tipo entero */ ]
```

- El subíndice indica la posición del elemento dentro de la matriz.
- Si se intenta acceder a un elemento con subíndice menor que 0 o mayor al número de elementos de la matriz menos 1, **C** no informa de ello, el sistema operativo lo notificará (escribir el código necesario para detectar este tipo de error).

```c
#define N 100

// ...

if ( k >= 0 && k < N - 1 )
    m[ k + 1 ] = m[ k ];
else
    printf( "Índice fuera de límites\n" );
```

### Trabajar con matrices unidimensionales

- Variable donde se va almacenando una suma: **acumulador**.

```c
do
{
    /* Código... */
}
while ( nalumnos < 1 || nalumnos > N_ALUMNOS );
```

- Se repetirá mientras se ingrese valores fuera de rango.

### Iniciar una matriz

- En la definición de una matriz a nivel global solamente, sus elementos son iniciados a `0` (numérica), `'\0'` (caracteres) o `NULL` (punteros).
- A nivel local no son iniciados: almacenarán basura, valores indeterminados.
- Si es local pero se declara `static`: se inicia como una global.
- Iniciar:

```c
// Número de elementos <= n
tipo nombre[ n ] = { a, b, c, ..., m };
```

- Si el número de elementos es mayor, sólo serán iniciados los n primeros.
- Si es menor, el resto de elementos serán iniciados a `0`, `'\0'` o `NULL`.
- Si el tamaño se omite, será igual al número de elementos.
- También puede omitirse cuando:
    - Se declara como **parámetro formal en una función**.
    - Se hace referencia a una matriz **declarada en otra parte del programa**.
- **C** siempre pasa las matrices en una función **por referencia**.
- Nombre de la matriz: dirección de memoria.

### Matrices asociativas

- Hacer coincidir una expresión con los subíndices de la matriz, por ejemplo:

```c
// car: carácter leído
// De esta manera se asocian
// las letras a-z con los subíndices

c[ 26 ];

c[ car - 'a' ];
```

- Variable que va incrementando su valor: **contador** (de uno en uno).

## Cadenas de caracteres

- Matriz unidimensional de elementos tipo `unsigned char` o `char`.

```c
// Equivalentes:
char cadena = { 'a', 'b', 'c', 'd', '\0' };
char cadena = { 97, 98, 99, 100, 0 };
```

- Cada carácter tiene asociado un entero entre 0 y 255 (**código ASCII**).
- `printf` visualizará todos los caracteres hasta encontrar el carácter nulo `'\0'` (formato `%s`).
- `scanf` finaliza automáticamente las cadenas leídas con un carácter `'\0'`.
- Si no se asignara el carácter `'\0'`, `printf` podría escribir más allá de los límites de la matriz y/o basura.
- **C** tiene automatizado la asignación de `'\0'` en:

```c
char cadena[ 10 ] = "abcd"; // ó
char cadena[] = "abcd";     // Tiene 5 elementos
```

### Leer y escribir una cadena de caracteres

```c
// Lee datos delimitados por espacios en blanco
char nombre[ 41 ];
scanf( "%s", nombre );

// %[ caracteres ]  : Lee hasta que encuentre uno que no esté especificado.
// %[ ^caracteres ] : Lee hasta que encuentre uno que esté especificado.
// %[ ^\n ]         : Lee hasta que encuentre '\n'.
```

- También usar `getchar`, finalizar la matriz con `'\0'`

```c
// Equivalentes:
cadena[ i ] != 0
cadena[ i ] != '\0'
```

#### Funciones gets y fgets

```c
// ANSI, UNIX, Windows
#include <stdio.h>
char *gets( char *var );
```

- *var* contendrá todos los caracteres tecleados excepto `\n` (será reemplazado `\0`).
- Devuelve un puntero a la cadena de caracteres leída.
- Un valor nulo indica un error o una condición de fin de fichero (`eof`).
- No es posible indicar cuántos caracteres serán leídos, `fgets` si permite.

```c
// También incluye '\n'
// Al final incluye '\0'

fgets( array, 40, stdin );
```

#### Función puts

```c
// ANSI, UNIX, Windows
#include <stdio.h>
int puts( const char *var );
```

- Reemplaza el carácter `'\0'` de terminación por `'\n'`.
- Devuelve un valor positivo si se ejecuta satisfactoriamente o `EOF` en caso contrario.
- Con `gets` **limpiar el buffer**, a veces queda un `'\n'` (`fflush` no tiene efecto en UNIX/Linux sobre un flujo desde el origen).

```c
fflush( stdin ) // ó
gets( cadena )
```

### Trabajar con cadenas de caracteres

- Diferencia entre minúsculas y mayúsculas (**ASCII**):

```
'a' - 'A' = 97 - 32 = 65
```

### Funciones de la biblioteca de C

```c
strcpy()    // Copiar cadenas.
strcmp()    // Comparar dos cadenas.
strlen()    // Longitud o número de caracteres de una cadena.
atof()      // Convertir una cadena a un valor double.
atoi()      // Convertir una cadena a un valor int.
atol()      // Convertir una cadena a un valor long.
sprintf()   // Convertir un valor, desde cualquier formato admitido
            // por printf() a cadena de caracteres.
tolower()   // Convertir un carácter a minúscula.
toupper()   // Convertir un carácter a mayúscula.
```

## Tipo y tamaño de una matriz

- El tipo de `int a[ 10 ]` es `int[]`.
- Se puede declarar sinónimos:

```c
typedef double t_matriz_1d[ 100 ];
t_matriz_1d m;
```

- Número de elementos:

```c
sizeof( m ) / sizeof( m[ 0 ] ) // ó / sizeof( double )
```

## Matrices multidimensionales

### Matrices numéricas multidimensionales

```c
tipo nombre_matriz[ expr_1 ][ expr_2 ] ... ;
```

- *tipo* primitivo entero o real.
- Número de elementos: *expr_1 * expr_2 * ...*

```
              +-----+-----+-----+-----+-----+-----+
matriz m ---> | m₀₀ | m₀₁ | m₀₂ | m₁₀ | m₁₁ | m₁₂ |
              +-----+-----+-----+-----+-----+-----+
              ↑                 ↑
         m₀ --+            m₁ --+
```

- `m`, `m[0]` y `m[0][0]` son la misma dirección.
- Número de filas:

```c
sizeof( m ) / sizeof( m[ 0 ] )
```

- Pensarlas como tablas:

```
matriz m --+
           ↓ col 0   col 1   col 2
           +-------+-------+-------+
    fila 0 |  m₀₀  |  m₀₁  |  m₀₂  |
           +-------+-------+-------+
    fila 1 |  m₁₀  |  m₁₁  |  m₁₂  |
           +-------+-------+-------+
```

- Cálculo del compilador para saber cuánto avanzar: `fila x elem_por_fila + col`.

### Matrices de cadenas de caracteres

```c
char nombre_matriz[ filas ][ longitud_fila ];
unsigned char nombre_matriz[ filas ][ longitud_fila ];
```

```
  +--------+      +-----------+-----------+-----------+-----+-------------+
m | m₀     | ---> | m₀ˌ₀      | m₀ˌ₁      | m₀ˌ₂      | ... | m(0, C-1)   | fila 0
  +--------+      +-----------+-----------+-----------+-----+-------------+
  | m₁     | ---> | m₁ˌ₀      | m₁ˌ₁      | m₁ˌ₂      | ... | m(1, C-1)   | fila 1
  +--------+      +-----------+-----------+-----------+-----+-------------+
  | m₂     | ---> | m₂ˌ₀      | m₂ˌ₁      | m₂ˌ₂      | ... | m(2, C-1)   | fila 2
  +--------+      +-----------+-----------+-----------+-----+-------------+
  | ...    | ---> | ...       | ...       | ...       | ... | ...         |
  +--------+      +-----------+-----------+-----------+-----+-------------+
  | m(F-1) | ---> | m(F-1, 0) | m(F-1, 1) | m(F-1, 2) | ... | m(F-1, C-1) | fila F-1
  +--------+      +-----------+-----------+-----------+-----+-------------+
    char[]          char
```

- Lista de cadenas de caracteres: `m₀`, `m₁`, `m₂`, ... , `m(F-1)`.

```c
respuesta = tolower( getchar() );

// Equivalente a:

respuesta = getchar();
respuesta = tolower( respuesta );
```

## Copiar matrices

- Al no existir una función para ello, hay que escribirla.
- Como parámetro sólo se puede obviar la primera dimensión: `m[][40]`.

## Trabajar con bloques de bytes

- Un problema con la función de copiar matrices, es que dependen de su dimensión.
- Se puede solucionar copiando **bloques de memoria** (conjunto de bytes consecutivos).

```c
// Poner las matrices a y c a cero
// (Iniciar a cero)
memset( a, 0, sizeof( a ) );

// Copiar la matriz a en c
memcpy( c, a, sizeof( a ) );

// Comparar byte a byte si tienen el mismo contenido
memcmp( a, c, sizeof( a ) );
```

## Estructuras

- Agrupar variables, generalmente de diferentes tipos, bajo un mismo nombre.
- En otros compiladores, son conocidos también como **registros**.

### Crear una estructura

```c
struct tipo_estructura
{
    tipo miembro_1;
    tipo miembro_2;

    // ...

    tipo miembro_n;
} /* [ Lista de variables ] */;
```

- Cada elemento recibe el nombre de **miembro**, o de **campo** en registros.
- Pueden ser de cualquier tipo primitivo o derivado (incluso otra estructura).
- La declaración de cada miembro no puede ser iniciada, ni contener calificadores como `extern`, `static`, `auto` o `register`.
- En **C** sólo puede contener definiciones de variables, en **C++** también puede contener definiciones de funciones.

### Definir variables de un tipo de estructura

```c
struct tipo_estructura /* [ variable1 [, variable2] ... ] */;
```

- `tipo_estructura var1, va2;` no es posible en **ANSI C**, pero sí en **C++**.
- Con `typedef` se podría obtener lo anterior en **C**.

```c
struct ficha { /* ... */ };
typedef struct ficha tficha;

// Equivalente a:
// <ficha> se puede omitir

typedef struct ficha
{ /* ... */ } tficha;
```

```c
// No recomendable:

struct
{ /* ... */ } var1, var2;
```

### Acceso a los miembros de una estructura

- Operador **punto** (`.`): `variable_estructura.miembro`.
- El nombre de una estructura no comparte el espacio de almacenamiento del resto de los identificadores (**ANSI C**).
- Para evitar confusiones, evitar usar el mismo identificador en más de una declaración.

### Miembros que son estructuras

- Declarar previamente el tipo de estructura a incluir.
- Los miembros de una estructura son almacenados secuencialmente byte a byte en el mismo orden que son declarados.

```
--+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+--
  | ██ | ██ | ██ | ██ | ██ | ██ | ## | ## | ## | ## | ## | ██ | ██ | ## | ## | ## |
--+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+--
              ↑                        ↑                   ↑                   ↑
  miembro 1 --+            miembro 2 --+       miembro 3 --+       miembro 4 --+
```

### Operaciones con estructuras

- Una variable que sea una estructura permite:

```c
// 1. Iniciarla al definirla
struct ficha persona = { "...", "...", 25, /* ... */ };

// 2. Obtener su dirección
struct ficha *ppersona = &persona;

// 3. Acceder a sus miembros
persona.telefono

// 4. Asignar una estructura a otra
struct ficha otra_persona;
otra_persona = persona;
```

### Matrices de estructuras

```c
typedef struct
{
    // ...
} tficha;

tficha alumno[ 100 ];
```

- También conocida como **matriz de registros**.
- `alumno[ i ].nombre`

```
                         nombre --+   nota--+
                                  ↓         ↓
--+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+--
  | ██ ¦ ██ ¦ ██ | ██ ¦ ██ | ## ¦ ## ¦ ## | ## ¦ ## | ██ ¦ ██ ¦ ██ | ██ ¦ ██ |
--+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+--
       alumno [ i - 1 ]           alumno [ i ]           alumno [ i + 1 ]
```

- Recomendable definir las estructuras a nivel global (fuera de `main()`).

## Uniones

- Región de almacenamiento compartida por dos o más miembros, generalmente de diferentes tipos.

```c
union tipo_union
{
    /* declaraciones de los miembros */
};

union tipo_union /* [ variable1 [, variable2] ... ] */;

variable_union.miembro;
```

- El espacio de almacenamiento es de tamaño igual al del miembro de mayor longitud en bytes.
- Sólo almacena uno de los miembros.
- Se accede al mismo dato desde diferentes miembros.
- Pueden dar resultados inesperados si se accede desde un tipo diferente con el que fue asignado.

### Estructuras variables

- Con un conjunto de miembros variable: `union` (como miembro).

## Campos de bits

- Pueden ser miembro de una **estructura** (no de una **unión**).
- Conjunto de bits adyacentes dentro de una unidad direccionable, generalmente un `int`.

```c
tipo /* [ identificador ] */ : tamaño
```

- *tamaño*:
    - Número de bits.
    - Constante entera no negativa.
    - Menor o igual al tamaño físico de la palabra máquina: `int`.
- *tipo*:
    - **ANSI C**: entero (`int`, `unsigned int`).
    - **C++**: también `char`, `short`, `int`, `long`, con signo o sin signo, o `enum`.
- No se permiten matrices de campos de bits, punteros a campos de bits o funciones que retornen un campo de bits.
- *identificador*:
    - Es opcional.
    - Campo no identificado sirve de relleno.
- La asignación de los campos de bits depende del hardware, esto es, son asignados del más significativo al menos significativo o viceversa.

```c
struct palabra
{
    unsigned car_ascii   :  7;
    unsigned bit_paridad :  1;
    unsigned operacion   :  5;
    unsigned             : 18;
    unsigned bit_signo   :  1;
};

struct palabra cb = { 'C', 1, 0x1E, 0 };
```

```
cb             : 1ec3
cb.bit_signo   :    0
cb.operacion   :   1e
cb.bit_paridad :    1
cb.car_ascii   :   43     C
                 (%x)  (%c)
```

```
 31  30  29  28  27  26  25  24  23  22  21  20  19  18  17  16  15  14  13  12  11  10  9   8   7   6   5   4   3   2   1   0
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
║ 0 ║ 0 ¦ 0 ¦ 0 ¦ 0 ¦ 0 ¦ 0 ¦ 0 ¦ 0 ¦ 0 ¦ 0 ¦ 0 ¦ 0 ¦ 0 ¦ 0 ¦ 0 ¦ 0 ¦ 0 ¦ 0 ║ 1 ¦ 1 ¦ 1 ¦ 1 ¦ 0 ║ 1 ║ 1 ¦ 0 ¦ 0 ¦ 0 ¦ 0 ¦ 1 ¦ 1 ║
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
|       0       |       0       |       0       |       0       |       1       |       e       |       c       |       3       |
+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+
```

- Si al definir una estructura de campo de bits, el espacio que queda en la unidad direccionable no es suficiente para ubicar el siguiente campo de bits, éste se alinea con respecto a la siguiente unidad direccionable (`int` o `unsigned int`).
- Un campo de bits sin nombre y de tamaño 0, garantiza que el siguiente miembro comience en la siguiente unidad direccionable.

```c
struct bits
{
    unsigned cb1: 24;
    unsigned cb2: 16;
    unsigned cb3:  5;

    // ...
}
```

```
 31  30  29  28  27  26  25  24  23  22  21  20  19  18  17  16  15  14  13  12  11  10  9   8   7   6   5   4   3   2   1   0
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   | █ | █ | █ | █ | █ | █ | █ | █ | █ | █ | █ | █ | █ | █ | █ | █ | █ | █ | █ | █ | █ | █ | █ | █ |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |   |   | ■ | ■ | ■ | ■ | ■ | # | # | # | # | # | # | # | # | # | # | # | # | # | # | # | # |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
```

- Utilizarlo para economizar espacio es una tarea ingenua y puede conducir a una pérdida de tiempo de ejecución.
- En muchas máquinas un byte o una palabra es la cantidad de memoria más pequeña que se puede acceder sin tiempo de procesamiento adicional.
- En cambio, extraer un campo de bits puede suponer instrucciones extra y, por lo tanto, un tiempo adicional.
- Debe utilizarse sólo en problemas que lo requieran; por ejemplo, cuando necesitamos utilizar un conjunto de indicadores de un bit agrupados en un entero (**flags**).

[Inicio][Index] - [Arriba][Header]

<!-------------------------------------------------------------------------
 !  Links
-------------------------------------------------------------------------->

[Index]:        ../README.md
[Header]:       #header

[Section-01]:   #introducción-a-las-matrices
[Section-02]:   #matrices-numéricas-unidimensionales
[Section-03]:   #cadenas-de-caracteres
[Section-04]:   #tipo-y-tamaño-de-una-matriz
[Section-05]:   #matrices-multidimensionales
[Section-06]:   #copiar-matrices
[Section-07]:   #trabajar-con-bloques-de-bytes
[Section-08]:   #estructuras
[Section-09]:   #uniones
[Section-10]:   #campos-de-bits
