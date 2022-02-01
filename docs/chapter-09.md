# Trabajar con ficheros

<a id="header"></a>

### Contenido

- [Visión general de los flujos de E/S][Section-01]
- [Visión general de un fichero][Section-02]
- [Abrir un fichero][Section-03]
    - fopen
    - freopen
- [Cerrar un fichero][Section-04]
    - fclose
- [Manipulación de errores][Section-05]
    - ferror
    - clearerr
    - feof
    - perror
- [Posición del puntero de L/E][Section-06]
    - ftell
    - fseek
    - rewind
- [E/S carácter a carácter][Section-07]
    - fputc
    - fgetc
- [E/S de cadenas de caracteres][Section-08]
    - fputs
    - fgets
- [Entrada/salida con formato][Section-09]
    - fprintf
    - fscanf
- [E/S utilizando registros][Section-10]
    - fwrite
    - fread
- [Abriendo ficheros para acceso secuencial][Section-11]
    - Un ejemplo de acceso secuencial
- [Escribir datos en la impresora][Section-12]
- [Control del buffer asociado con un flujo][Section-13]
    - setvbuf
    - fflush
- [Ficheros temporales][Section-14]
    - tmpfile
- [Abriendo ficheros para acceso aleatorio][Section-15]

[Inicio][Index]

- Un **fichero** o **archivo** es una colección de información que almacenamos en un soporte, generalmente magnético, para poderla manipular en cualquier momento.
- El **registro** más simple estaría formado por un carácter.

```
╔═══════════╦═══════════╦═══════════╦═══════════════════════════════════╦══════
║ nombre    ║ dirección ║ teléfono  ║                                   ║
╚═══════════╩═══════════╩═══════════╩═══════════════════════════════════╩═══
|           |                       |                                   |
|   campo   |                       |                                   |
|<--------->|                       |                                   |
|             registro              |             registro              |
|<--------------------------------->|<--------------------------------->|
|
|                                fichero
|<-----------------------------------------------------------------------------\
```

- Operaciones a realizar:
    1. Abrir el fichero.
    2. Escribir o leer registros en el fichero.
    3. Cerrar el fichero.
- Tipos de ficheros:
    - Ficheros de la aplicación (`.c`, `.h`, etc.).
    - Ficheros de datos:
        - Acceso secuencial
        - Acceso aleatorio

## Visión general de los flujos de E/S

- **Flujo** o **stream**: estructura de datos que hace de intermediario entre el programa y el origen o destino de la información.
- Este nivel de abstracción hace que el programa no tenga que saber nada ni del dispositivo ni del tipo de información.
- Los algoritmos son siempre más o menos los mismos:

Leer|Escribir
:---|:---
Abrir un flujo **desde** un fichero.|Abrir un flujo **hacia** un fichero.
Mientras haya información:<br />**Leer** información.|Mientras haya información:<br />**Escribir** información.
Cerrar el flujo.|Cerrar el flujo.

- En **C/C++** abrir un flujo supone crear una estructura de datos de tipo `FILE`.

```c
struct _iobuf
{
    char *_ptr;      // Puntero a la posición en el buffer sobre la
                     // que se hará la siguiente operación de E/S.
    int   _cnt;      // Contador que indica los bytes que quedan por
                     // leer o por escribir en el buffer de E/S.
    char *_base;     // Puntero al buffer de E/S.
    char  _flag;     // Máscara para contener el modo de acceso al
                     // fichero y los errores que se produzcan al
                     // acceder a él.
    char  _file;     // Descriptor del fichero.
    int   _charbuf;  // (Normalmente es 0)
    int   _bufsiz;   // Tamaño del buffer.
    char *_tmpfname; // (Normalmente es NULL)
};
typedef struct _iobuf FILE;
```

- **Buffer**:
    - Bloque de memoria que actúa como intermediario para operaciones de E/S.
    - Los accesos a dispositivos son más lentos que los accesos a memoria.
- Antes de abrir un flujo, definir una estructura tipo `FILE`.
- Después de finalizar el trabajo con un flujo, éste debe cerrarse.
- Cuando un programa **C/C++** comienza su ejecución, son abiertos automáticamente tres flujos:

Flujo|Dispositivo al que está vinculado
:---|:---
`stdin`|Dispositivo de entrada estándar (teclado).
`stdout`|Dispositivo de salida estándar (pantalla).
`stderr`|Dispositivo de error estándar (pantalla).

- En aplicaciones **Windows**, pueden estar presentes además:

