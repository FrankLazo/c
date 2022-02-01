# Punteros

<a id="header"></a>

### Contenido

- [Creación de punteros][Section-01]
    - Operadores
    - Importancia del tipo del objeto al que se apunta
- [Operaciones con punteros][Section-02]
    - Operación de asignación
    - Operaciones aritméticas
    - Comparación de punteros
    - Punteros genéricos
    - Puntero nulo
    - Punteros constantes
- [Punteros y matrices][Section-03]
    - Punteros a cadenas de caracteres
- [Matrices de punteros][Section-04]
    - Punteros a punteros
    - Matriz de punteros a cadenas de caracteres
    - Ordenar matrices de cadenas de caracteres
- [Asignación dinámica de memoria][Section-05]
    - Funciones para administrar dinámicamente la memoria
        - *malloc*
        - *free*
    - Reasignar un bloque de memoria
- [Matrices dinámicas][Section-06]
    - Matrices dinámicas numéricas
        - Matrices dinámicas de una dimensión
        - Matrices dinámicas de dos dimensiones
    - Matrices dinámicas de cadenas de caracteres
- [Punteros a estructuras][Section-07]
- [Punteros como parámetros en funciones][Section-08]
- [Declaraciones complejas][Section-09]
- [Notas de los ejercicios resueltos][Section-10]

[Inicio][Index]

- Variable que contiene la *dirección* de memoria de un dato o de otra variable que contiene al dato.
- Pueden ser a estructuras o funciones.
- Iniciar adecuadamente para evitar accesos a zonas de memoria no permitidas.

## Creación de punteros

```c
tipo *var_puntero;
```

- `*`: "*puntero a*".
- *tipo*: cualquier tipo primitivo o derivado.

```c
int a; /* Equivalente a */ int *pint;

// Quasi equivalentes si:
pint = &a;
// Esto es: *pint < > a
```

```c
// Equivalente a lo anterior:
int a = 0, *pint = &a;
```

- Espacio para un puntero: dirección máquina, generalmente **4 bytes**.

### Operadores

- `&`: dirección de.
- `*`: indirección.

### Importancia del tipo del objeto al que se apunta

- Habría una advertencia y un resultado inesperado.

## Operaciones con punteros

### Operación de asignación

```c
int a = 10, *p, *q;
p = &a;
q = p;
```

```
                                                 +-- &a = 12FF7C
         p --+                               a --+
             ↓                                   |
════╬════════╬════════╬════════╬════════╬════════|════════╬════════╬════
    ║        ║ 12FF7C ║------------+    ║        ↓        ║        ║
════╬════════╬════════╬════════╬═══|════╬════════╬════════╬════════╬════
    ║        ║        ║        ║   +--------+--->║   10   ║        ║
════╬════════╬════════╬════════╬════════╬═══|════╬════════╬════════╬════
    ║        ║        ║        ║ 12FF7C ║---+    ║        ║        ║
════╬════════╬════════╬════════╬════════╬════════╬════════╬════════╬════
                               ↑
                           q --+
```

### Operaciones aritméticas

- **Sumar** o **restar** unidades del tipo del puntero.

```c
int x[ 100 ];
int *p, *q, a;

p = &x[ 3 ];    // p apunta a x[3]
p = p + 3;      // p apunta a x[6]
p = p - 1;      // p apunta a x[5]

q = &x[ 2 ];
p - q = 3;      // 3 elementos del tipo int

p++;            // p apunta a x[6]
p--;            // p apunta a x[5]

a = *( p + 1 )  // se le asigna el valor de x[6]

( *p )--;       // el valor de x[6] se decrementa

a = *p--;       // se le asigna el valor de x[6]
                // y p apunta a x[5]
```

### Comparación de punteros

- En realidad se comparan dos enteros (dirección de memoria).
- Sólo tiene sentido cuando se apunta a elementos de una misma matriz.

### Punteros genéricos

- Un puntero a cualquier tipo de objeto: `void *`.
- **ANSI C** permite una conversión implícita de un puntero genérico a un puntero a cualquier tipo de objeto.
- En **C++** un puntero genérico no puede ser asignado a otro puntero de otro tipo sin una conversión explícita (conversión *cast*).
- Por compatibilidad, es aconsejable realizar la conversión explícita.

