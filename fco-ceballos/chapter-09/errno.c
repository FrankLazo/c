// errno.c
//
#include <stdio.h>
#include <stdlib.h>

// Si no se incluyera stdlib.h
// extern int errno;			// número de error
// extern char *sys_errlist[]; // mensajes de error
// extern int sys_nerr;		// elementos de la matriz sys_errlist

int main( int argc, char *argv[] )
{
	int i;

	for ( i = 0; i < sys_nerr; i++ )
	{
		printf( "Error: %d, %s\n", i, sys_errlist[ i ] );
		getchar();
	}

	return 0;
}
