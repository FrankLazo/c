/* Suponiendo un texto escrito en minúsculas y sin signos de puntuación, es decir,
 * una palabra estará separada de otra por un espacio en blanco, realizar un programa
 * que lea texto de la entrada estándar (del teclado) y dé como resultado la frecuen-
 * cia con que aparece cada palabra leída del texto. El resultado se almacenará en
 * una matriz en la que cada elemento será una estructura del tipo siguiente:
 *
 * typedef struct
 * {
 *   char *palabra; // palabra
 *   int contador;  // número de veces que aparece en el texto
 * } telem;
 *
 * La estructura del programa estará formada por la función main y por las fun-
 * ciones siguientes:
 *
 * int BuscarPalabra(telem *a, char *palabra);
 * void InsertarPalabra(telem *a, char *palabra);
 * void VisualizarMatriz(telem *a);
 *
 * La función main asignará memoria para una matriz de n elementos, iniciará
 * los elementos de la matriz a cero, utilizando las funciones anteriores calculará la
 * frecuencia con la que aparece cada una de las palabras y visualizará el resultado.
 *
 * La función BuscarPalabra verificará si la palabra leída de la entrada estándar
 * está en la matriz a. Esta función devolverá un valor distinto de 0 si la palabra está
 * en la matriz y un 0 en caso contrario.
 *
 * La función InsertarPalabra permitirá añadir una nueva palabra al final de la
 * matriz a. Tenga en cuenta que cada palabra en la matriz está referenciada por un
 * puntero.
 *
 * La función VisualizarMatriz visualizará cada una de las palabras de la ma-
 * triz seguida del número de veces que apareció.
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
	int posicion = nPalabras - 1;

	a[ posicion ].palabra = ( char * )malloc( ( strlen( palabra ) + 1 ) * sizeof( char ) );

	if ( a[ posicion ].palabra == NULL )
	{
		printf( "Insuficiente memoria. Fin del programa.\n" );
		exit( -1 );
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