```c
void fnx( void *p, int n )
{
    int *q = (int *)p;
    // ...
}
```

### Puntero nulo

```c
#define NULL ((void *)0) // definición de NULL en C
#define NULL 0           // definición de NULL en C++
```

- Se utiliza para indicar que ha ocurrido un error.
- En general, no tiene sentido asignar enteros a punteros porque quien gestiona la memoria es el sistema operativo.

### Punteros constantes

```c
const int *p = &a;  // objeto constante y p variable
int * const p = &a; // objeto variable y p constante
```

## Punteros y matrices

- Cualquier operación que se pueda realizar mediante la indexación de una matriz se puede hacer también utilizando aritmética de punteros.

```c
int *plista = &lista[ 0 ];

// Idénticos resultados:
lista[ ind ], *( lista + ind ), plista[ ind ], *( plista + ind )
```

- El identificador de una matriz es una constante y un puntero es una variable.
- Un parámetro de una función que sea matriz se considera una variable (un puntero).
- El operador `sizeof` aplicado a una matriz devuelve el tamaño en bytes de la matriz y aplicado a un puntero que apunta a una matriz devuelve el tamaño en bytes del puntero.

### Punteros a cadenas de caracteres

```c
char *cadena;
unsigned char *cadena;
```

- La dirección de memoria donde comienza una cadena viene dada por el nombre de la matriz que la contiene.
- Y el final por el carácter `\0` con el que **C** finaliza todas las cadenas.

```c
char *nombre = "Francisco Javier";
printf( "%s", nombre );

nombre = "Carmen";  // Ahora apunta a una nueva cadena

nombre[ 9 ] = '-';  // Error en ejecución, constante de caracteres

// En este caso no habría error:
char nombre[] = "Francisco Javier";
char *pnombre = nombre;
pnombre[ 9 ] = '-'; // Se modifica el elemento de índice 9
```

## Matrices de punteros

```c
int *p[ /* Tamaño */ ];
```

- Una matriz de dos dimensiones y una matriz de punteros se pueden utilizar de forma parecida.

```c
int a[ 5 ][ 5 ]; // matriz de dos dimensiones
int *p[ 5 ];     // matriz de punteros

for ( i = 0; i < 5; i++ )
    p[ i ] = a[ i ]; // asignar a p las filas de a
```

- No se puede hacer `p = a` ya que no son del mismo tipo y no se admite conversión entre ellos.
- *p* es una matriz de cinco elementos tipo puntero, en cambio, *a* es un puntero a una matriz de cinco elementos.
- En la matriz *p* el acceso a un elemento se efectúa mediante una indirección a través de un puntero y en la matriz *a*, mediante una multiplicación y una suma.
- Las matrices apuntadas por *p* pueden ser de longitud diferente.

### Punteros a punteros

```c
tipo **varpp;
```

- *tipo*: objeto apuntado después de una doble indirección.
- *varpp*: identificador de la variable puntero a puntero.

```c
int a, *p, *pp;

a = 10;     // dato
p = &a;     // puntero que apunta al dato
pp = &p;    // puntero que apunta al puntero que apunta al dato
```

```
                        p
                        +------------+
pp                +---> |     &a     | ---+     a
+------------+    |     +------------+    |     +------------+
|     &p     | ---+                       +---> |     10     |
+------------+                                  +------------+
```

- *p* es una variable con un nivel de indirección.
- *pp* es una variable con dos niveles de indirección.

```c
int a[5][5];
int *p[5];
int **q;

// Si después de asignar a p las filas de a, hacemos:
q = p;

// Entonces, las siguientes expresiones representan el mismo valor:
q[ i ][ j ], *( q[ i ] + j ), *( *( q + i) + j )
```

### Matriz de punteros a cadenas de caracteres

```c
char *p[ 5 ]; // ó
unsigned char *p[ 5 ];

char c = 'z';

p[ 0 ] = &c;
p[ 0 ] = "hola";

// Produce error ya que 'a' es un valor int
p[ 0 ] = 'a';
```