Flujo|Dispositivo al que está vinculado
:---|:---
`stdaux`|Dispositivo auxiliar estándar (puerto serie).
`stdprn`|Dispositivo de impresión estándar (puerto paralelo para la impresora).

## Visión general de un fichero

- **Fichero**: secuencia de bytes almacenada en binario en un dispositivo de almacenamiento.
- Código fuente en un editor de texto:

```c
/* holamundo.c */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("¡Hola mundo!\n");
    system("pause");
    return 0;
}
```

- Código fuente en un editor capaz de mostrarlo byte a byte en hexadecimal:
    1. Columna 1: la posición del primer byte de cada fila.
    1. Columna 2: los 16 bytes en hexadecimal.
    1. Columna 3: los caracteres correspondientes.

```
00000000    2f 2a 20 68 6f 6c 61 6d 75 6e 64 6f 2e 63 20 2a    /* holamundo.c *
00000010    2f 0d 0a 23 69 6e 63 6c 75 64 65 20 3c 73 74 64    /..#include <std
00000020    69 6f 2e 68 3e 0d 0a 23 69 6e 63 6c 75 64 65 20    io.h>..#include
00000030    3c 73 74 64 6c 69 62 2e 68 3e 0d 0a 0d 0a 69 6e    <stdlib.h>....in
00000040    74 20 6d 61 69 6e 28 29 0d 0a 7b 0d 0a 20 20 70    t main()..{.. p
00000050    72 69 6e 74 66 28 22 a1 48 6f 6c 61 20 6d 75 6e    rintf(".Hola mun
00000060    64 6f 21 5c 6e 22 29 3b 0d 0a 20 20 73 79 73 74    do!\n");.. syst
00000070    65 6d 28 22 70 61 75 73 65 22 29 3b 0d 0a 20 20    em("pause");..
00000080    72 65 74 75 72 6e 20 30 3b 0d 0a 7d 0d 0a          return 0;..}..
                                       ~~~~~
```

- Sólo se muestran los caracteres imprimibles de los 128 primeros caracteres **ASCII**, el resto aparece representado por un punto.
- **ASCII** coincide con los códigos **ANSI** y **UNICODE** sólo en los 128 primeros caracteres.
- **ANSI** y **UNICODE** coinciden en los caracteres 0 a 255.
- Los bytes *0d 0a* son el salto de línea, que en **Windows** se representa con dos caracteres:
    - *0d*: ASCII **CR** (**C**arriage **R**eturn: retorno de carro).
    - *0d*: ASCII **LF** (**L**ine **F**eed: avance de línea).
- *Ficheros de texto*: Si cada byte se corresponde con un carácter de la tabla de códigos utilizada (**ASCII**, **ANSI**, **UNICODE**, etc.).
- *Ficheros binarios*: si no existe esa correspondencia.
- El carácter correspondiente a un determinado código depende de la tabla de códigos utilizada por la aplicación:

Código Hexadecimal|ASCII|ANSI|UNICODE
:---:|:---:|:---:|:---:
61|a|a|a
e1|β|á|á
f1|±|ñ|ñ

- En **Linux** se usa **UTF-8** y poco a poco va tomando presencia el **UNICODE** (16 bits por carácter).
- En **Linux** y **UNIX** el carácter `'\n'` se codifica con un sólo carácter: *0a* (**LF**).
- Los compiladores de **C** para **Windows** hacen la correspondiente traducción del caracter `'\n'`.
- `fopen`: abrir el fichero.
- `fclose`: cerrar el fichero.
- `fwrite`: escribir en el fichero.
- `fprintf`: escribir en el fichero. Versión generalizada de `printf`.
- Los números pueden escribirse en:
    - **ASCII** (`fprintf`) o en
    - Binario (`fwrite`).

## Abrir un fichero

### fopen

- Crea un flujo *desde*, *hacia*, o bien *desde y hacia* un fichero.

```c
#include <stdio.h>
FILE *fopen( const char *nomfi, const char *modo );
// Compatibilidad: ANSI, UNIX y Windows
```

- *nomfi*: debe cumplir las reglas impuestas por el sistema operativo.
- *modo*: especifica cómo se va a abrir el fichero:

