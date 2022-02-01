# C/C++ Curso de Programación: Ejercicios propuestos

<a id="header"></a>

[Inicio][Index]

## 01 Fases en el desarrollo de un programa

**Ejercicio 02:**

> Practique la edición, la compilación y ejecución con un programa similar al
> programa *aritmeti.c* realizado en el apartado anterior. Por ejemplo, modifíquelo
> para que ahora realice las operaciones de sumar, restar, multiplicar y dividir con
> tres datos: *dato1*, *dato2*, *dato3*. En un segundo intento, puede también combinar
> las operaciones aritméticas.
>
> [Solución](chapter-01/ejercicio-02.c)

## 02 Elementos del lenguaje C

**Ejercicio 02:**

> Escriba un programa que visualice los siguientes mensajes:
>
> ```
> Los programas escritos en C,
> son portables en código fuente.
> ```
>
> [Solución](chapter-02/ejercicio-02.c)

**Ejercicio 05:**

> Escriba las sentencias necesarias para visualizar el tamaño en *bytes* de cada uno
> de los tipos primitivos de C.
>
> [Solución](chapter-02/ejercicio-05.c)

**Ejercicio 06:**

> Escriba un programa que visualice su nombre, dirección y teléfono en líneas
> diferentes y centrados en la pantalla.
>
> [Solución](chapter-02/ejercicio-06.c)

**Ejercicio 07:**

> Escriba un programa que calcule la suma y la media de cuatro valores de tipo **int**.
>
> [Solución](chapter-02/ejercicio-07.c)

**Ejercicio 08:**

> Escriba un programa que visualice el resultado de la expresión:
>
> *(b<sup>2</sup> - 4ac) / 2a*
>
> para valores de *a = 1*, *b = 5* y *c = 2*.
>
> [Solución](chapter-02/ejercicio-08.c)

## 03 Estructura de un programa

> Sin ejercicios

## 04 Entrada y salida estándar

**Ejercicio 02:**

> Realizar un programa que calcule el volumen de una esfera, que viene dado por la
> fórmula:
>
> v = ( 4 * π * r³ ) / 3
>
> [Solución](chapter-04/ejercicio-02.c)

**Ejercicio 03:**

> Realizar un programa que pregunte el nombre, el año de nacimiento y el año
> actual, y dé como resultado:
>
> ```
> Hola nombre, en el año 2030 cumplirás n años
> ```
>
> [Solución](chapter-04/ejercicio-03.c)

**Ejercicio 04:**

> Realizar un programa que evalúe el polinomio *p = 3x⁵ - 5x³ + 2x - 7* y visualice
> el resultado con el siguiente formato:
>
> ```
> Para x = valor, 3x^5 - 5x^3 + 2x - 7 = resultado
> ```
>
> [Solución](chapter-04/ejercicio-04.c)

**Ejercicio 05:**

> Realizar el mismo programa anterior, pero empleando ahora coeficientes variables
> *a*, *b* y *c*.
>
> [Solución](chapter-04/ejercicio-05.c)

**Ejercicio 06:**

> Ejecute el siguiente programa, explique lo que ocurre y realice las modificaciones
> que sean necesarias para su correcto funcionamiento.
>
> ```c
> #include <stdio.h>
> void main()
> {
>   int car = 0;
>   car = getchar();
>   putchar(car);
>   car = getchar();
>   putchar(car);
> }
> ```
>
> [Solución](chapter-04/ejercicio-06.c)

**Ejercicio 07:**

> Indique qué resultado da el siguiente programa. A continuación ejecute el
> programa y compare los resultados.
>
> ```c
> #include <stdio.h>
> main()
> {
>   char car1 = 'A', car2 = 65, car3 = 0;
>   car3 = car1 + 'a' - 'A';
>   printf("%d %c\n", car3, car3);
>   car3 = car2 + 32;
>   printf("%d %c\n", car3, car3);
> }
> ```
>
> [Solución](chapter-04/ejercicio-07.c)

## 05 Sentencias de control

**Ejercicio 02:**

> Realizar un programa que calcule e imprima la suma de los múltiplos de 5
> comprendidos entre dos valores *a* y *b*. El programa no permitirá introducir valores
> negativos para *a* y *b*, y verificará que *a* es menor que *b*. Si *a* es mayor que *b*,
> intercambiará estos valores.
>
> [Solución](chapter-05/ejercicio-02.c)

