/* Modificar el programa anterior para que la función InsertarPalabra inserte cada
 * nueva palabra en el orden que le corresponde alfabéticamente, moviendo los ele-
 * mentos necesarios un lugar hacia atrás. De esta forma, cuando finalice la lectura
 * del texto, la matriz estará ordenada.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SI 1
#define NO 0
#define MAX 41

typedef struct
{
  	char *palabra;
  	int contador;
} telem;

unsigned int nPalabras = 0;

int BuscarPalabra( telem *a, char *palabra );
void InsertarPalabra( telem *a, char *palabra );
void VisualizarMatriz( telem *a );

int main( int argc, char *argv[] )
{
	char caracter;
	char cadena[ MAX ];
	unsigned int i = 0;
	unsigned int salir = NO;
	unsigned int palabra = NO;
	telem *pMatriz = NULL;

	memset( cadena, '\0', MAX );

	system( "cls" );

	printf( "Frecuencia de palabras en un texto\n" );
	printf( "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	printf( "\n" );

	printf( "Inserte su texto. Para aceptar, presione <Enter> dos veces:\n\n" );

	// Entrada de datos
	while ( ( caracter = getchar() ) != '\n' || !salir )
    {
		salir = NO;

        if ( caracter == ' ' || caracter == '\t' || caracter == '\n' )
		{
			if ( palabra && !BuscarPalabra( pMatriz, cadena ) )
			{
				nPalabras++;
				pMatriz = ( telem * )realloc( pMatriz, sizeof( telem ) * nPalabras );

				if ( pMatriz == NULL )
				{
					printf( "Insuficiente memoria. Fin del programa.\n" );
					return -1;
				}

				InsertarPalabra( pMatriz, cadena );
			}

			memset( cadena, '\0', MAX );
            palabra = NO;
			i = 0;
		}
        else
        {
			cadena[ i ] = caracter;
            palabra = SI;
			i++;
        }

        if ( caracter == '\n' ) salir = SI;
    }

	// Salida de datos
	VisualizarMatriz( pMatriz );

	// Liberar memoria
	for ( i = 0; i < nPalabras; i++ )
		free( pMatriz[ i ].palabra );

	free( pMatriz );

	return 0;
}

int BuscarPalabra( telem *a, char *palabra )
{
	int i = 0;

	if ( a == NULL ) return 0;

	for ( i = 0; i < nPalabras; i++ )
	{
		if ( !strcmp( a[ i ].palabra, palabra ) )
		{
			a[ i ].contador++;
			return a[ i ].contador;
		}
	}

	return 0;
}

void InsertarPalabra( telem *a, char *palabra )
{
	int i = 0;
	int j = 0;
	int posicion = nPalabras - 1;
	char *aux = NULL;

	a[ posicion ].palabra = ( char * )malloc( ( strlen( palabra ) + 1 ) * sizeof( char ) );

	if ( a[ posicion ].palabra == NULL )
	{
		printf( "Insuficiente memoria. Fin del programa.\n" );
		exit( -1 );
	}

	strcpy( a[ posicion ].palabra, palabra );
	aux = a[ posicion ].palabra;

	for ( i = 0; i < nPalabras - 1; i++ )
	{
		if ( strcmp( palabra, a[ i ].palabra ) < 0 )
		{
			for ( j = nPalabras - 1; j > i; j-- )
			{
				a[ j ].palabra = a[ j - 1 ].palabra;
				a[ j ].contador = a[ j - 1 ].contador;
			}

			a[ i ].palabra = aux;
			a[ i ].contador = 1;

			return;
		}
	}

	strcpy( a[ posicion ].palabra, palabra );
	a[ posicion ].contador = 1;
}

void VisualizarMatriz( telem *a )
{
	int i = 0;

	for ( i = 0; i < nPalabras; i++ )
		printf( "%-20s : %d\n", a[ i ].palabra, a[ i ].contador );
}
