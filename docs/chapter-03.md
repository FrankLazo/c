# Estructura de un programa

<a id="header"></a>

### Contenido

- [Estructura de un programa C][Section-01]
    - Directrices para el preprocesador
    - Definiciones y declaraciones
    - Sentencia simple
    - Sentencia compuesta o bloque
    - Funciones
        - Declaración de una función
        - Definición de una función
        - Llamada a una función
    - Función main
- [Pasando argumentos a las funciones][Section-02]
- [Programa C formado por múltiples ficheros][Section-03]
- [Ámbito de una variable][Section-04]
    - Variables globales y locales
- [Clases de almacenamiento de una variable][Section-05]
    - Calificación de variables globales
    - Calificación de variables locales
    - Calificación de funciones

[Inicio][Index]

## Estructura de un programa C

- Un programa fuente **C** está formado por una o más funciones.
- Muchas de las funciones usadas pertenecen a la biblioteca de **C** (como `printf`).
- El punto de entrada para ejecutar un programa **C/C++** siempre es la función `main`.

```c
main()
{
    /* Código */
}
```

- El diseño **top down** de programas: descomposición del problema en subproblemas cada vez más simples.
- Más la utilización únicamente de estructuras secuenciales, alternativas y repetitivas, nos conduce a la **programación estructurada**.
- Un programa **C/C++** es un conjunto de funciones que se llaman entre sí.
- Cada subproblema será resuelto por una función **C**.
- Las funciones deben ser autónomas, depender única y exclusivamente de sus propios parámetros.
- El orden establecido no es esencial, aunque sí bastante habitual:

```c
// Directrices para el preprocesador
// Definiciones y/o declaraciones
// Función main
// Otras funciones
```

- Cada función consta de:
    - **Definiciones** y/o **declaraciones**
    - **Sentencias** a ejecutar
- Una función en **C**: las definiciones y declaraciones hay que realizarlas antes de escribir la primera sentencia. En **C++** en cualquier lugar.

### Directrices para el preprocesador

- Facilitar el desarrollo, la compilación y el mantenimiento de un programa.
- Inicia con el carácter `#`.
- Procesadas por el **preprocesador** de **C**, invocadas por el compilador antes de la traducción del programa fuente.
- **Directriz de inclusión**:

```c
#include <stdio.h>      // Directorio predefinido include
#include "misfuncs.h"   // Directorio actual y luego en el predefinido
```

- **Directriz de sustitución**:

```c
#define IDENTIFICADOR VALOR
```

### Definiciones y declaraciones

- Una **declaración** introduce uno o más nombres en un programa.
- Toda declaración es una **definición**, a menos que no haya asignación de memoria como cuando se declara una función, se define un nuevo tipo, se declara un sinónimo de un tipo o cuando con una variable definida en alguna parte se utiliza el calificador `extern` para hacerla accesible.
- Toda variable debe ser definida antes de ser utilizada.
- La definición de una variable declara la variable y además le asigna memoria.
- Una variable puede ser iniciada en la propia definición.

```c
int x = 0;

/* La definición de una función la declara y además incluye el cuerpo de la
 * misma. Siempre a nivel externo.
 */

int accion( /* Parámetros */ )
{
    /* Código */
}
```

- La declaración o definición de una variable, o la declaración de una función, puede ser a nivel interno o externo.

### Sentencia simple

- Es la unidad ejecutable más pequeña de un programa **C**.
- Las sentencias controlan el flujo u orden de ejecución.
- Puede formarse a partir de:
    - Palabra clave (`for`, `while`, ...)
    - Expresiones
    - Declaraciones
    - Llamadas a funciones
- Toda sentencia simple termina con un punto y coma `;`.
- Dos o más pueden aparecer sobre una misma línea, separadas por `;` (desaconsejable).
- Una **sentencia nula** consta solamente de un `;`.

### Sentencia compuesta o bloque