**Ejercicio 03:**

> Realizar un programa que permita evaluar la serie:
>
>     Sumatoria <a = 0; b> de 1 / (x + ay)
>
> [Solución](chapter-05/ejercicio-03.c)

**Ejercicio 04:**

> Si quiere averiguar su número de Tarot, sume los números de su fecha de
> nacimiento y a continuación redúzcalos a un único dígito; por ejemplo si su fecha de
> nacimiento fuera 17 de octubre de 1992, los cálculos a realizar serían:
>
>     17 + 10 + 1992 = 2019 => 2 + 0 + 1 + 9 = 12 => 1 + 2 = 3
>
> lo que quiere decir que su número de Tarot es el 3.
>
> Realizar un programa que pida una fecha, de la forma:
>
>     día mes año
>
> donde *día*, *mes* y *año* son enteros, y dé como resultado el número de Tarot. El
> programa verificará si la fecha es correcta, esto es, los valores están dentro de los
> rangos permitidos.
>
> [Solución](chapter-05/ejercicio-04.c)

**Ejercicio 05:**

> Realizar un programa que genere la siguiente secuencia de dígitos:
>
>                                  1
>                                2 3 2
>                              3 4 5 4 3
>                            4 5 6 7 6 5 4
>                          5 6 7 8 9 8 7 6 5
>                        6 7 8 9 0 1 0 9 8 7 6
>                      7 8 9 0 1 2 3 2 1 0 9 8 7
>                    8 9 0 1 2 3 4 5 4 3 2 1 0 9 8
>                  9 0 1 2 3 4 5 6 7 6 5 4 3 2 1 0 9
>                0 1 2 3 4 5 6 7 8 9 8 7 6 5 4 3 2 1 0
>              1 2 3 4 5 6 7 8 9 0 1 0 9 8 7 6 5 4 3 2 1
>            2 3 . . . . . . . . . . . . . . . . . . . . .
>
> El número de filas estará comprendido entre 11 y 20 y el resultado aparecerá
> centrado en la pantalla como se indica en la figura.
>
> [Solución](chapter-05/ejercicio-05.c)

**Ejercicio 06:**

> Un centro numérico es un número que separa una lista de números enteros
> (comenzando en 1) en dos grupos de números, cuyas sumas son iguales. El primer
> centro numérico es el 6, el cual separa la lista (1 a 8) en los grupos: (1, 2, 3, 4, 5)
> y (7, 8) cuyas sumas son ambas iguales a 15. El segundo centro numérico es el 35,
> el cual separa la lista (1 a 49) en los grupos: (1 a 34) y (36 a 49) cuyas sumas son
> ambas iguales a 595. Escribir un programa que calcule los centros numéricos
> entre 1 y *n*.
>
> [Solución](chapter-05/ejercicio-06.c)

**Ejercicio 07:**

> Realizar un programa que solicite un texto (suponer que los caracteres que forman
> el texto son sólo letras, espacios en blanco, comas y el punto como final del texto)
> y a continuación lo escriba modificado de forma que a la A le corresponda la K, a
> la B la L, ... , a la O la Y, a la P la Z, a la Q la A, ... y a la Z la J, e igual para las
> letras minúsculas. Suponga que la entrada no excede de una línea y que finaliza
> con un punto.
>
> Al realizar este programa tenga en cuenta que el tipo **char** es un tipo entero, por lo
> tanto las afirmaciones en los ejemplos siguientes son correctas:
>
> - 'A' es menor que 'a'; es equivalente a decir que 65 es menor que 97, porque
>   el valor ASCII de 'A' es 65 y el de 'a' es 97.
>
> - 'A' + 3 es igual a 'D'; es equivalente a decir que 65 + 3 es igual a 68, y este
>   valor es el código ASCII del carácter 'D'.
>
> [Solución](chapter-05/ejercicio-07.c)

**Ejercicio 08:**

