// binario-b.c

#include <stdio.h>
#include <string.h>

int main( int argc, char *argv[] )
{
	int n = 0;
	char *s = "¡Hola mundo!\n";
	FILE *pf; // flujo

	// Abrir el fichero
	// pf = fopen( "mifichero-b.bin", "wb" ); // b: fichero binario
	pf = fopen( "mifichero-t.bin", "wt" ); // t: fichero de texto

	// Escribir en el fichero
	fwrite( s, strlen( s ), 1, pf );
	n = 9;        fwrite( &n, sizeof( int ), 1, pf );
	n = 256;      fwrite( &n, sizeof( int ), 1, pf );
	// n = 17432583; fwrite( &n, sizeof( int ), 1, pf );
	n = 17435911; fwrite( &n, sizeof( int ), 1, pf );

	// Cerrar el fichero
	fclose( pf );

	return 0;
}