- Colección de sentencias simples incluidas entre llaves `{ }`.
- Un bloque puede contener a otros bloques.

### Funciones

- Bloque de sentencias que ejecuta una tarea específica y al que nos referimos mediante un nombre (cuerpo + nombre).
- Especificar **parámetros** y **tipo de resultado**.
- Un **argumento** es el valor almacenado en el parámetro cuando se llama a la función.
- Funciones **definidas por el usuario** y funciones **de biblioteca**.

#### Declaración de una función

- Prototipo de la función.

```c
tipo_resultado nombre_funcion(/* [ Lista de parámetros ] */);
```

- Es una plantilla, para asegurar que un llamado antes de la definición es correcto.
- **Declaración implícita**:
    - Cuando la función es llamada y no existe una declaración previa.
    - **C**, por omisión, supone una función tipo `int` y no chequea la lista de parámetros (`main()`).
    - No se contempla en **C++**.
- **Declaración explícita**:
    - Recomendada.
    - Número y tipo de parámetros, y tipo de valor retornado.
    - En el prototipo se pueden omitir los identificadores (sólo para aportar sintaxis más clara).

```c
float funcion_x( int, float, char );
```

- Lista de parámetros vacía:
    - **ANSI C**: número indeterminado de ellos.
    - En **C++**: que no hay parámetros.
    - Para asegurar portabilidad usar: `void` (no parámetros).
- También para una función que no devuelve nada.

```c
void funcion_x( void );
```

#### Definición de una función

- Consta de cabecera y cuerpo.

```c
tipo_resultado nombre_funcion( /* [ Parámetros formales ] */ )
{
    // Declaraciones de variables locales;
    // Sentencias;
    // Devolver un resultado al punto de la llamada:
    // [ return [(] expresión [)] ];
}
```

- El tipo de resultado no puede ser una matriz o una función.
- Si no se especifica se supone `int`.
- La sentencia `return` puede ser o no la última y aparecer más de una vez.
- No se puede especificar más de un elemento de datos a continuación de `return`.
- Los **parámetros formales** son variables locales a esa función, tienen vida sólo durante la ejecución de la función.

#### Llamada a una función

- Se realiza desde otra función o incluso desde ella misma.
- Formada por su nombre seguido de una lista de argumentos (**parámetros actuales**).

### Función main

- Todo programa **C** tiene una y sólo una función `main`.
- Es el punto de entrada al programa y de salida.

```c
int main( int argc, char *argv[] )
{
    // Cuerpo de la función
}
```

- **C++** permite que `main` no retorne un valor.
- En cambio, **ANSI C**, avisará que `main` no retorna un `int`.

## Pasando argumentos a las funciones

- **Por valor**:
    - Se pasa una copia del valor del argumento.
    - Por defecto, todos los argumentos, excepto las matrices, son pasados por valor (`printf`).
- **Por referencia**:
    - Pasar la dirección de cada argumento, los parámetros formales deben ser punteros.
    - Usar el operador `&` (`scanf`).

## Programa C formado por múltiples ficheros

- Un fichero fuente puede contener cualquier combinación de directrices para el compilador, declaraciones y definiciones.
- Pero una función o estructura no puede ser dividida entre dos ficheros fuente.
- Un fichero fuente no necesita contener sentencias ejecutables.
- Para compilar y enlazar los ficheros:

```bash
# Compilador C de Microsoft
cl modulo01.c modulo02.c /Femayor

# Compilador C de UNIX/Linux
cc modulo01.c modulo02.c -o mayor.exe
```

```
      +--> modulo01.c ---+      +------> modulo01.obj -------+
      |                  ↓      |                            ↓
+--------+            +------------+                      +-----------+
| Editor |            | Compilador | --> modulo02.obj --> | Enlazador | --> mayor.exe
+--------+            +------------+                      +-----------+
      |                  ↑                                   ↑
      +--> modulo02.c ---+             +--------------+      |
                                       | Biblioteca C |------+
                                       +--------------+
```