> Realizar un programa que calcule el importe a pagar por un vehículo al circular
> por una autopista. El vehículo puede ser una bicicleta, una moto, un coche o un
> camión. Para definir el conjunto vehículos utilizaremos un tipo enumerado (vea
> en el capítulo 2 los tipos enumerados). El importe se calculará según los siguien-
> tes datos:
>
> - Un importe fijo de 100 unidades para las bicicletas.
> - Las motos y los coches pagarán 30 unidades por Km.
> - Los camiones pagarán 30 unidades por Km más 25 unidades por Tn.
>
> La presentación en pantalla de la solución, será de la forma siguiente:
>
> ```
>         1 - bicicleta
>         2 - moto
>         3 - coche
>         4 - camión
>         5 - salir
>
> Seleccione la opción deseada: 4
> Kilómetros y toneladas? 100 50
> Importe = 4250
> ```
>
> [Solución](chapter-05/ejercicio-08.c)

## 06 Tipos estructurados de datos

**Ejercicio 02:**

> Se desea realizar un histograma con los pesos de los alumnos de un determinado
> curso.
>
> ```
> Peso      Numero de alumnos
> ---------------------------
>  21       **
>  22       ****
>  23       ***************
>  24       ******
>  ..       ...
> ```
>
> El número de asteriscos se corresponde con el número de alumnos del peso
> especificado.
>
> Realizar un programa que lea los pesos e imprima el histograma correspondiente.
> Suponer que los pesos están comprendidos entre los valores 10 y 100 Kg. En el
> histograma sólo aparecerán los pesos que se corresponden con uno o más
> alumnos.
>
> [Solución](chapter-06/ejercicio-02.c)

**Ejercicio 03:**

> Realizar un programa que lea una cadena de caracteres e imprima el resultado que
> se obtiene cada vez que se realice una rotación de un carácter a la derecha sobre
> dicha cadena. El proceso finalizará cuando se haya obtenido nuevamente la
> cadena de caracteres original. Por ejemplo:
>
>     HOLA AHOL LAHO OLAH HOLA
>
> [Solución](chapter-06/ejercicio-03.c)

**Ejercicio 04:**

> Realizar un programa que lea una cadena de caracteres y la almacene en una
> matriz. A continuación, utilizando una función, deberá convertir los caracteres
> escritos en mayúsculas a minúsculas. Finalmente imprimirá el resultado.
>
> [Solución](chapter-06/ejercicio-04.c)

**Ejercicio 05:**

> La mediana de una lista de *n* números se define como el valor que es menor o
> igual que los valores correspondientes a la mitad de los números, y mayor o igual
> que los valores correspondientes a la otra mitad. Por ejemplo, la mediana de:
>
>     16 12 99 95 18 87 10
>
> es 18, porque este valor es menor que 99, 95, 87 (mitad de los números) y mayor
> que 16, 12 y 10 (otra mitad).
>
> Realizar un programa que lea un número impar de valores y dé como resultado la
> mediana. La entrada de valores finalizará cuando se detecte la marca de fin de
> fichero.
>
> [Solución](chapter-06/ejercicio-05.c)

**Ejercicio 06:**

> Escribir un programa que utilice una función para leer una línea de la entrada y dé
> como resultado la línea leída y su longitud o número de caracteres.
>
> [Solución](chapter-06/ejercicio-06.c)

**Ejercicio 07:**

> Analice el programa que se muestra a continuación e indique el significado que
> tiene el resultado que se obtiene.
>
> ```c
> #include <stdio.h>
> #include <stdlib.h>
>
> void Visualizar( unsigned char c );
> unsigned char fnxxx( unsigned char c );
>
> void main()
> {
> 	unsigned char c;
>
> 	printf( "Introducir un caracter: " );
> 	c = getchar();
> 	Visualizar( c );
>
> 	printf( "\nCaracter resultante:\n" );
> 	c = fnxxx( c );
> 	Visualizar( c );
> }
>
> void Visualizar( unsigned char c )
> {
> 	int i = 0;
> 	for ( i = 7; i >= 0; i-- )
>     printf( "%d", ( c & ( 1 << i ) ) ? 1 : 0 );
> 	printf( "\n" );
> }
>
> unsigned char fnxxx( unsigned char c )
> {
> 	return ( ( ( c & 0x01 ) << 7 ) | ( ( c & 0x02 ) << 5 ) |
> 			 ( ( c & 0x04 ) << 3 ) | ( ( c & 0x08 ) << 1 ) |
> 			 ( ( c & 0x10 ) >> 1 ) | ( ( c & 0x20 ) >> 3 ) |
> 			 ( ( c & 0x40 ) >> 5 ) | ( ( c & 0x80 ) >> 7 ) );
> }
> ```
>
> [Solución](chapter-06/ejercicio-07.c)