Modo|Descripción
:---|:---
***"r"***|Abrir un fichero para **leer**. Si el fichero no existe o no se encuentra, se obtiene un error.
***"w"***|Abrir un fichero para **escribir**. Si el fichero no existe, se crea; y si existe, su contenido se destruye para ser creado de nuevo.
***"a"***|Abrir un fichero para **añadir** información al final del mismo. Si el fichero no existe, se crea.
***"r+"***|Abrir un fichero para **leer** y **escribir**. El fichero debe existir.
***"w+"***|Abrir un fichero para **escribir** y **leer**. Si el fichero no existe, se crea; y si existe, su contenido se destruye para ser creado de nuevo.
***"a+"***|Abrir un fichero para **leer** y **añadir**. Si el fichero no existe, se crea.

- El puntero de L/E (Lectura o Escritura) se supone colocado al principio del fichero, excepto para el modo añadir que se supone colocado al final.
- Para el sistema **Windows**:

> - A diferencia de **UNIX**, en **Windows** un fichero puede ser abierto como fichero *de texto* o como fichero *binario*.
> - Por las incompatibilidades entre **C** y **Windows**, ya que **C** fue diseñado originalmente para **UNIX**.
> - Traducciones en **ficheros de texto** para: `'\n'` (*CR+LF* y *LF*) y `Ctrl+Z` (**EOF**).
> - Puede ocasionar problemas al desplazarse un número de bytes determinado (`fseek`).
> - Para evitar problemas, utilizar **ficheros binarios**.
> - A los modos se les puede añadir ***t*** o ***b*** (por ejemplo, *rb*, *a+b* o *ab+*).
> - La opción ***t*** es una extensión de **Microsoft C**.
> - Si ***t*** o ***b*** no se especifican, se utiliza el valor almacenado en la variable global `_fmode` de **C** (fichero de texto por defecto).
> - En **UNIX**, la opción ***b*** es ignorada, lo que permite la transportabilidad de un programa hecho en **Windows** a **UNIX**.

- Devuelve un puntero a una estructura de tipo `FILE`.
- Un puntero nulo indica un error.

### freopen

- Desvincula el dispositivo o fichero actualmente asociado con el flujo referenciado por *pflujo* y reasigna al fichero identificado por *nomfi*.
- Normalmente se utiliza para redireccionar `stdin`, `stdout`, `stderr` a ficheros especificados por el usuario.

```c
#include <stdio.h>
FILE *freopen( const char *nomfi, const char *modo, FILE *pflujo );
// Compatibilidad: ANSI, UNIX y Windows
```

- Devuelve un puntero al mismo flujo de datos, o un puntero nulo si ocurriera un error, en cuyo caso, el flujo original quedaría cerrado.

## Cerrar un fichero

- Si un fichero no se cierra explícitamente, es cerrado automáticamente cuando finaliza el programa.
- Un fichero abierto por una aplicación generalmente no está disponible para otra hasta que no se cierre.

### fclose

- Cualquier dato en el *buffer* asociado se escribe en el fichero antes de ser cerrado.

```c
#include <stdio.h>
int fclose( FILE *pf );
// Compatibilidad: ANSI, UNIX y Windows
```

- Devuelve 0 si se ejecuta satisfactoriamente, en otro caso, devuelve un **EOF**.

## Manipulación de errores

### ferror

- Observa los bits de error agrupados bajo el miembro `_flag` del flujo sobre el que se ejecutó la operación de E/S.
- Cada tipo de error viene dado por un bit (1 si ocurrió el error).
- Los bits activados permanecerán en ese estado hasta que se cierre el fichero o se invoque a `clearerr` o `rewind`.

```c
#include <stdio.h>
int ferror( FILE *pf );
// Compatibilidad: ANSI, UNIX y Windows
```

- Devuelve 0 si no ha ocurrido un error y un valor distinto en caso contrario.

### clearerr

- Pone a 0 los bits de error, incluido el bit de fin de fichero, en el miembro `_flag`.

```c
#include <stdio.h>
void clearerr( FILE *pf );
// Compatibilidad: ANSI, UNIX y Windows
```

### feof

- Al crear un fichero el sistema añade automáticamente al final del mismo una marca de fin de fichero.
- Cuando se intenta leer más allá de la marca de fin de fichero, el sistema pone a 1 el bit de *fin de fichero* del miembro `_flag`.

```c
#include <stdio.h>
int feof( FILE *pf );
// Compatibilidad: ANSI, UNIX y Windows
```

- Devuelve un valor distinto de 0 cuando se intenta leer más allá de **eof**, no cuando se lee el último registro, en otro caso devuelve 0.

### perror

- Escribe en `stderr`, el mensaje especificado seguido por dos puntos, seguidos del mensaje de error dado por el sistema terminado con `\n`.

