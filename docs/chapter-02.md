# Elementos del lenguaje C

<a id="header"></a>

### Contenido

- [Presentación de la sintaxis de C][Section-01]
- [Caracteres de C][Section-02]
    - Letras, dígitos y carácter de subrayado
    - Espacios en blanco
    - Caracteres especiales y signos de puntuación
    - Secuencias de escape
- [Tipos de datos][Section-03]
    - Tipos primitivos
        - char
        - short
        - int
        - long
        - enum
        - float
        - double
    - Tipos derivados
- [Sinónimos de un tipo][Section-04]
- [Literales][Section-05]
    - Literales enteros
    - Literales reales
    - Literales de un solo carácter
    - Literales de cadenas de caracteres
- [Identificadores][Section-06]
- [Palabras clave][Section-07]
- [Comentarios][Section-08]
- [Declaración de constantes simbólicas][Section-09]
    - Constantes C++
    - ¿Por qué utilizar constantes?
- [Declaración de una variable][Section-10]
    - Iniciación de una variable
- [Expresiones numéricas][Section-11]
- [Operadores][Section-12]
    - Operadores aritméticos
    - Operadores de relación
    - Operadores lógicos
    - Operadores unitarios
    - Operadores a nivel de bits
    - Operadores de asignación
    - Operador condicional
    - Otros operadores
- [Prioridad y orden de evaluación][Section-13]
- [Conversión entre tipos de datos][Section-14]

[Inicio][Index]

## Presentación de la sintaxis de C

- Palabras clave en negrita.
- Texto en cursiva, colocar información indicada por el texto.
- Información opcional entre corchetes.
- Más elementos de la misma forma con puntos suspensivos.
- Opciones entre llaves separadas por barra vertical.

> **typedef** *declaracion_tipo sinonimo*[, *sinonimo*] ... ;<br />
> *constante_entera*[ { L | U | UL } ]

## Caracteres de C

### Letras, dígitos y carácter de subrayado

- Para formar las **constantes**, **identificadores** y **palabras clave** de C.
- Letras mayúsculas del alfabeto inglés:

```
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
```

- Letras minúsculas del alfabeto inglés:

```
a b c d e f g h i j k l m n o p q r s t u v w x y z
```

- Dígitos decimales:

```
0 1 2 3 4 5 6 7 8 9
```

- Carácter de subrayado:

```
_
```

- Mayúsculas y minúsculas diferentes para el compilador de C.

### Espacios en blanco

```
Espacio en blanco
Tabulador horizontal
Tabulador vertical
Avance de página
Nueva línea
```

- Para escribir programas más legibles.
- Ignorados por el compilador (el exceso).
- `Ctrl + Z` en Windows, `Ctrl + D` en UNIX: **fin de fichero** (End Of File).

### Caracteres especiales y signos de puntuación

```
, . ; : ? ' " ( ) [ ] { } < ! | / \ ~ + # % & ^ * - = >
```

### Secuencias de escape

- Cualquiera de los anteriores puede ser representado por una **secuencia de escape**.

Secuencia|Nombre
:---|:---
`\n`|Ir al principio de la siguiente línea.
`\t`|Tabulador horizontal.
`\v`|Tabulador vertical (sólo para impresora).
`\b`|Retroceso (backspace).
`\r`|Retorno de carro sin avance de línea.
`\f`|Alimentación de página (sólo para impresora).
`\a`|Alerta, pitido.
`\'`|Comilla simple.
`\"`|Comilla doble.
`\\`|Barra invertida (backslash).
`\ddd`|Carácter ASCII. Representación octal (*d* es un dígito de 0 a 7).
`\xdd`|Carácter ASCII. Representación hexadecimal (0 a 9 - A a F).

## Tipos de datos

### Tipos primitivos

- Definidos por el compilador.
- Tipos enteros:

```c
char     short     int     long     enum
```

- Tipos reales:

```c
float    double
```

- Ficheros de cabecera `limits.h`, `float.h` especifican los valores máximo y mínimo de cada tipo.
- Cada entero puede ser calificado por:
    - `signed` (con signo)
    - `unsigned` (sin signo)
- Por defecto son `int`:

```c
// Son equivalentes:
signed x;
signed int x;
```

