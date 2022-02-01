/* Realizar un programa que:
 *
 * a) Lea dos cadenas de caracteres denominadas cadena1 y cadena2 y un número
 *    entero n.
 *
 * b) Llame a una función:
 *
 *    int compcads(cadena1, cadena2, n);
 *
 *    que compare los n primeros caracteres de cadena1 y de cadena2 y devuelva
 *    como resultado un valor entero (no utilizar strncmp):
 *
 *    0   si cadena1 y cadena2 son iguales.
 *    1   si cadena1 es mayor que cadena2 (los n primeros caracteres).
 *    -1  si cadena1 es menor que cadena2 (los n primeros caracteres).
 *
 *    Si n es menor que 1 o mayor que la longitud de la menor de las cadenas, la
 *    comparación se hará sin tener en cuenta este parámetro.
 *
 * c) Escriba la cadena que sea menor según los n primeros caracteres (esto es, la
 *    que esté antes por orden alfabético).
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 81

int compcads( char *cadena1, char *cadena2, int n );

int main( int argc, char *argv[] )
{
	int correcto = 0;
	int resultado = 0;
	int nCaracteres = 0;
	char cadena[ MAX ];
	char *pCadena1 = NULL;
	char *pCadena2 = NULL;

	system( "cls" );

	printf( "Comparacion de cadenas\n" );
	printf( "~~~~~~~~~~~~~~~~~~~~~~\n" );
	printf( "\n" );

	// Entrada de datos
	do
	{
		printf( "Escriba la primera cadena:\n\n" );
	}
	while ( !strlen( gets( cadena ) ) );

	// Asignación de memoria
	pCadena1 = ( char * )malloc( ( strlen( cadena ) + 1 ) * sizeof( char ) );

	if ( pCadena1 == NULL)
	{
		printf( "Insuficiente memoria. Fin del programa.\n" );
		return -1;
	}

	strcpy( pCadena1, cadena );

	// Entrada de datos
	do
	{
		printf( "\nEscriba la segunda cadena:\n\n" );
	}
	while ( !strlen( gets( cadena ) ) );

	// Asignación de memoria
	pCadena2 = ( char * )malloc( ( strlen( cadena ) + 1 ) * sizeof( char ) );

	if ( pCadena2 == NULL)
	{
		printf( "Insuficiente memoria. Fin del programa.\n" );
		return -1;
	}

	strcpy( pCadena2, cadena );

	do
	{
		printf( "\nCuantos caracteres desea comparar? " );
	}
	while ( !( correcto = scanf( "%d", &nCaracteres ) ) );

	// Proceso de datos
	resultado = compcads( pCadena1, pCadena2, nCaracteres );

	// Salida de datos
	printf( "\n" );

	switch ( resultado )
	{
		case 0:
			printf( "Las cadenas son iguales en los %d primeros caracteres.\n", nCaracteres );
			break;

		case 1:
			printf( "La cadena \"%s\" es menor", pCadena2 );
			if ( strlen( pCadena2 ) >= nCaracteres && nCaracteres > 0 && strlen( pCadena2 ) < strlen( pCadena1 ) )
				printf( " en los %d primeros caracteres.\n", nCaracteres );
			else
				printf( ".\n" );
			break;

		case -1:
			printf( "La cadena \"%s\" es menor", pCadena1 );
			if ( strlen( pCadena1 ) >= nCaracteres && nCaracteres > 0 && strlen( pCadena1 ) < strlen( pCadena2 ) )
				printf( " en los %d primeros caracteres.\n", nCaracteres );
			else
				printf( ".\n" );
			break;

		default:
			break;
	}

	// Liberar memoria
	free( pCadena1 );
	free( pCadena2 );

	return 0;
}

int compcads( char *cadena1, char *cadena2, int n )
{
	int i = 0;
	int menor = ( strlen( cadena1 ) > strlen( cadena2 ) ) ? strlen( cadena1 ) : strlen( cadena2 );

	if ( n < 1 || n > menor )
	{
		if( strcmp( cadena1, cadena2 ) > 0 ) return 1;
		if( strcmp( cadena1, cadena2 ) < 0 ) return -1;
		return 0;
	}
	else
	{
		for ( i = 0; i < n; i++ )
		{
			if ( tolower( cadena1[ i ] ) > tolower( cadena2[ i ] ) ) return 1;
			if ( tolower( cadena1[ i ] ) < tolower( cadena2[ i ] ) ) return -1;
		}

		return 0;
	}
}