### Ordenar matrices de cadenas de caracteres

- La matriz de punteros permite comparar realizar la ordenación comparando las cadenas y modificando el orden de los elementos de la matriz de punteros, lo que da lugar a una mayor velocidad de ejecución.

## Asignación dinámica de memoria

- **C** cuenta fundamentalmente con dos métodos para almacenar información en la memoria:
    1. Variables globales y locales:
        - Globales: espacio fijado para ser usado en toda la ejecución del programa.
        - Locales: la asignación se hace a través de la pila del sistema, espacio fijado temporalmente.
    2. Usar funciones de la biblioteca de **C**: `malloc` y `free`.
- La *asignación dinámica de memoria* consiste en asignar la cantidad de memoria necesaria durante la ejecución del programa, en vez de hacerlo en la compilación del mismo.
- Se devuelve un puntero al bloque de memoria asignado.

### Funciones para administrar dinámicamente la memoria

#### *malloc*

- Asigna un bloque de memoria de *nbytes* bytes consecutivos en memoria para almacenar uno o más objetos de un tipo cualquiera.

```c
#include <stdlib.h>
void *malloc( size_t nbytes );
// Compatibilidad: ANSI, UNIX y Windows
```

- En **ANSI C**, el valor devuelto será convertido implícitamente.
- Pero en **C++** hay que realizar la conversión explícitamente.
- Si hay insuficiente espacio de memoria, retorna un puntero nulo (`NULL` o `0`).
- Si el argumento *nbytes* es 0, asigna un bloque de tamaño 0 devolviendo un puntero válido.

#### *free*

- Permite liberar un bloque de memoria asignado por las funciones `malloc`, `calloc` o `realloc`, pero no pone el puntero a `NULL`.
- Si el puntero que referencia al bloque de memoria es nulo, `free` no hace nada.

```c
#include <stdlib.h>
void free( void *vpuntero );
// Compatibilidad: ANSI, UNIX y Windows
```

- Sólo liberar memoria asignada previamente por `malloc`, `calloc` o `realloc`.
- Es buen estilo de programación liberar la memoria asignada cuando ya no se necesite.
- En Windows la memoria no liberada crea lagunas o fugas de memoria, estos bloques no estarán disponibles hasta que se reinicie la máquina.

### Reasignar un bloque de memoria

- `realloc`: cambia el tamaño de un bloque de memoria previamente asignado.

```c
#include <stdlib.h>
void *realloc( void *pBlomem, size_t nBytes );
// Compatibilidad: ANSI, UNIX y Windows
```

- *pBlomem*: puntero que apunta al comienzo del bloque de memoria actual.
- Si *pBlomem* es `NULL`, esta función se comporta igual que `malloc`.
- El bloque puede haber sido liberado por `free`.
- *nBytes*: nuevo tamaño del bloque en bytes.
- El contenido del bloque no cambia en el espacio conservado.
- Retorna `NULL` si *nBytes* es 0 y *pBlomem* no es `NULL` o si no hay suficiente memoria.
- En el primer caso, el bloque original es liberado, en el segundo, no cambia.

## Matrices dinámicas

- Matrices **estáticas**: conocer su dimensión al momento de escribir el código.
- Matrices **dinámicas**: permite decidir su dimensión durante la ejecución del programa.

```c
#include <stdlib.h>
void *calloc( size_t nelementos, size_t tamelem );
// Compatibilidad: ANSI, UNIX y Windows
```

- *nelementos*: número de elementos de la matriz.
- *tamelem*: tamaño en bytes de cada elemento.
- Devuelve `NULL` si no hay un bloque de memoria del tamaño solicitado.

### Matrices dinámicas numéricas

#### Matrices dinámicas de una dimensión

- `memset`: iniciar los elementos de la matriz (`memory.h`).

#### Matrices dinámicas de dos dimensiones

- Proceso de dos partes:
    - Asignar memoria para una matriz de punteros.
    - Asignar memoria para cada una de las filas.