- Por defecto los enteros son `signed`:

```c
// Son equivalentes:
char y;
signed char y;
```

#### 1. char

- [ -128; +127 ]
- Conjunto de **8 bits**, el primero para el signo, el resto para el valor.
- `unsigned char`: [ 0; +255 ]
- Los valores 0 a 127 se corresponden con los 128 primeros caracteres de los códigos internacionales **ASCII**, **ANSI** o **UNICODE**.

```c
char car =  'a';
char car =   97;
char car = 0x61; // Hexadecimal
char car = 0141; // Octal
```

#### 2. short

- [ -32 768; +32 767 ]
- Abreviatura de `signed short int`.
- Dato de **16 bits** de longitud, independientemente de la plataforma utilizada.
- `unsigned short`: [ 0; +65 535 ]

#### 3. int

- [ -2 147 483 648; +2 147 483 647 ]
- Abreviatura de `signed int`.
- Dato de **32 bits** de longitud.
- `unsigned int`: [ 0; +4 294 967 295 ]
- Uso de enteros de cualquier tipo produce un código compacto y rápido.
- La longitud de un `short` es siempre menor o igual que la de un `int`.

#### 4. long

- [ -2 147 483 648; +2 147 483 647 ]
- Dato de **32 bits** de longitud (en otros compiladores es de **64 bits**).
- `unsigned long`: [ 0; +4 294 967 295 ]
- La longitud de un `int` es menor o igual que la de un `long`.

#### 5. enum

- Una lista de valores que pueden ser tomados por una variable de este tipo.

```c
enum tipo_enumerado
{
    /* Identificadores de las constantes enteras */
};

enum tipo_enumerado /* [ variable1 [, variable2] ... ] */;
```

- Cada identificador tiene asociado un valor desde 0, 1, 2, ...
- Para **ANSI C** un tipo enumerado es un `int`, para **C++** es un tipo diferente.
- Se le puede asignar un valor inicial a cualquier identificador.
- Dos o más miembros pueden tener el mismo valor.
- Un identificador no puede aparecer en más de un tipo.
- No es posible leer o escribir directamente un identificador de un tipo enumerado.
- Permite acercar más a nuestra forma de expresarnos.

#### 6. float

- Dato en coma flotante de **32 bits**.
- En formato **IEEE 754**: 1 bit para el signo, 8 bits para el exponente y 23 bits para la mantisa.
- Precisión aproximada de **7 dígitos**.
- Añadir al final `f` o `F`.

#### 7. double

- Dato en coma flotante de **64 bits**.
- En formato **IEEE 754**: 1 bit para el signo, 11 bits para el exponente y 52 bits para la mantisa.
- Precisión aproximada de **16 dígitos**.
- Por omisión, una constante (un literal) es considerada de tipo `double`.
- Algunos compiladores proporcionan el tipo `long double`. Puede tener hasta **19 dígitos** significativos.

### Tipos derivados

- Construídos a partir de tipos primitivos.
- **Estructuras**, **uniones**, **matrices** (arrays), **punteros** y **funciones**.

## Sinónimos de un tipo

- Declarar nuevos nombres de tipo de datos (primitivos o derivados):

```c
typedef declaracion_tipo /* sinonimo1 [, sinonimo2] ... */;

typedef unsigned long ulong;
ulong dni;
```

- Permiten parametrizar un programa para evitar problemas de portabilidad.

## Literales

- Valores constantes.

### Literales enteros

- En base 10, 8, 16.
- El signo `+` opcional en valores positivos.
- Los sufijos pueden ir en mayúscula o minúscula.
- Si es decimal y no tiene sufijo será: `int`, `long int` o `unsigned long int`, en el primero que pueda ser representado.
- Si es octal o hexadecimal sin sufijo será: `int`, `unsigned int`, `long int` o `unsigned long int`, en el primero que pueda ser representado.

```c
// Si el sufijo L:  long, sino unsigned long
// Si el sufijo U:  unsigned int, sino unsigned long
// Si el sufijo UL: unsigned long

/* { [+] | - } */ literal_entero /* [ { L | U | UL } ] */
```

