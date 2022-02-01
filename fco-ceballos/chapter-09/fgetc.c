/****** Leer datos de un fichero carácter a carácter ******/
/* fgetc.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char *argv[] )
{
	FILE *pf = NULL;
	char buffer[ 81 ];
	int i = 0;

	// Abrir el fichero "texto" para leer
	if ( ( pf = fopen( "texto", "r" ) ) == NULL )
	{
		perror( "El fichero no se puede abrir" );
		exit( 1 );
	}

	while ( !ferror( pf ) && !feof( pf ) )
		buffer[ i++ ] = fgetc( pf );

	buffer[ --i ] = '\0';

	if ( ferror( pf ) )
		perror( "Error durante la lectura" );

	fclose( pf );

	return 0;
}
