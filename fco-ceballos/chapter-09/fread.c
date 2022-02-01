/*** Leer datos de un fichero registro a registro ***/
/* fread.c
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char nombre[ 40 ];
	char direccion[ 40 ];
	long telefono;
} registro; // tipo registro

int existe( char *nombreFichero );
void mostrarFichero( char *nombreFichero );

int main( int argc, char *argv[] )
{
	char nombreFichero[ 30 ]; // nombre del fichero

	// Solicitar el nombre del fichero
	printf( "Nombre del fichero: " );
	gets( nombreFichero );

	// Verificar si el fichero existe
	if ( existe( nombreFichero ) )
		mostrarFichero( nombreFichero );
	else
		printf( "El fichero no existe." );

	return 0;
}

int existe( char *nombreFichero )
{
	FILE *pf = NULL;

	// Verificar si el fichero existe
	int exis = 0; // no existe

	if ( ( pf = fopen( nombreFichero, "r" ) ) != NULL )
	{
		exis = 1; // existe
		fclose( pf );
	}

	return exis;
}

void mostrarFichero( char *nombreFichero )
{
	FILE *pf = NULL;	// identificador del fichero
	registro reg;		// definir un registro

	// Abrir el fichero nombreFichero para leer "r"
	if ( ( pf = fopen( nombreFichero, "rb" ) ) == NULL )
	{
		printf( "El fichero no puede abrirse." );
		exit( 1 );
	}

	// Leer datos del fichero y mostrarlos en la salida estándar
	fread( &reg, sizeof( reg ), 1, pf );

	while ( !ferror( pf ) && !feof( pf ) )
	{
		system( "cls" ); // limpiar la pantalla

		printf( "Nombre:    %s\n", reg.nombre );
		printf( "Direccion: %s\n", reg.direccion );
		printf( "Telefono:  %ld\n\n", reg.telefono );

		// Hacer una pausa
		printf( "Pulse <Entrar> para continuar " );
		getchar();
		fflush( stdin );

		// Leer el siguiente registro del fichero
		fread( &reg, sizeof( reg ), 1, pf );
	}

	if ( ferror( pf ) )
		perror( "Error durante la lectura" );

	fclose( pf );
}