- Entero decimal: primer carácter diferente de cero.
- Entero octal: primer carácter igual a cero.
- Entero hexadecimal: precedidos por 0x ó 0X.

```c
256     // Dígitos de 0 a 9
0400    // Dígitos de 0 a 7
0x100   // Dígitos de 0 a 9 + letras de A a F
```

### Literales reales

```c
/* { [+] | - } */ parte_entera . parte_fraccionaria /* [ { e | E } { [+] | - } exponente ] */
```

### Literales de un solo carácter

- Son de tipo `char`.
- Un único carácter entre **comillas simples** `' '`.
- También secuencias de escape.
- Su valor es el que le corresponde en el juego de caracteres de la máquina.

### Literales de cadenas de caracteres

- Secuencia de caracteres encerrados entre **comillas dobles** `" "`.
- Incluye las secuencias de escape.
- Cuando la secuencia es demasiado larga se puede usar `\` como carácter de continuación.
- Dos o más cadenas separadas por un espacio en blanco serían concatenadas en una sola.

```c
printf( "Esta cadena de caracteres es dema\
         siado larga.\n" );

printf( "Primera cadena, "
        "segunda cadena.\n" );
```

- Cada carácter es almacenado en localizaciones sucesivas de memoria.
- Cada carácter ocupa un byte y la cadena finaliza con el carácter nulo `\0`.

```
    -+----+----+----+----+----+----+----+----+-
     |    | h  | o  | l  | a  | \0 |    |    |
    -+----+----+----+----+----+----+----+----+-
```

## Identificadores

- Nombres dados a **tipos**, **literales**, **variables**, **funciones** y **etiquetas** de un programa.

```c
/* { letra | _ }[ { letra | dígito | _ } ] ... */
```

- Mayúsculas y minúsculas son diferentes.
- Dependiendo del compilador sólo los *n* primeros caracteres son significativos:
    - **ANSI C**: 6 en un identificador externo y 31 en uno interno (dentro de una función).
    - **Microsoft C**: 247 en identificadores externos o internos.

## Palabras clave

- Identificadores predefinidos que tienen un significado especial para el compilador **C**.

```
auto            double          int             struct
break           else            long            switch
case            enum            register        typedef
char            extern          return          union
const           float           short           unsigned
continue        for             signed          void
default         goto            sizeof          volatile
do              if              static          while
```

## Comentarios

- Explicar el código fuente.

```c
/* Comentario tradicional.
 * Puede ocupar más de una línea.
 * No pueden anidarse.
 */

// Comentario de una sola línea.
// Comentarios estilo C++.
```

## Declaración de constantes simbólicas

- Decirle al compilador **C** el nombre de la constante y su valor.
- Generalmente antes de la función `main`, usando la directriz `#define`.
- Una directriz no es una sentencia **C**, sino una orden para el preprocesador.
- El tipo de una constante es el tipo del valor asignado.
- Habitual escribir el nombre en mayúsculas.

```c
#define NOMBRE VALOR
```

### Constantes C++

- Otra forma de declarar una constante: `const`.
- Una vez declarada e iniciada, ya no se puede modificar su valor.
- Si se omite el tipo, se supone `int`.

```c
const double PI = 3.14;
```

### ¿Por qué utilizar constantes?

- Hace más fácil modificar un programa.

## Declaración de una variable

- Una variable representa un espacio de memoria para almacenar un valor de un determinado tipo.

```c
tipo identificador1 /* [, identificador2] ... */;
```

- El tipo determina los valores y operaciones que pueden realizarse.
- Se puede declarar fuera de todo **bloque** (`{ ... }`) y dentro de un bloque de sentencias.
- En **ANSI C**, cuando es dentro de un bloque, la declaración debe hacerse al principio del mismo.
- En **C++**, puede ser en cualquier lugar, pero antes de ser usada.
- Una variable declarada fuera de todo bloque se dice que es **global**.
- Una variable declarada dentro de un bloque se dice que es **local**.

### Iniciación de una variable

- Las variables globales son iniciadas por omisión por el compilador **C**:
    - Numéricas con `0`
    - Caracteres con `'\0'`
- Las variables locales no son iniciadas.
- Recomendable siempre iniciarlas.

## Expresiones numéricas