```c
#include <stdio.h>
void perror( const char *mensaje );
// Compatibilidad: ANSI, UNIX y Windows
```

- `sys_errlist`: matriz que contiene los mensajes de error ordenados por el número de error (`stdlib.h`).
- `sys_nerr`: número de elementos de la matriz (`stdlib.h`).
- `errno`: número de error que se ha producido (`stdlib.h`, `errno.h`).

## Posición del puntero de L/E

- Cada operación de E/S tiene lugar a partir de la posición en el fichero definida por `_ptr` de la estructura `FILE`.
- Este puntero (*de lectura/escritura*) es automáticamente actualizado cuando finaliza dicha operación.

### ftell

- Permite obtener la posición en el fichero del puntero de L/E.

```c
#include <stdio.h>
long ftell( FILE *pf );
// Compatibilidad: ANSI, UNIX y Windows
```

- Devuelve la posición actual en el fichero, o bien el valor *-1L* si ocurre un error.
- Posición relativa al principio del fichero.

### fseek

- Permite fijar la posición donde se realizará la siguiente operación de L/E.

```c
#include <stdio.h>
int fseek( FILE *pf, long desp, int pos );
// Compatibilidad: ANSI, UNIX y Windows
```

- Mueve el puntero de L/E a una nueva localización desplazada *desp* bytes (valor positivo avanza, valor negativo retrocede) de la posición especificada por *pos*:

pos|significado
:---|:---
**SEEK_SET**|Hace referencia a la primera posición en el fichero.
**SEEK_CUR**|Hace referencia a la posición actual del puntero de L/E.
**SEEK_END**|Hace referencia a la última posición en el fichero.

- Devuelve 0 si se ejecuta satisfactoriamente y un valor distinto de 0 en caso contrario.

### rewind

- Mueve el puntero de L/E al principio del fichero asociado con *pf*.

```c
#include <stdio.h>
void rewind( FILE *pf );
// Compatibilidad: ANSI, UNIX y Windows
```

- Equivale a `fseek`, con la excepción de que `rewind` pone a 0 los bits de error y el bit de fin de fichero, y `fseek` no.

## E/S carácter a carácter

### fputc

- Escribe un carácter *car* en la posición indicada por el puntero de L/E.

```c
#include <stdio.h>
int fputc( int car, FILE *pf );
// Compatibilidad: ANSI, UNIX y Windows
```

- Devuelve el carácter escrito, o **EOF** si ocurre un error.
- Ya que **EOF** es un valor aceptado por *car*, es mejor utilizar `ferror`.

### fgetc

- Lee un carácter de la posición indicada por el puntero de L/E y avanza su posición al siguiente carácter a leer.

```c
#include <stdio.h>
int fgetc( FILE *pf );
// Compatibilidad: ANSI, UNIX y Windows
```

- Devuelve el carácter leído, o **EOF** si ocurre un error o se detecta el final del fichero.
- Ya que **EOF** es un valor aceptado, utilizar `ferror` o `feof`.
- `putw` y `getw`: sintaxis y comportamiento idéntico a `fputc` y `fgetc`, respectivamente.

## E/S de cadenas de caracteres

### fputs

- Permite copiar una cadena de caracteres en un fichero o dispositivo.

```c
#include <stdio.h>
int fputs( const char *cadena, FILE *pf );
// Compatibilidad: ANSI, UNIX y Windows
```

- La terminación `'\0'` no se copia.
- Devuelve un valor no negativo si se ejecuta satisfactoriamente, en caso contrario devuelve **EOF**.
- Para recuperar de una forma sencilla la información, es aconsejable copiar el carácter `\n` después de cada cadena.

### fgets

- Permite leer una cadena de caracteres en un fichero o dispositivo.

```c
#include <stdio.h>
char *fgets( char *cadena, int n, FILE *pf );
// Compatibilidad: ANSI, UNIX y Windows
```

- Lee desde la posición indicada por el puntero de L/E hasta el primer carácter nueva línea (`'\n'`), incluido éste, o bien hasta el final del fichero, o hasta que el número de caracteres sea igual a *n-1*.
- La terminación `'\0'` es añadida automáticamente a la cadena leída y el carácter `'\n'`, si lo hay, no es eliminado.
- Devuelve un puntero al principio de la cadena leída.
- Devuelve `NULL` si ha ocurrido un error o se ha detectado la marca de fin de fichero.
- Para determinar lo que ha ocurrido, invocar a `feof` o `ferror`.
- Permite controlar el número de caracteres leídos, a diferencia de `gets`, que podría leer más allá del final del *buffer*.

