/* Realizar un programa que lea un conjunto de valores reales a través del teclado,
 * los almacene en una matriz dinámica de m filas por n columnas y, a continuación,
 * visualice la matriz por filas.
 *
 * La estructura del programa estará formada, además de por la función main,
 * por las funciones siguientes:
 *
 * void Leer(float **m, int fi, int co);
 *
 * El parámetro m de la función Leer hará referencia a la matriz de fi filas por co
 * columnas, cuyos elementos deseamos leer. Esta matriz se creará dinámicamente
 * invocando a la función:
 *
 * float **AsigMem(int fi, int co);
 *
 * La función AsigMem devolverá una matriz de fi filas por co columnas.
 *
 */

#include <stdio.h>
#include <stdlib.h>

float **AsigMem( int fi, int co );
void Leer( float **m, int fi, int co );
void VisualizarMatriz( float **m, int fi, int co );

int main( int argc, char *argv[] )
{
	int i = 0;
	int filas = 0;
	int columnas = 0;
	int correcto = 0;
	float **pMatriz = NULL;

	system( "cls" );

	printf( "Visualizar una matriz de numeros reales\n" );
	printf( "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	printf( "\n" );

	// Entrada de datos
	do
	{
		printf( "Ingrese el numero de filas de la matriz: " );
		correcto = scanf( "%d", &filas );
		fflush( stdin );
	}

	while ( filas < 1 || !correcto );

	do
	{
		printf( "Ingrese el numero de columnas de la matriz: " );
		correcto = scanf( "%d", &columnas );
		fflush( stdin );
	}
	while ( columnas < 1 || !correcto );

	// Asignar memoria
	pMatriz = AsigMem( filas, columnas );

	if ( pMatriz == NULL )
	{
		printf( "Insuficiente memoria. Fin del programa.\n" );
		return -1;
	}

	// Proceso de datos
	printf( "\n" );
	Leer( pMatriz, filas, columnas );

	// Salida de datos
	printf( "\n" );
	VisualizarMatriz( pMatriz, filas, columnas );

	// Liberar memoria
	for ( i = 0; i < filas; i++ )
		free( pMatriz[ i ] );

	free( pMatriz );

	return 0;
}

float **AsigMem( int fi, int co )
{
	int i = 0;
	float **p = NULL;

	p = ( float ** )malloc( fi * sizeof( float * ) );
	if ( p == NULL ) return NULL;

	for ( i = 0; i < fi; i++ )
	{
		p[ i ] = ( float * )malloc( co * sizeof( float ) );
		if ( p[ i ] == NULL ) return NULL;
	}

	return p;
}

void Leer( float **m, int fi, int co )
{
	int f = 0;
	int c = 0;
	int correcto = 0;

	for ( f = 0; f < fi; f++ )
		for ( c = 0; c < co; c++ )
		{
			do
			{
				printf( "Numero[%d][%d] : ", f, c );
				correcto = scanf( "%f", &m[ f ][ c ] );
				fflush( stdin );
			}
			while ( !correcto );
		}
}

void VisualizarMatriz( float **m, int fi, int co )
{
	int f = 0;
	int c = 0;

	for ( f = 0; f < fi; f++ )
	{
		for ( c = 0; c < co; c++ )
		{
			printf( "%.2f  ", m[ f ][ c ] );
		}

		printf( "\n" );
	}
}
