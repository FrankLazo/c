/* Un cuadrado mágico se compone de números enteros comprendidos entre 1 y n^2,
 * donde n es un número impar que indica el orden de la matriz cuadrada que contie-
 * ne los números que forman dicho cuadrado mágico. La matriz que forma este
 * cuadrado mágico cumple que la suma de los valores que componen cada fila, cada
 * columna y cada diagonal es la misma. Por ejemplo, un cuadrado mágico de orden
 * 3, n = 3, implica una matriz de 3 por 3. Por lo tanto, los valores de la matriz es-
 * tarán comprendidos entre 1 y 9 y dispuestos de la siguiente forma:
 *
 * 								8  1  6
 * 								3  5  7
 * 								4  9  2
 *
 * Realizar un programa que visualice un cuadrado mágico de orden impar n. El
 * programa verificará que n es impar y está comprendido entre 3 y 15.
 *
 * Una forma de construirlo consiste en situar el número 1 en el centro de la
 * primera línea, el número siguiente en la casilla situada encima y a la derecha, y así
 * sucesivamente. Es preciso tener en cuenta que el cuadrado se cierra sobre sí mis-
 * mo; esto es, la línea encima de la primera es la última y la columna a la derecha
 * de la última es la primera. Siguiendo esta regla, cuando el número caiga en una
 * casilla ocupada, se elige la casilla situada debajo del último número situado.
 *
 * Se deberán realizar al menos las siguientes funciones:
 *
 * a) Es_impar. Esta función verificará si n es impar.
 * b) Cuadrado_magico. Esta función construirá el cuadrado mágico.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15
#define MIN 3

int Es_impar( int );
int **Cuadrado_magico( int );
void VisualizarCuadrado( int **, int );

int main()
{
	int f = 0;
    int correcto = 0;
    int nCuadrado = 0;
	int **pCuadrado = NULL;

    system( "cls" );

    printf( "Cuadrado Magico\n" );
    printf( "===============\n" );

    // Entrada de datos
    do
    {
        printf( "\nIngrese un numero impar entre 3 y 15: " );
        correcto = scanf( "%d", &nCuadrado );
		fflush( stdin );
    }
    while ( !correcto || nCuadrado < MIN || nCuadrado > MAX || !Es_impar( nCuadrado ) );

	// Proceso de datos
	pCuadrado = Cuadrado_magico( nCuadrado );

	// Salida de datos
	VisualizarCuadrado( pCuadrado, nCuadrado );

    // Liberar memoria
	for ( f = 0; f < nCuadrado; f++ )
    	free( pCuadrado[ f ] );

	free( pCuadrado );

    return 0;
}

int Es_impar( int numero )
{
	if ( numero % 2 ) return 1;
	else return 0;
}

int **Cuadrado_magico( int n )
{
	int f = 0;
	int c = 0;
	int fPrev = 0;
	int cPrev = 0;
	int **p = NULL;
	int valorActual = 1;

	// Asignar memoria
	if ( ( p = ( int ** )malloc( n * sizeof( int * ) ) ) == NULL ) return NULL;

	for ( f = 0; f < n; f++ )
	{
		if ( ( p[ f ] = ( int * )malloc( n * sizeof( int ) ) ) == NULL ) return NULL;
	}

	// Iniciar valores a cero
	for ( f = 0; f < n; f++ )
	{
		memset( p[ f ], 0, n * sizeof( int ) );
	}

	// Añadir valores al cuadrado
	f = 0;
	c = ( n - 1 ) / 2;

	p[ f ][ c ] = valorActual;

	for ( valorActual = 2; valorActual <= n * n; valorActual++ )
	{
		fPrev = f;
		cPrev = c;

		f = ( f + n - 1 ) % n;
		c = ( c + 1 ) % n;

		if ( p[ f ][ c ] )
		{
			f = ( fPrev + 1 ) % n;
			c = cPrev;
		}

		p[ f ][ c ] = valorActual;
	}

	return p;
}

void VisualizarCuadrado( int **pCuadrado, int n )
{
	int f = 0;
	int c = 0;

	printf( "\n" );

	for ( f = 0; f < n; f++ )
	{
		for ( c = 0; c < n; c++ )
			printf( "%4d ", pCuadrado[ f ][ c ] );

		printf( "\n" );
	}

	printf( "\n" );
}
