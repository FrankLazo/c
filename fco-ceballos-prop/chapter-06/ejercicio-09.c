/* Para almacenar una matriz bidimensional que generalmente tiene muchos elemen-
 * tos nulos (matriz sparse) se puede utilizar una matriz unidimensional en la que só-
 * lo se guarden los elementos no nulos precedidos por sus índices, fila y columna,
 * lo que redunda en un aprovechamiento de espacio. Por ejemplo, la matriz:
 *
 * 6 0 0 0 4
 * 0 5 0 0 2
 * 2 0 0 0 0
 * 0 0 7 0 0
 * 0 0 0 8 0													 +- fila
 * 																 |	 +- columna
 * se guardará en una matriz unidimensional así:				 |	 |	 +- valor
 * 																 ↓	 ↓	 ↓
 * +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
 * | 0 | 0 | 6 | 0 | 4 | 4 | 1 | 1 | 5 | 1 | 4 | 2 | 2 | 0 | 2 | 3 | 2 | 7 | 4 | 3 | 8 |
 * +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
 *
 * Para trabajar con esta matriz utilizaremos la siguiente declaración:
 *
 * typedef int tMatrizU[300];
 *
 * Se pide:
 *
 * a) Escribir una función que lea una matriz bidimensional por filas y la almacene
 *    en una matriz m de tipo tMatrizU. El prototipo de esta función será:
 *
 *    int CrearMatrizUni( tMatrizU m, int fi, int co );
 *
 *    Los parámetros fi y co se corresponden con el número de filas y de columnas
 *    de la supuesta matriz bidimensional.
 *
 * b) Escribir una función que permita representar en pantalla la matriz bidimen-
 *    sional por filas y columnas. El prototipo de esta función será:
 *
 * 	  int Visualizar( int f, int c, tMatrizU m, int n );
 *
 * 	  Los parámetros f y c se corresponden con la fila y la columna del elemento
 *    que se visualiza. El valor del elemento que se visualiza se obtiene, lógicamen-
 *    te, de la matriz unidimensional creada en el apartado a, así: buscamos por los
 *    índices f y c; si se encuentran, la función Visualizar devuelve el valor almace
 *    -nado justamente a continuación; si no se encuentran, entonces devuelve un 0.
 *    El parámetro n indica el número de elementos no nulos de la matriz bidimen-
 *    sional.
 *
 *    Escribir un programa que, utilizando la función CrearMatrizUni, cree una
 *    matriz unidimensional a partir de una supuesta matriz sparse bidimensional y
 *    a continuación, utilizando la función Visualizar, muestre en pantalla la matriz
 *    bidimensional.
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef int tMatrizU[ 300 ];

int CrearMatrizUni( tMatrizU m, int fi, int co );
int Visualizar( int f, int c, tMatrizU m, int n );

int main()
{
	tMatrizU matriz_uni;
	int filas, columnas;
	int elementos;

	system( "cls" );
	printf( "Matriz sparse\n" );
	printf( "-------------\n" );

	printf( "\n" );
	printf( "Ingrese el numero de filas de la matriz: ");
	scanf( "%d", &filas );
	printf( "Ingrese el numero de columnas de la matriz: ");
	scanf( "%d", &columnas );

	elementos = CrearMatrizUni( matriz_uni, filas, columnas );
	Visualizar( filas, columnas, matriz_uni, elementos );
}

int CrearMatrizUni( tMatrizU m, int fi, int co )
{
	int valor;
	int contador = 0;

	for ( int f = 0; f < fi; f++ )
	{
		printf( "\nIngrese los elementos de la fila %d: ", f );

		for ( int c = 0; c < co; c++)
		{
			scanf( "%d", &valor );

			if ( valor )
			{
				m[ contador * 3 ] = f;
				m[ contador * 3 + 1 ] = c;
				m[ contador * 3 + 2 ] = valor;

				contador++;
			}
		}
	}

	return contador;
}

int Visualizar( int f, int c, tMatrizU m, int n )
{
	int elemento = 0;

	if ( f * c > 300 )
		return 0;

	printf( "\n" );

	for ( int i = 0; i < f; i++ )
	{
		for ( int j = 0; j < c; j++ )
		{
			if ( m[ elemento * 3 ] == i && m[ elemento * 3 + 1 ] == j )
			{
				printf( "%d ", m[ elemento * 3 + 2 ] );
				elemento++;
			}
			else
			{
				printf( "0 " );
			}
		}

		printf( "\n" );
	}

	return 1;
}