**Ejercicio 08:**

> En el apartado de ejercicios resueltos se ha presentado un programa para
> visualila representación interna de un **float**. ¿Se podría resolver este problema
> utilizando una función como la siguiente? Razone su respuesta.
>
> ```c
> void presentar( float c )
> {
>   int i = 0;
>   for (i = 31; i>=0; i--)
>     printf("%d", (c & (1 << i)) ? 1 : 0);
>   printf("\n");
> }
> ```
>
> [Solución](chapter-06/ejercicio-08.c)

**Ejercicio 09:**

> Para almacenar una matriz bidimensional que generalmente tiene muchos
> elementos nulos (matriz *sparse*) se puede utilizar una matriz unidimensional en la que
> sólo se guarden los elementos no nulos precedidos por sus índices, *fila* y *columna*,
> lo que redunda en un aprovechamiento de espacio. Por ejemplo, la matriz:
>
> ```
> 6 0 0 0 4
> 0 5 0 0 2
> 2 0 0 0 0
> 0 0 7 0 0
> 0 0 0 8 0
> ```
>
> se guardará en una matriz unidimensional así:
>
> ```
>                                                               +- fila
>                                                               |   +- columna
> se guardará en una matriz unidimensional así:                 |   |   +- valor
>                                                               ↓   ↓   ↓
> +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
> | 0 | 0 | 6 | 0 | 4 | 4 | 1 | 1 | 5 | 1 | 4 | 2 | 2 | 0 | 2 | 3 | 2 | 7 | 4 | 3 | 8 |
> +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
> ```
>
> Para trabajar con esta matriz utilizaremos la siguiente declaración:
>
> ```c
> typedef int tMatrizU[300];
> ```
>
> Se pide:
>
> - Escribir una función que lea una matriz bidimensional por filas y la almacene
>   en una matriz *m* de tipo *tMatrizU*. El prototipo de esta función será:
>
>   ```c
>   int CrearMatrizUni( tMatrizU m, int fi, int co );
>   ```
>
>   Los parámetros *fi* y *co* se corresponden con el número de filas y de columnas
>   de la supuesta matriz bidimensional.
>
> - Escribir una función que permita representar en pantalla la matriz
>   bidimensional por filas y columnas. El prototipo de esta función será:
>
>   ```c
> 	int Visualizar( int f, int c, tMatrizU m, int n );
>   ```
>
> 	Los parámetros *f* y *c* se corresponden con la fila y la columna del elemento
>   que se visualiza. El valor del elemento que se visualiza se obtiene,
>   lógicamente, de la matriz unidimensional creada en el apartado *a*, así: buscamos por los
>   índices *f* y *c*; si se encuentran, la función *Visualizar* devuelve el valor
>   almacenado justamente a continuación; si no se encuentran, entonces devuelve un 0.
>   El parámetro *n* indica el número de elementos no nulos de la matriz
>   bidimensional.
>
>   Escribir un programa que, utilizando la función *CrearMatrizUni*, cree una
>   matriz unidimensional a partir de una supuesta matriz sparse bidimensional y
>   a continuación, utilizando la función *Visualizar*, muestre en pantalla la matriz
>   bidimensional.
>
> [Solución](chapter-06/ejercicio-09.c)

## 07 Punteros

**Ejercicio 02:**

> Realizar un programa que permita utilizar el terminal como un diccionario
> Inglés-Español; esto es, al introducir una palabra en inglés, se escribirá la
> correspondiente palabra en español. El número de parejas de palabras es variable, pero limitado
> a un máximo de 100. La longitud máxima de cada palabra será de 40 caracteres.
> Como ejemplo, supongamos que introducimos las siguientes parejas de palabras:
>
>     book      libro
>     green     verde
>     mouse     ratón
>
> Una vez finalizada la introducción de la lista, pasamos al modo traducción, de
> forma que si tecleamos *green*, la respuesta ha de ser *verde*. Si la palabra no se
> encuentra, se emitirá un mensaje que lo indique.
>
> El programa constará al menos de dos funciones:
>
> - *CrearDiccionario*. Esta función creará el diccionario.
>
> - *Traducir*. Esta función realizará la labor de traducción.
>
> [Solución](chapter-07/ejercicio-02.c)

