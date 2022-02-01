/* Realizar un programa que lea una cadena de caracteres e imprima el resultado que
 * se obtiene cada vez que se realice una rotación de un carácter a la derecha sobre
 * dicha cadena. El proceso finalizará cuando se haya obtenido nuevamente la cade-
 * na de caracteres original. Por ejemplo:
 *
 * HOLA AHOL LAHO OLAH HOLA
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define N_CARACTERES 100

void main()
{
	char cadena[ N_CARACTERES ];
	int longitud = 0;

	// Presentación
	system( "cls" );
	printf( "Rotacion de una cadena de caracteres\n" );
	printf( "------------------------------------\n" );

	// Entrada de datos
	printf( "\nIngrese una cadena de caracteres: " );
	gets( cadena );

	// Número de caracteres ingresados
	while ( cadena[ longitud ] )
	{
		longitud++;
	}

	// Salida de datos
	printf( "\n" );

	for ( int i = longitud; i >= 0; i-- )
	{
		for ( int j = i; j < longitud + i; j++ )
			printf( "%c", cadena[ j % longitud ] );

		printf( " " );
	}

	printf( "\n" );
	printf( "\nFin del programa.\n" );
}
