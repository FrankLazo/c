/* Analice el programa que se muestra a continuación e indique el significado que
 * tiene el resultado que se obtiene.
 *
 */

#include <stdio.h>
#include <stdlib.h>

void Visualizar( unsigned char c );
unsigned char fnxxx( unsigned char c );

void main()
{
	unsigned char c;

	system( "cls" );

	printf( "Introducir un caracter: " );
	c = getchar();
	Visualizar( c );

	printf( "\nCaracter resultante:\n" );
	c = fnxxx( c );
	Visualizar( c );
}

void Visualizar( unsigned char c )
{
	int i = 0;
	for ( i = 7; i >= 0; i-- )
		printf( "%d", ( c & ( 1 << i ) ) ? 1 : 0 );
	printf( "\n" );
}

unsigned char fnxxx( unsigned char c )
{
	return ( ( ( c & 0x01 ) << 7 ) | ( ( c & 0x02 ) << 5 ) |
			 ( ( c & 0x04 ) << 3 ) | ( ( c & 0x08 ) << 1 ) |
			 ( ( c & 0x10 ) >> 1 ) | ( ( c & 0x20 ) >> 3 ) |
			 ( ( c & 0x40 ) >> 5 ) | ( ( c & 0x80 ) >> 7 ) );
}

// Respuesta. Muestra los bits del carácter y su respectiva inversión.