**Ejercicio 03:**

> Un cuadrado mágico se compone de números enteros comprendidos entre *1* y *n<sup>2</sup>*,
> donde *n* es un número impar que indica el orden de la matriz cuadrada que
> contiene los números que forman dicho cuadrado mágico. La matriz que forma este
> cuadrado mágico cumple que la suma de los valores que componen cada fila, cada
> columna y cada diagonal es la misma. Por ejemplo, un cuadrado mágico de orden
> 3, *n* = 3, implica una matriz de 3 por 3. Por lo tanto, los valores de la matriz
> estarán comprendidos entre 1 y 9 y dispuestos de la siguiente forma:
>
>                                                   8  1  6
>                                                   3  5  7
>                                                   4  9  2
>
> Realizar un programa que visualice un cuadrado mágico de orden impar *n*. El
> programa verificará que *n* es impar y está comprendido entre 3 y 15.
>
> Una forma de construirlo consiste en situar el número 1 en el centro de la
> primera línea, el número siguiente en la casilla situada encima y a la derecha, y así
> sucesivamente. Es preciso tener en cuenta que el cuadrado se cierra sobre sí mis-
> mo; esto es, la línea encima de la primera es la última y la columna a la derecha
> de la última es la primera. Siguiendo esta regla, cuando el número caiga en una
> casilla ocupada, se elige la casilla situada debajo del último número situado.
>
> Se deberán realizar al menos las siguientes funciones:
>
> - *Es_impar*. Esta función verificará si *n* es impar.
> - *Cuadrado_magico*. Esta función construirá el cuadrado mágico.
>
> [Solución](chapter-07/ejercicio-03.c)

**Ejercicio 04:**

> Se define la función *f(t)* como:
>
>            +-
>            | ∫e^(-t^2)dt si t>=0
>     f(t) = |
>            |      0      si t<0
>            +-
>
> Se pide escribir un programa que nos permita evaluar *f(t)*. Para ello se
> realizarán los siguientes pasos:
>
> - Escribir una función que permita evaluar el integrando *e<sup>-t<sup>2</sup></sup>*. El prototipo de
>   esta función será así:
>
>       double f(double t);
>
>   Para implementar esta función se aconseja utilizar la función *exp(t)*, que
>   permite evaluar *e<sup>t</sup>* y que se encuentra declarada en el fichero de cabecera *math.h*
>   así:
>
> 	    double exp(double t);
>
> - Escribir una función que genere números seudoaleatorios dentro de un
>   determinado rango. El prototipo de esta función será así:
>
>       double rnd(long &r);
>
>   La función *rnd*, cada vez que se invoque, generará un número seudoaleatorio
>   comprendido entre *0* y *t*.
>
> - Escribir un programa que pida un valor de *t* y utilizando las funciones
>   anteriores calcule *f(t)*.
>
>   * La función *e<sup>-t<sup>2</sup></sup>* es positiva monótona decreciente. En *0* vale *1* y tiende a *0*
>     cuando *t* crece. La primitiva de esta función, no se conoce.
>
>          e^(-t^2) |
>                   |
>                 1 +-------------------------------------------
>                   |*
>                   |*
>                   | *
>                   |   *
>                   |       *
>                   |             *
>                   |                           *            *
>                 --+-------------------------------------------
>                 0 |                                          t
>
> 	* La forma de solucionar este problema es análoga al cálculo del volumen
> 	  de una esfera realizado en el apartado *Ejercicios resueltos*.
>
> [Solución](chapter-07/ejercicio-04.c)

**Ejercicio 05:**