## Entrada/salida con formato

### fprintf

- Permite escribir sus argumentos, con el formato especificado, en un fichero o dispositivo.

```c
#include <stdio.h>
int fprintf( FILE *pf, const char *formato /* [, arg]... */ );
// Compatibilidad: ANSI, UNIX y Windows
```

- Devuelve el número de caracteres escritos o un valor negativo si ocurre un error.
- Cuando el flujo sea `stdout`, el resultado es el mismo de `printf`.
- Un dispositivo físico recibe el mismo tratamiento que un fichero en el disco.
- Los caracteres son almacenados uno por byte y los números enteros y reales requieren un byte por cada dígito (no es la forma idónea de almacenar datos).

### fscanf

- Permite leer sus argumentos, con el formato especificado, desde un fichero o dispositivo.

```c
#include <stdio.h>
int fscanf( FILE *pf, const char *formato /* [, arg]... */ );
// Compatibilidad: ANSI, UNIX y Windows
```

- Devuelve el número de argumentos que han sido leídos y asignados.
- Devuelve 0 si no se han asignado valores.
- Devuelve `EOF` si se ha detectado el final del fichero.
- Cuando el flujo sea `stdin`, el resultado es el mismo de `scanf`.

## E/S utilizando registros

### fwrite

- Permite escribir un bloque de bytes visto byte a byte, sin tener en cuenta el tipo de los datos almacenados.

```c
#include <stdio.h>
size_t fwrite( const void *buffer, size_t n, size_t c, FILE *pf );
// Compatibilidad: ANSI, UNIX y Windows
```

- Escribe *c* elementos de longitud *n* bytes (*c x n* bytes) almacenados en el *buffer* especificado.
- Devuelve el número de elementos actualmente escritos.
- Si el número es menor que *c*, entonces ha ocurrido un error.

```c
fwrite( &car, sizeof( char ), 1, pf1 );
fwrite( cadena, strlen( cadena ), 1, pf2 );

// Equivalentes a:
fputc( car, pf1 );
fputs( cadena, pf2 );
```

- Almacena los datos numéricos en formato binario.
- En **Windows**, no confundir el formato binario con la forma binaria (*b*) en la que se abre un fichero para evitar la traducción de `'\n'`.

### fread

- Permite leer un bloque de bytes, byte a byte, el tipo de los datos dependerá de la variable que los almacene.

```c
#include <stdio.h>
size_t fread( void *buffer, size_t n, size_t c, FILE *pf );
// Compatibilidad: ANSI, UNIX y Windows
```

- Lee *c* elementos de longitud *n* bytes (*c x n* bytes) del fichero y los almacena en el *buffer* especificado.
- Devuelve el número de elementos actualmente leídos.
- Si el número es menor que *c*, entonces ha ocurrido un error o se llegó al final del fichero.
- Usar `feof` o `ferror` para saber si fue un error o fin de fichero.
- Si *n* o *c* son 0, se devuelve un 0 y el contenido del *buffer* permanece igual.

```c
fread( &car, sizeof( char ), 1, pf1 );
fread( cadena, sizeof( cadena ) - 1, 1, pf2 );

// Equivalentes a:
car = fgetc( pf1 );
fgets( cadena, sizeof( cadena ), pf2 );
```

## Abriendo ficheros para acceso secuencial

- Tipo de acceso más simple a un fichero de datos.
- Registros que se escriben son colocados uno a continuación del otro, y cuando se leen, desde el primero hasta el final.
- Posibilita que los registros puedan ser de cualquier longitud.
- Generalmente se utiliza con ficheros de texto, pero no son los más apropiados para almacenar grandes series de números.
- Para el tratamiento de información numérica se sugiere utilizar `fwrite` y `fread`.

### Un ejemplo de acceso secuencial

- Para escribir datos en un fichero:
    1. Definimos un flujo hacia el fichero.
    1. Leemos los datos del dispositivo de entrada o de otro fichero, realizamos las operaciones y escribimos en el fichero. Los datos normalmente serán escritos registro a registro con `fwrite`.
    1. Cerramos el flujo.
- Para leer datos de un fichero:
    1. Abrimos un flujo desde el fichero.
    1. Leemos los datos del fichero y los almacenamos en variables para trabajar con ellos. Los datos normalmente serán escritos registro a registro con `fread`.
    1. Cerramos el flujo.