- Conjunto de operandos unidos mediante operadores para especificar una operación determinada.
- Cuando se evalúan retornan un valor.
- Cuando se evalúa una expresión de diferentes tipos, **C** convierte los valores al tipo del operando de mayor precisión.
- En una asignación `x = ...` **C** convierte el valor de la derecha al de la izquierda.
- **C** sugiere conversión explícita.

## Operadores

- Símbolos que indican como son manipulados los datos.

### Operadores aritméticos

- Para realizar operaciones matemáticas.

Operador|Operación
:---:|:---
`+`|**Suma**. Operandos enteros o reales.
`-`|**Resta**. Operandos enteros o reales.
`*`|**Multiplicación**. Operandos enteros o reales.
`/`|**División**. Operandos enteros o reales. Si ambos enteros, resultado entero, sino real.
`%`|**Resto** o **Módulo**. Operandos enteros.

- Reales convertidos a enteros truncando la parte fraccionaria.
- Los reales son redondeados (5 o mayor).

### Operadores de relación

- Permiten evaluar la igualdad y la magnitud.
- Resultado **valor booleano**: 1 ó 0 (verdadero o falso).

Operador|Operación
:---:|:---
`<`|¿Primer operando **menor que** el segundo?
`>`|¿Primer operando **mayor que** el segundo?
`<=`|¿Primer operando **menor o igual que** el segundo?
`>=`|¿Primer operando **mayor o igual que** el segundo?
`!=`|¿Primer operando **distinto que** el segundo?
`==`|¿Primer operando **igual que** el segundo?

- Los operandos tienen que ser de un tipo primitivo.

### Operadores lógicos

- Resultado **valor booleano**: 1 ó 0 (verdadero o falso).
- Las expresiones que dan resultados booleanos pueden combinarse para formar **expresiones booleanas**.
- En **C**, expresión numérica distinta de 0 es verdadera, igual a 0 es falsa.

Operador|Operación
:---:|:---
`&&`|**AND**. Si el primer operando es falso, el segundo no es evaluado.
`\|\|`|**OR**. Si el primer operando es verdadero, el segundo no es evaluado.
`!`|**NOT**.

- `|`: ASCII 124.
- El resultado de una operación lógica es de tipo `int`.

### Operadores unitarios

- Se aplican a un solo operando: `!` `-` `~` `++` `--`.

Operador|Operación
:---:|:---
`~`|**Complemento a 1**. Cambiar ceros por unos y unos por ceros. ASCII 126: `~`. Operando de tipo primitivo entero.
`-`|**Cambia de signo**. Operando de tipo primitivo entero o real.

### Operadores a nivel de bits

- Operaciones **AND**, **OR**, **XOR** y **desplazamientos**, bit por bit.
- Operandos deben ser enteros.

Operador|Operación
:---:|:---
`&`|**AND**. A nivel de bits.
`\|`|**OR**. A nivel de bits.
`^`|**XOR**. A nivel de bits.
`<<`|**Desplazamiento a la izquierda**. Rellenando con ceros por la derecha.
`>>`|**Desplazamiento a la derecha**. Rellenando con el bit de signo negativo por la izquierda.

### Operadores de asignación

Operador|Operación
:---:|:---
`++`|**Incremento**.
`--`|**Decremento**.
`=`|**Asignación simple**.
`*=`|**Multiplicación más asignación**.
`/=`|**División más asignación**.
`%=`|**Módulo más asignación**.
`+=`|**Suma más asignación**.
`-=`|**Resta más asignación**.
`<<=`|**Desplazamiento a la izquierda más asignación**.
`>>=`|**Desplazamiento a la derecha más asignación**.
`&=`|**AND más asignación**.
`\|=`|**OR más asignación**.
`^=`|**XOR más asignación**.

- Los operandos tienen que ser de un tipo primitivo.
- `x++` se realiza después de la asignación y `++x` antes de.
- No se recomienda incluirlos en expresiones complejas.

### Operador condicional

- Operando 1 debe ser una expresión booleana.
- Si operando 1 es verdadero, el resultado de la expresión condicional es operando 2.
- Si operando 1 es falso, el resultado de la expresión condicional es operando 3.

```c
operando1 ? operando2 : operando3;
```

### Otros operadores