> Una empresa dedicada a la venta de electrodomésticos y a su posterior
> mantenimiento desea tener una aplicación que automatice todos sus procesos de gestión.
>
> Esto supone tener la información de todos los clientes que compran
> electrodomésticos junto con los contratos de mantenimiento (esta última información,
> lógicamente, sólo estará disponible en los casos que el cliente contrate un seguro
> de mantenimiento para los electrodomésticos adquiridos) almacenada en una
> matriz dinámica de estructuras.
>
> Cada cliente podrá asegurar o no el electrodoméstico comprado y cada
> electrodoméstico asegurado dará lugar a un contrato de mantenimiento.
>
> La estructura *tcon* almacena la información de cada electrodoméstico
> comprado y asegurado:
>
> ```c
> typedef struct
> {
>   char Descripcion[80];  // Descripción del electrodoméstico
>   int ValorCompra;       // Valor del electrodoméstico
>   int ImpContrato;       // Importe del contrato de mantenimiento
>   char NumSerie[15];     // Número de serie del aparato
>   char NumContrato[10];  // Número del contrato
> } tcon;
> ```
>
> Para almacenar los contratos de mantenimiento subscritos por cada cliente, se
> define una estructura *tcontrato* así:
>
> ```c
> typedef struct
> {
>   tcon *Contrato;        // Puntero a una estructura tcon
>   int nContratosAct;     // Número actual de contratos por cliente
> } tcontrato;
> ```
>
> Para almacenar los datos de los clientes que han comprado electrodomésticos
> aunque no hayan asegurado ninguno, se define una estructura *tcliente* así:
>
> ```c
> typedef struct
> {
>   char Nombre[35];       // Nombre del cliente
>   char Apellidos[55];    // Apellidos del cliente
>   char Direccion[35];    // Dirección del cliente
>   char Codigo[15];       // Código del cliente
>   tcontrato ContratoCli; // Estructura del tipo tcontrato
> } tcliente;
> ```
>
> La matriz dinámica de estructuras con la información de los clientes estará
> referenciada por la variable *pcliente* definida a continuación:
>
> ```c
> tcliente *pcliente;
> ```
>
> Partiendo de las declaraciones anteriores y suponiendo que existe una matriz
> apuntada por *pcliente* correctamente iniciada, implemente las siguientes -
> funciones:
>
> 1. Función *AutorizaReparacion*. Indica si se autoriza o no una reparación de un
>    electrodoméstico dependiendo de los siguientes requisitos:
>
>    * Existe un contrato para el electrodoméstico con el número de serie
>      especificado.
>    * El coste de la reparación no excede del 25% del valor de compra.
>
>
>    ```c
>    int AutorizaReparacion(tcliente *pcliente,
>                           char numSerie[15],
>                           int numClientes,
>                           int impReparacion);
>
>    // Parámetros:
>    // pcliente         puntero a la matriz de estructuras tcliente.
>    // numSerie         número de serie del aparato.
>    // numClientes      número de clientes existentes.
>    // impReparacion    coste de la reparación.
>    ```
>
>    Valor retornado:<br />
>    Un 0 si el importe de la reparación excede el 25% de la compra, un 1 si se
>    autoriza y un 2 si el número de serie no existe.
>
> 2. Función *DarDeAltaUnContrato*. Dará de alta un contrato para un cliente
>    existente en *pcliente*, solicitando los datos desde el teclado. El prototipo de la
>    función *DarDeAltaUnContrato* se indica a continuación:
>
>    ```c
>    void DarDeAltaUnContrato(tcliente *pcliente, int i);
>
>    // Parámetros:
>    // pcliente         puntero a la matriz de estructuras tcliente.
>    // i                posición del cliente poseedor del nuevo contrato.
>    ```
>
>    Valor retornado: ninguno.
>
>    *Nota*: el nuevo contrato introducido se insertará en la posición primera si este
>    cliente no tuviera contratos vigentes. En caso contrario, se insertará después
>    del último contrato existente (se sugiere utilizar la función **realloc**).
>
> 3. Función *BuscarPosicion*. Permite encontrar la posición de un determinado
>    cliente en la matriz dinámica de estructuras. El prototipo para esta función es
>    el siguiente:
>
>    ```c
>    int BuscarPosicion(tcliente *pcliente,
>                       char *codigo, int numClientes);
>
>    // Parámetros:
>    // pcliente         puntero a la matriz de estructuras tcliente.
>    // codigo           código del cliente.
>    // numClientes      número de clientes existentes.
>    ```
>
>    Valor retornado:<br />
>    Un entero que indica la posición que ocupa el cliente en la matriz, o -1 si el
>    cliente no se encuentra.
>
> 4. Función *Listar*. Mostrará en pantalla un listado de todos los datos de los clien-
>    tes. En el caso de que un cliente no tenga ningún contrato mostrará un mensa-
>    je indicándolo.
>
>    ```c
>    void Listar(tcliente *pcliente, int numClientes);
>
>    // Parámetros:
>    // pcliente         puntero a la matriz de estructuras tcliente.
>    // numClientes      número de clientes existentes.
>    ```
>
>    Valor retornado: ninguno.
>
> 5. Función *LiberarMemoria*. Liberará toda la memoria que se haya asignado du-
>    rante la ejecución del programa. Su prototipo es:
>
>    ```c
>    void LiberarMemoria(tcliente *pcliente, int numClientes);
>
>    // Parámetros:
>    // pcliente         puntero a la matriz de estructuras tcliente.
>    // numClientes      número de clientes existentes.
>    ```
>
>    Valor retornado: ninguno.
>
> [Solución](chapter-07/ejercicio-05.c)