- Los datos deben ser recuperados del fichero con el mismo formato con el que fueron escritos.

## Escribir datos en la impresora

- Si el sistema no tiene un flujo estándar para el puerto paralelo, definir uno y vincularlo:
    - **Windows**: *lpt1*, *lpt2* o *prn*.
    - **UNIX**: */dev/lp0*, */dev/lp1*, etc.

## Control del buffer asociado con un flujo

- *Buffer*:
    - Área de datos en la memoria del sistema (memoria **RAM**) cuando se crea un flujo.
    - Evita la transferencia física de un fichero en el momento de la operación.
    - La transferencia física de datos se hace en múltiplos del tamaño del buffer.

### setvbuf

- Permite controlar la existencia de un *buffer* y su tamaño.
- Debe ejecutarse una vez abierto el fichero y antes de cualquier lectura o escritura, o bien después de haber llamado a `fflush`.

```c
#include <stdio.h>
int setvbuf( FILE *pf, char *buffer, int modo, size_t n );
// Compatibilidad: ANSI, UNIX y Windows
```

- *buffer*: matriz de caracteres de longitud *n* bytes que desempeña la función de *buffer* o memoria intermedia.
- *modo*:
    - `_IOFBF`: permite asignar un *buffer* de *n* bytes.
    - `_IONBF`: no se utilizará un *buffer*.
- Devuelve un 0 si se ejecuta satisfactoriamente, distinto de 0 en caso contrario.
- `BUFSIZ`: constante definida en `stdio.h`.
- No siempre a mayor buffer se obtendrá el mejor resultado, las diferencias pueden ser mínimas.

### fflush

- Escribe en el fichero el contenido del *buffer* definido para ese flujo.
- En **Windows**, no en **UNIX**, si el fichero está abierto para leer, `fflush` borra el contenido del *buffer*.

```c
#include <stdio.h>
int fflush( FILE *pf );
// Compatibilidad: ANSI, UNIX y Windows
```

- Devuelve 0 si se ejecuta con éxito, si el flujo no tiene un *buffer* o si fue abierto para leer solamente.
- En otro caso, devuelve `EOF`.

## Ficheros temporales

- Se crean durante la ejecución y se destruyen, como muy tarde, al finalizar la ejecución.

### tmpfile

- Crea un fichero temporal.
- Este fichero es automáticamente borrado cuando el fichero es cerrado o cuando el programa termina normalmente.
- El fichero temporal es abierto en modo *w+b*.

```c
#include <stdio.h>
FILE *tmpfile( void );
// Compatibilidad: ANSI, UNIX y Windows
```

- Devuelve un puntero al fichero temporal, o un puntero nulo si no es posible crearlo.

## Abriendo ficheros para acceso aleatorio

- Para modificar algunos de los valores contenidos en el fichero o extraer una parte concreta dentro del mismo.
- Puede resultar bastante complicado si las unidades de grabación (**registros**) no son todas iguales.
- Al reemplazar un registro *n* por otro, no debe sobrepasarse el número de bytes que actualmente tiene.
- Esto sería viable llevando la cuenta en una matriz de la posición de inicio de cada uno de los registros y de cada uno de los campos si fuera preciso.
- Para modificar un registro lo habitual es:
    - Preguntar por el número de registro, situar el puntero de L/E, leerlo y visualizarlo.
    - Preguntar si se desea modificar, solicitar los datos, situar el puntero de L/E y escribir el registro modificado de nuevo en el fichero.

[Inicio][Index] - [Arriba][Header]

<!-------------------------------------------------------------------------
 !  Links
-------------------------------------------------------------------------->

[Index]:        ../README.md
[Header]:       #header

[Section-01]:   #visión-general-de-los-flujos-de-es
[Section-02]:   #visión-general-de-un-fichero
[Section-03]:   #abrir-un-fichero
[Section-04]:   #cerrar-un-fichero
[Section-05]:   #manipulación-de-errores
[Section-06]:   #posición-del-puntero-de-le
[Section-07]:   #es-carácter-a-carácter
[Section-08]:   #es-de-cadenas-de-caracteres
[Section-09]:   #entradasalida-con-formato
[Section-10]:   #es-utilizando-registros
[Section-11]:   #abriendo-ficheros-para-acceso-secuencial
[Section-12]:   #escribir-datos-en-la-impresora
[Section-13]:   #control-del-buffer-asociado-con-un-flujo
[Section-14]:   #ficheros-temporales
[Section-15]:   #abriendo-ficheros-para-acceso-aleatorio
