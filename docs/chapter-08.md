# Más sobre funciones

<a id="header"></a>

### Contenido

- [Pasar una matriz como argumento a una función][Section-01]
    - Matrices estáticas
    - Matrices dinámicas
- [Pasar un puntero como argumento a una función][Section-02]
- [Pasar una estructura a una función][Section-03]
- [Datos retornados por una función][Section-04]
- [Argumentos en la línea de órdenes][Section-05]
- [Redirección de la entrada y de la salida][Section-06]
- [Funciones recursivas][Section-07]
- [Punteros a funciones][Section-08]

[Inicio][Index]

## Pasar una matriz como argumento a una función

- **Matriz estática**: cuando el compilador hace la reserva de memoria (su nombre es una constante).
- **Matriz dinámica**: cuando la reserva se realiza durante la ejecución del programa.

### Matrices estáticas

- Siempre son pasadas **por referencia**.
- Matriz unidimensional como parámetro: `int matriz[]`.
- Matriz multidimensional como parámetro: `int matriz[][COLS]`.
- El nombre de una matriz representa una dirección de un nivel de indirección, almacenable en un puntero con un nivel de indirección: `int *pMatriz`.
- En matrices multidimensionales:

```c
// Por indexación
void Función( int ( *pMatriz )[ COLS ] )
{
    // ...

    pMatriz[ fila ][ col ] = algo;

    // ...
}

// Con aritmética de punteros
void Función( int *pMatriz )
{
    // ...

    *( pMatriz + ( fila * COLS ) + col ) = algo;

    // ...
}
```

### Matrices dinámicas

- Referenciada por una variable tipo puntero con tantos niveles de indirección como dimensiones tenga la matriz.

## Pasar un puntero como argumento a una función

- Puede ser pasado **por valor** o **por referencia**.
- En ambos casos, los datos apuntados son pasados **por referencia**.

```c
void FuncionA( int ** );
void FuncionB( int *** );

main()
{
    int **p;

    // ...

    FuncionA( p );  // Por valor
    FuncionB( &p ); // Por referencia

    // ...
}
```

## Pasar una estructura a una función

- Puede ser pasada **por valor** o **por referencia**.

## Datos retornados por una función

- No se puede devolver una matriz, ya que al finalizar la función, los datos de la matriz serán destruidos y sólo quedará una dirección de memoria con la que ya no se podrán acceder a los datos.
- Una función deberá devolver:
    - Una copia de los datos.
    - La dirección de un bloque de memoria reservado dinámicamente para contener los datos.
    - La dirección de una variable declarada **static**.

## Argumentos en la línea de órdenes

```c
int main( int argc, char *argv[] );
```

- *argc*: número de argumentos pasados a través de la línea de órdenes, incluido el nombre del programa.
- *argv*: *argv[0]* contiene el nombre del programa, *argv[1]* el primer argumento de la línea de órdenes, *argv[2]* el segundo argumento, etc.
- Retorna un **int** para expresar el éxito o no de la ejecución de **main**.

## Redirección de la entrada y de la salida

- Redireccionar la entrada y salida, de y a, un medio diferente, por ejemplo, un fichero en el disco:

```bash
# Programa redir

redir [argumentos] < fdatos.ent
redir [argumentos] > fdatos.sal

# En simultáneo
redir [argumentos] < fdatos.ent > fdatos.sal
```

```bash
# En PowerShell

Get-Content fdatos.ent | ./redir.exe [argumentos]
Get-Content fdatos.ent | ./redir.exe [argumentos] > fdatos.sal
```

## Funciones recursivas

- Función que se llama a sí misma.
- Las variables **static** solamente son iniciadas una vez, en la primera llamada.
- ¿Cuándo es eficaz? Cuando el proceso a programar sea por definición recursivo:

```c
// Factorial de un número:
// n! = n(n-1)!

factorial( n ) = n * factorial( n - 1 );
```

Nivel de recursión|Proceso de ida (pila de llamadas)|Proceso de vuelta
:---:|:---:|:---:
0|factorial( 4 )|24
1|4 * factorial( 3 )|4 * 6
2|3 * factorial( 2 )|3 * 2
3|2 * factorial( 1 )|2 * 1
4|1 * factorial( 0 )|1 * 1

- Por su uso de memoria, en aplicaciones prácticas, es imperativo demostrar que el nivel máximo de recursión es, no sólo finito, sino realmente pequeño.
- El uso de la recursión debe evitarse cuando haya una solución obvia por iteración.

## Punteros a funciones

- El nombre de la función representa la dirección donde se localiza esa función.

```c
// Puntero a una función:

tipo ( *p_identif )( /* Tipo de argumentos */ );
```

- *tipo*: valor devuelto por la función.
- *p_identif*: nombre de la variable de tipo puntero.
- Paréntesis vacíos:
    - En **C**: cualquier número y tipo de argumentos (para indicar sin argumentos: `void`).
    - En **C++**: sin argumentos (`void`).

```c
// Invocar a la función apuntada:

( *p_identif )( /* Argumentos */ ); // ó
p_identif( /* Argumentos */ );
```

- Operar con matrices unidimensionales de punteros a funciones:

```c
double ( *ptFuncion[ 10 ] )();
```

```c
typedef double ( *t_ptFuncion )();

main()
{
    t_ptFuncion ptFuncion[ 10 ];

    // ...
}
```

[Inicio][Index] - [Arriba][Header]

<!-------------------------------------------------------------------------
 !  Links
-------------------------------------------------------------------------->

[Index]:        ../README.md
[Header]:       #header

[Section-01]:   #pasar-una-matriz-como-argumento-a-una-función
[Section-02]:   #pasar-un-puntero-como-argumento-a-una-función
[Section-03]:   #pasar-una-estructura-a-una-función
[Section-04]:   #datos-retornados-por-una-función
[Section-05]:   #argumentos-en-la-línea-de-órdenes
[Section-06]:   #redirección-de-la-entrada-y-de-la-salida
[Section-07]:   #funciones-recursivas
[Section-08]:   #punteros-a-funciones