## 08 Más sobre funciones

**Ejercicio 02:**

> Calcular números de Fibonacci. El número de Fibonacci *f(i)*, siendo *i* el número
> de orden (0, 1, 2, 3, ...), es igual al número de Fibonacci *f(i-1)* más el número de
> Fibonacci *f(i-2)*, partiendo de que *f(0)* vale 0 y *f(1)* vale 1.
>
>     f(0) = 0
>     f(1) = 1
>     f(2) = f(1) + f(0)
>     f(3) = f(2) + f(1)
>     ...
>     f(i) = f(i-1) + f(i-2)
>
> Realizar un programa que pregunte: ¿cuántos números de Fibonacci, a partir
> del primero, se quieren calcular?, almacene esos números en una matriz del
> tamaño necesario y finalmente los muestre. Para ello se deberá utilizar una función NO
> RECURSIVA con el prototipo indicado a continuación:
>
> ```c
> int fibonacci(int n);
> ```
>
> La función *fibonacci* devolverá como resultado el número de Fibonacci cuyo
> número de orden (0, 1, 2, ...) sea *n*.
>
> [Solución](chapter-08/ejercicio-02.c)

**Ejercicio 03:**

> Realizar un programa que:
>
> - Lea dos cadenas de caracteres denominadas *cadena1* y *cadena2* y un número
>   entero *n*.
>
> - Llame a una función:
>
>   ```c
>   int compcads(cadena1, cadena2, n);
>   ```
>
>   que compare los *n* primeros caracteres de *cadena1* y de *cadena2* y devuelva
>   como resultado un valor entero (no utilizar **strncmp**):
>
>   Valor|Condición
>   ---:|:---
>   0|si *cadena1* y *cadena2* son iguales.
>   1|si *cadena1* es mayor que *cadena2* (los *n* primeros caracteres).
>   -1|si *cadena1* es menor que *cadena2* (los *n* primeros caracteres).
>
>   Si *n* es menor que 1 o mayor que la longitud de la menor de las cadenas, la
>   comparación se hará sin tener en cuenta este parámetro.
>
> - Escriba la cadena que sea menor según los *n* primeros caracteres (esto es, la
>   que esté antes por orden alfabético).
>
> [Solución](chapter-08/ejercicio-03.c)

**Ejercicio 04:**

> Suponiendo un texto escrito en minúsculas y sin signos de puntuación, es decir,
> una palabra estará separada de otra por un espacio en blanco, realizar un programa
> que lea texto de la entrada estándar (del teclado) y dé como resultado la
> frecuencia con que aparece cada palabra leída del texto. El resultado se almacenará en
> una matriz en la que cada elemento será una estructura del tipo siguiente:
>
> ```c
> typedef struct
> {
>   char *palabra; // palabra
>   int contador;  // número de veces que aparece en el texto
> } telem;
> ```
>
> La estructura del programa estará formada por la función **main** y por las fun-
> ciones siguientes:
>
> ```c
> int BuscarPalabra(telem *a, char *palabra);
> void InsertarPalabra(telem *a, char *palabra);
> void VisualizarMatriz(telem *a);
> ```
>
> La función **main** asignará memoria para una matriz de *n* elementos, iniciará
> los elementos de la matriz a cero, utilizando las funciones anteriores calculará la
> frecuencia con la que aparece cada una de las palabras y visualizará el resultado.
>
> La función *BuscarPalabra* verificará si la palabra leída de la entrada estándar
> está en la matriz a. Esta función devolverá un valor distinto de 0 si la palabra está
> en la matriz y un 0 en caso contrario.
>
> La función *InsertarPalabra* permitirá añadir una nueva palabra al final de la
> matriz a. Tenga en cuenta que cada palabra en la matriz está referenciada por un
> puntero.
>
> La función *VisualizarMatriz* visualizará cada una de las palabras de la ma-
> triz seguida del número de veces que apareció.
>
> [Solución](chapter-08/ejercicio-04.c)

