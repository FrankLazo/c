// perror.c
//
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] )
{
	FILE *pf;
	char *cadena = "Esta cadena nunca será escrita";

	if ( ( pf = fopen( "datos", "r" ) ) == NULL )
	{
		perror( "datos" );
		exit( 1 );
	}

	fprintf( pf, "%s\n", cadena );

	if ( ferror( pf ) )
	{
		perror( "Error al escribir en el fichero" );
		clearerr( pf );
	}

	fclose( pf );

	return 0;
}