## Ámbito de una variable

- Parte de un programa donde una variable puede ser referenciada por su nombre.
- Puede estar limitada a un bloque, fichero, función o a una declaración de una función.

### Variables globales y locales

- **Variable global**:
    - Declarada fuera de todo bloque.
    - Accesible hasta el final del fichero fuente.
    - Existe y tiene valor hasta el final de la ejecución del programa.
- **Variable local** o automática:
    - Declaración dentro de un bloque.
    - Acceso limitado a ese bloque.
    - Existe y tiene valor hasta el final del bloque.

```
Nivel externo:                   Fuera de todo bloque.
Nivel bloque de la función main: Accesibles desde main y bloques 1 y 2.
Nivel bloque 1:                  Sentencia compuesta. Bloque 1 y 2.
Nivel bloque 2:                  Sentencia compuesta. Bloque 2.
```

```
            +-
            |             // Código
            |           +-
            |           | main()
            |           | {
            |           |     // Más código
            |           |                                                 -+
            |           |     {                                            |
externo --> |  main --> |         // Y más código                          |
            |           |                                  -+              |
            |           |         {                         |              | <-- bloque1
            |           |             // Y más y más código | <-- bloque2  |
            |           |         }                         |              |
            |           |     }                            -+              |
            |           | }                                               -+
            |           +-
            +-
```

- Una variable global y local pueden tener el mismo nombre.
- La variable global queda anulada en el ámbito de la local.
- Los parámetros declarados en la declaración de una función tienen un ámbito restringido a la declaración.
- Los parámetros formales en la definición de una función son locales a la función.

## Clases de almacenamiento de una variable

- Determinan la accesibilidad y existencia de las variables.
- `auto`:
    - Almacenamiento automático.
    - Sólo con variables locales.
- `register`:
    - Almacenamiento en un registro.
    - Sólo con variables locales.
- `static`:
    - Almacenamiento estático.
    - Con variables locales y globales.
- `extern`:
    - Almacenamiento externo.
    - Sólo con variables globales.

### Calificación de variables globales

- Una variable global es una definición de la variable o una referencia a una variable definida en otra parte.
- Se puede hacer visible antes de su definición (si tiene sentido) o en otro fichero fuente con el calificador `extern`.
- Si se usa `static` en la declaración, la variable sólo es accesible dentro de su propio fichero fuente.

### Calificación de variables locales

- Calificada `auto` (automática o local):
    - Solamente es visible dentro del bloque.
    - En caso se omita es `auto`.
    - Recomendable iniciarlas siempre.
- Calificada `static`:
    - Solamente es visible dentro del bloque, pero su existencia es permanente.
    - Sólo se inicia una vez.
    - Si no se inicia, por defecto es 0.
- Calificada `register`:
    - Recomendación al compilador para que la almacene en un **registro de la máquina**, produciendo programas más cortos y más rápidos.
    - El número de registros utilizables depende de la máquina.
    - Si no es posible se le da tratamiento `auto`.
    - Válido para variables `int` y de tipo **puntero**.
- Declarada `extern` a nivel local hace referencia a una definición a nivel global.

### Calificación de funciones

- Todas las funciones tienen carácter global, no pueden definirse en un bloque.
- `static` accesible sólo dentro de ese fichero.
- `extern` accesible desde todos los ficheros.
- Por omisión, una función es `extern`.
- Calificar se puede hacer en el prototipo o definición de la función.

[Inicio][Index] - [Arriba][Header]

<!-------------------------------------------------------------------------
 !  Links
-------------------------------------------------------------------------->

[Index]:        ../README.md
[Header]:       #header

[Section-01]:   #estructura-de-un-programa-c
[Section-02]:   #pasando-argumentos-a-las-funciones
[Section-03]:   #programa-c-formado-por-múltiples-ficheros
[Section-04]:   #ámbito-de-una-variable
[Section-05]:   #clases-de-almacenamiento-de-una-variable