**Ejercicio 05:**

> Modificar el programa anterior para que la función *InsertarPalabra* inserte cada
> nueva palabra en el orden que le corresponde alfabéticamente, moviendo los
> elementos necesarios un lugar hacia atrás. De esta forma, cuando finalice la lectura
> del texto, la matriz estará ordenada.
>
> [Solución](chapter-08/ejercicio-05.c)

**Ejercicio 06:**

> Realizar un programa que lea un conjunto de valores reales a través del teclado,
> los almacene en una matriz dinámica de *m* filas por *n* columnas y, a continuación,
> visualice la matriz por filas.
>
> La estructura del programa estará formada, además de por la función **main**,
> por las funciones siguientes:
>
> ```c
> void Leer(float **m, int fi, int co);
> ```
>
> El parámetro *m* de la función *Leer* hará referencia a la matriz de *fi* filas por *co*
> columnas, cuyos elementos deseamos leer. Esta matriz se creará dinámicamente
> invocando a la función:
>
> ```c
> float **AsigMem(int fi, int co);
> ```
>
> La función *AsigMem* devolverá una matriz de *fi* filas por *co* columnas.
>
> [Solución](chapter-08/ejercicio-06.c)

**Ejercicio 07:**

> Escribir un programa para evaluar la expresión *(ax + by)<sup>n</sup>*. Para ello, tenga en
> cuenta las siguientes expresiones:
>
>     (ax + by)^n = Sumatoria( k = 0, n, Combinatoria( n, k ) * (ax)^(n - k) * (by)^k )
>     Combinatoria( n, k ) = n! / ( k! * (n - k)! )
>     n! = n * (n - 1) * (n - 2) * ... * 2 * 1
>
> - Escribir una función cuyo prototipo sea:
>
>   ```c
>   long factorial(int n);
>   ```
>
>   La función *factorial* recibe como parámetro un entero y devuelve el factorial
>   del mismo.
>
> - Escribir una función con el prototipo:
>
>   ```c
>   long combinaciones(int n, int k);
>   ```
>
>   La función *combinaciones* recibe como parámetros dos enteros, *n* y *k*, y
>   devuelve como resultado el valor de *Combinatoria( n, k )*.
>
> - Escribir una función que tenga el prototipo:
>
>   ```c
>   double potencia(double base, int exponente);
>   ```
>
>   La función *potencia* recibe como parámetros dos enteros, *base* y *exponente*, y
>   devuelve como resultado el valor de *base<sup>exponente</sup>*.
>
> - La función **main** leerá los valores de *a*, *b*, *n*, *x* e *y*, y utilizando las funciones
>   anteriores escribirá como resultado el valor de *(ax + by)<sup>n</sup>*.
>
> [Solución](chapter-08/ejercicio-07.c)

## 09 Trabajar con ficheros

**Ejercicio 02:**
> [Solución](chapter-09/ejercicio-02.c)

## 10 El preprocesador de C

**Ejercicio 02:**
> [Solución](chapter-10/ejercicio-02.c)

## 11 Estructuras dinámicas

**Ejercicio 02:**
> [Solución](chapter-11/ejercicio-02.c)

## 12 Algoritmos

**Ejercicio 02:**
> [Solución](chapter-12/ejercicio-02.c)

[Inicio][Index] - [Arriba][Header]

<!-------------------------------------------------------------------------
 !  Links
-------------------------------------------------------------------------->

[Index]:    ../README.md
[Header]:   #header
