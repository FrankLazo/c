/* Escribir un programa que utilice una función para leer una línea de la entrada y dé
 * como resultado la línea leída y su longitud o número de caracteres.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define N_CARACTERES 200

int obtenerNumeroCaracteres( char * );

void main()
{
	char cadena[ N_CARACTERES ];
	int caracteres;

	// Presentación
	system( "cls" );
	printf( "Leer una linea y mostrar su numero de caracteres\n" );
	printf( "------------------------------------------------\n" );

	// Entrada de datos
	printf( "\nEscriba una linea de texto." );
	printf( "\nPara finalizar presione <Enter>.\n\n" );

	gets( cadena );

	// Proceso de datos
	caracteres = obtenerNumeroCaracteres( cadena );

	// Salida de datos
	printf( "\n" );
	printf( "El numero de caracteres de la cadena leida es: %d\n", caracteres );

	printf( "\nFin del programa.\n" );
}

int obtenerNumeroCaracteres( char *cadena )
{
	int contador = 0;

	while ( cadena[ contador ] )
	{
		contador++;
	}

	return contador;
}
