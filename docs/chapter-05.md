# Sentencias de control

<a id="header"></a>

### Contenido

- [Sentencia **if**][Section-01]
- [Anidamiento de sentencias if][Section-02]
- [Estructura **else if**][Section-03]
- [Sentencia **switch**][Section-04]
- [Sentencia **while**][Section-05]
    - Bucles anidados
- [Sentencia **do ... while**][Section-06]
- [Sentencia **for**][Section-07]
- [Sentencia **break**][Section-08]
- [Sentencia **continue**][Section-09]
- [Sentencia **goto**][Section-10]

[Inicio][Index]

## Sentencia `if`

```c
if ( condición )
    sentencia1;
else
    sentencia2;
```

- *condición*: expresión numérica, relacional o lógica.
- *sentencia1 y 2*: sentencias simples o compuestas.

```c
// Equivalentes:
if ( x )
if ( x != 0 )
```

```c
if ( a = b * 5 )

// Equivalente a:

a = b * 5;
if ( a )
```

## Anidamiento de sentencias if

- Si se omiten las llaves, cada `else` se corresponde con el `if` más próximo que no haya sido emparejado.
- Recordar que si no se cumple la condición, todo el bloque ya no se ejecuta y pasa directo a la siguiente línea ejecutable del código.

## Estructura `else if`

```c
if ( condición1 )
    sentencia1;
else if ( condición2 )
    sentencia2;
else if ( condición3 )
    sentencia3;

/*
    Más sentencias else if ...
*/

else
    sentenciaN;
```

- Las sentencias *1, 2, ..., N* pueden ser simples o compuestas.

## Sentencia `switch`

```c
switch ( expresión )
{
    case expresión-constante1:
        sentencia1;
    case expresión-constante2:
        sentencia2;

    // Más cases ...

    default:
        sentenciaN;
}
```

- En función del valor de una expresión.
- *expresión* es una expresión entera.
- *expresión-constante* es una constante entera, una constante de un solo carácter o una expresión constante de valor resultante entero.
- *sentencia*: simple o compuesta.
- La cláusula `default` puede colocarse en cualquier parte del bloque.
- La sentencia `break` permite salir del bloque de `switch`.
- Es posible hacer declaraciones en el bloque (`{ }`) de cada `case` y/o al principio de `switch`.
- Si hubieran iniciaciones, son ignoradas.
- Las cláusulas `case` pueden ir en una línea separadas por un espacio.
- La sentencia `break` al final no es necesaria (en `default`), sólo obedece a un buen estilo de programación.

## Sentencia `while`

```c
while ( condición )
    sentencia;
```

- *condición*: expresión numérica, relacional o lógica.
- *sentencia*: simple o compuesta.
- Para salir de un **bucle infinito** presionar `Ctrl + C`.

### Bucles anidados

- Una sentencia `while`, `do` o `for` dentro de otra de ellas.

## Sentencia `do ... while`

```c
do
    sentencia;
while ( condición );
```

- *condición*: expresión numérica, relacional o lógica.
- *sentencia*: simple o compuesta.
- Termina en punto y coma `;`.

## Sentencia `for`

```c
for ( /* [ v1 = e1 [, v2 = e2] ... ] */; /* [ condición ] */; /* [ progresión-condición ] */ )
    sentencia;
```

- *v1, v2* variables de control, iniciadas con los valores de las expresiones *e1, e2*.
- *condición*: expresión booleana, se se omite: verdadera.
- *progresión-condición*: una o más expresiones separadas por comas, para finalizar la ejecución de `for`.
- *sentencia*: simple o compuesta.
- Bucle infinito:

```c
for ( ; ; )
```

## Sentencia `break`

- Finaliza la ejecución de un bucle: `while`, `do` o `for`.
- Cuando están anidadas, sólo finaliza el bucle en el que está incluído.

## Sentencia `continue`

- Obliga a ejecutar la siguiente iteración del bucle `while`, `do` o `for`.

```c
continue;
```

## Sentencia `goto`

```c
goto etiqueta;

// Código ...

etiqueta: sentencia;
```

- Transfiere el control a una línea específica del programa, identificada por una ***etiqueta***.
- No se puede transferir el control fuera del cuerpo de la función en la que se encuentra.
- Un uso abusivo de ésta, da programas difíciles de interpretar y mantener.
- En **programación estructurada**, se utiliza solamente en ocasiones excepcionales.
- El uso más normal consiste en abandonar alguna estructura profundamente anidada.

[Inicio][Index] - [Arriba][Header]

<!-------------------------------------------------------------------------
 !  Links
-------------------------------------------------------------------------->

[Index]:        ../README.md
[Header]:       #header

[Section-01]:   #sentencia-if
[Section-02]:   #anidamiento-de-sentencias-if
[Section-03]:   #estructura-else-if
[Section-04]:   #sentencia-switch
[Section-05]:   #sentencia-while
[Section-06]:   #sentencia-do--while
[Section-07]:   #sentencia-for
[Section-08]:   #sentencia-break
[Section-09]:   #sentencia-continue
[Section-10]:   #sentencia-goto
