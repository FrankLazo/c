// crlf-t.c

#include <stdio.h>

int main( int argc, char *argv[] )
{
	FILE *pf; // flujo

	// Abrir el fichero
	// pf = fopen( "mifichero-t.txt", "wt" ); // w: write, t: fichero de texto
	pf = fopen( "mifichero-b.txt", "wb" ); // w: write, t: fichero binario

	// Escribir en el fichero
	fprintf( pf, "¡Hola mundo!\n" );
	fprintf( pf, "%d * %d = %d\n", 9, 256, 9 * 256 );

	// Cerrar el fichero
	fclose( pf );

	return 0;
}