- `sizeof()` o `sizeof x`:
    - Da el tamaño en bytes de su operando (identificador o tipo).
    - Paréntesis necesario con un tipo de dato.
    - No se puede aplicar a matrices de dimensión no especificada, a un campo de bits o a una función.
- Operador **coma**: `,`:
    - Para encadenar varias operaciones.
    - En declaraciones/asignaciones, sentencia `for`, argumentos de una función.
- Operador **dirección-de**: `&`:
    - No se puede aplicar a un campo de bits perteneciente a una estructura o a un identificador con `register`.
- Operador de **indirección**: `*`:
    - Accede a un valor indirectamente a través de una dirección (un puntero).

## Prioridad y orden de evaluación

- De mayor a menor prioridad.
- En la misma línea, misma prioridad.
- En **C**, todos los operadores binarios excepto los de asignación son evaluados de izquierda a derecha.

Operador|Asociatividad
:---|:---
`()` `[]` `.` `->`|Izquierda a derecha.
`-` `~` `!` `++` `--` `(tipo)` `*` `&` `sizeof`|Derecha a izquierda.
`*` `/` `%`|Izquierda a derecha.
`+` `-`|Izquierda a derecha.
`<<` `>>`|Izquierda a derecha.
`<` `<=` `>` `>=`|Izquierda a derecha.
`==` `!=`|Izquierda a derecha.
`&`|Izquierda a derecha.
`^`|Izquierda a derecha.
`\|`|Izquierda a derecha.
`&&`|Izquierda a derecha.
`\|\|`|Izquierda a derecha.
`?:`|Derecha a izquierda.
`=` `*=` `/=` `%=` `+=` `-=` `<<=` `>>=` `&=` `\|=` `^=`|Derecha a izquierda.
`,`|Izquierda a derecha.

## Conversión entre tipos de datos

- Reglas en el orden indicado para cada operación binaria perteneciente a una expresión (dos operandos y un operador):
    1. Si uno es `long double`, el otro es convertido a `long double`.
    1. Si uno es `double`, el otro es convertido a `double`.
    1. Si uno es `float`, el otro es convertido a `float`.
    1. Un `char` o `short`, con o sin signo, se convertirá a `int` si puede representar todos los valores del tipo original, o a `unsigned int` en caso contrario.
    1. Si uno es `unsigned long`, el otro es convertido a `unsigned long`.
    1. Si uno es `long`, el otro es convertido a `long`.
    1. Si uno es `unsigned int`, el otro es convertido a `unsigned int`.
- Si el compilador **C** no puede convertir, lanzará error: **Conversión explícita**.
- Construcción **cast**:

```c
(tipo) expresion

// Notación funcional
// En C++
tipo( expresion )
```

- Siempre que se pueda es mejor evitarla, ya que suprime la verificación de tipo proporcionada por el compilador y puede conducir a resultados inesperados.
- En una asignación:
    - Los caracteres se convierten a enteros con o sin extensión de signo, dependiendo esto de la instalación. Generalmente con extensión de signo.
    - Los enteros se convierten a caracteres preservando los bits de menos peso.
    - Los reales son convertidos a enteros, truncando la parte fraccionaria.
    - Un `double` pasa a `float`, redondeando y perdiendo precisión.
- También ocurre conversión cuando un valor es pasado como argumento a una función.

[Inicio][Index] - [Arriba][Header]

<!-------------------------------------------------------------------------
 !  Links
-------------------------------------------------------------------------->

[Index]:        ../README.md
[Header]:       #header

[Section-01]:   #presentación-de-la-sintaxis-de-c
[Section-02]:   #caracteres-de-c
[Section-03]:   #tipos-de-datos
[Section-04]:   #sinónimos-de-un-tipo
[Section-05]:   #literales
[Section-06]:   #identificadores
[Section-07]:   #palabras-clave
[Section-08]:   #comentarios
[Section-09]:   #declaración-de-constantes-simbólicas
[Section-10]:   #declaración-de-una-variable
[Section-11]:   #expresiones-numéricas
[Section-12]:   #operadores
[Section-13]:   #prioridad-y-orden-de-evaluación
[Section-14]:   #conversión-entre-tipos-de-datos
