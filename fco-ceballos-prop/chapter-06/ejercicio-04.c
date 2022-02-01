/* Realizar un programa que lea una cadena de caracteres y la almacene en una ma-
 * triz. A continuación, utilizando una función, deberá convertir los caracteres escri-
 * tos en mayúsculas a minúsculas. Finalmente imprimirá el resultado.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N_CARACTERES 100

void stringToLowerCase( char * );

void main()
{
	char cadena[ N_CARACTERES ];
	int longitud = 0;

	// Presentación
	system( "cls" );
	printf( "Conversion de una cadena de caracteres a minusculas\n" );
	printf( "---------------------------------------------------\n" );

	// Entrada de datos
	printf( "\nIngrese una cadena de caracteres: " );
	gets( cadena );

	// Conversión
	stringToLowerCase( cadena );

	// Salida de datos
	printf( "\n" );
	puts( cadena );

	printf( "\nFin del programa.\n" );
}

void stringToLowerCase( char *cadena )
{
	int contador = 0;

	while ( cadena[ contador ] )
		cadena[ contador++ ] = tolower( cadena[ contador ] );
}