```
m --+
    ↓
    +----+     +----+----+----+----+----+----+----+----+----+----+----+----+--
    |    | --> |    |    |    |    |    |    |    |    |    |    |    |    |   fila 0
    +----+     +----+----+----+----+----+----+----+----+----+----+----+----+--
    |    | --> |    |    |    |    |    |    |    |    |    |    |    |    |   fila 1
    +----+     +----+----+----+----+----+----+----+----+----+----+----+----+--
    |    | --> |    |    |    |    |    |    |    |    |    |    |    |    |   fila 2
    +----+     +----+----+----+----+----+----+----+----+----+----+----+----+--
    |    | --> |    |    |    |    |    |    |    |    |    |    |    |    |   fila 3
    +----+     +----+----+----+----+----+----+----+----+----+----+----+----+--
    |    | --> |    |    |    |    |    |    |    |    |    |    |    |    |    ...
```

- Las filas pueden ser de cualquier longitud.
- Liberar primero la memoria de las filas y luego de la matriz de punteros.

### Matrices dinámicas de cadenas de caracteres

- Matriz de dos dimensiones cuyos elementos son de tipo `char`.

## Punteros a estructuras

- Para referirse a un miembro de una estructura apuntada por un puntero hay que utilizar el operador `->`.
- El simple hecho de declarar un puntero a una estrutura no significa que dispongamos de la estructura.
- Cuando declaramos un puntero a un objeto, casi siempre es porque el objeto va a ser creado durante la ejecución.
- Los punteros a **uniones** se manipulan exactamente igual que los punteros a estructuras.

## Punteros como parámetros en funciones

```c
main()
{
    struct fecha *hoy;
    // ...
    escribir( hoy );
    // ...
}

void escribir( struct fecha *f )
{
    // ...
}
```

- El argumento *hoy* se ha pasado **por valor**.
- La estructura a la que apunta se ha pasado **por referencia**.
- Si se hubiera pasado *hoy* por referencia, entonces *f* tendría que haber sido declarado como puntero a un puntero.

```c
struct fecha **p;
```

- ``p`` es un puntero a un puntero a una estructura **struct** *fecha*.
- ``*p`` es un puntero a una estructura **struct** *fecha*.
- ``**p`` se refiere a una estructura **struct** *fecha*.

## Declaraciones complejas

- Identificador calificado por más de un operador ( matriz: `[]`, puntero: `*`, o función: `()` ).
- Para interpretar estas declaraciones:
    1. Comenzar con el identificador y ver si a la derecha hay *corchetes* o *paréntesis*.
    1. Interpretarlos y ver si a la izquierda hay *asteriscos*.
    1. Dentro de cada nivel de paréntesis, de más internos a más externos, aplicar las reglas 1 y 2.

```c
// 1. El identificador *var* es declarado como
// 2. un puntero a
// 3. una función que devuelve
// 4. un puntero a
// 5. una matriz de 10 elementos, los cuales son
// 6. punteros a
// 7. objetos de tipo `char`.

char *( *( *var )() )[ 10 ]
// ↑ ↑  ↑  ↑ ↑   ↑   ↑
// 7 6  4  2 1   3   5
```

## Notas de los ejercicios resueltos

- Algoritmo de congruencia lineal para un generador de números aleatorios:

> r<sub>k</sub> = ( multiplicador * r<sub>k-1</sub> + incremento ) % módulo

- La función **rand** está basada en este algoritmo.

[Inicio][Index] - [Arriba][Header]

<!-------------------------------------------------------------------------
 !  Links
-------------------------------------------------------------------------->

[Index]:        ../README.md
[Header]:       #header

[Section-01]:   #creación-de-punteros
[Section-02]:   #operaciones-con-punteros
[Section-03]:   #punteros-y-matrices
[Section-04]:   #matrices-de-punteros
[Section-05]:   #asignación-dinámica-de-memoria
[Section-06]:   #matrices-dinámicas
[Section-07]:   #punteros-a-estructuras
[Section-08]:   #punteros-como-parámetros-en-funciones
[Section-09]:   #declaraciones-complejas
[Section-10]:   #notas-de-los-ejercicios-resueltos
