/* Realizar un programa que permita utilizar el terminal como un diccionario Inglés-
 * Español; esto es, al introducir una palabra en inglés, se escribirá la correspondien-
 * te palabra en español. El número de parejas de palabras es variable, pero limitado
 * a un máximo de 100. La longitud máxima de cada palabra será de 40 caracteres.
 * Como ejemplo, supongamos que introducimos las siguientes parejas de palabras:
 *
 * book      libro
 * green     verde
 * mouse     ratón
 *
 * Una vez finalizada la introducción de la lista, pasamos al modo traducción, de
 * forma que si tecleamos green, la respuesta ha de ser verde. Si la palabra no se en-
 * cuentra, se emitirá un mensaje que lo indique.
 *
 * El programa constará al menos de dos funciones:
 *
 * a) CrearDiccionario. Esta función creará el diccionario.
 *
 * b) Traducir. Esta función realizará la labor de traducción.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAREJAS 100
#define MAX_CADENA  40

typedef struct
{
    char *eng;
    char *esp;
} tPareja;

tPareja **CrearDiccionario( int );
char *Traducir( char *, tPareja **, int );

int main()
{
    int p = 0;
    int nFilas = 0;
    int correcto = 0;
	char cadena[ MAX_CADENA ];
	char *pTraducida = NULL;
    tPareja **pDiccionario = NULL;

    system( "cls" );

    printf( "Diccionario ingles-espagnol\n" );
    printf( "===========================\n" );

    // Entrada de datos
    do
    {
        printf( "\nIntroduzca el numero de palabras a registrar: " );
        correcto = scanf( "%d", &nFilas );
		fflush( stdin );
    }
    while ( !correcto || nFilas < 1 || nFilas > MAX_PAREJAS );

	// Registro de palabras
    if ( ( pDiccionario = CrearDiccionario( nFilas ) ) == NULL )
    {
        printf( "\nEspacio insuficiente en memoria.\n" );
        return -1;
    }

	printf( "\nEscriba el termino a traducir: " );
	printf( "\nPara terminar presione solo <Enter>.\n\n" );

	// Proceso de datos
	while ( strlen( gets( cadena ) ) > 0 )
	{
		pTraducida = Traducir( cadena, pDiccionario, nFilas );
		printf( "%s\n\n", pTraducida );
	}

    // Liberar memoria
    for ( p = 0; p < nFilas; p++ )
    {
        free( pDiccionario[ p ]->eng );
        free( pDiccionario[ p ]->esp );
        free( pDiccionario[ p ] );
    }

    free( pDiccionario );

    return 0;
}

tPareja **CrearDiccionario( int nPalabras )
{
    char cadena[ MAX_CADENA ];
    tPareja **pParejas = NULL;
    int longitud = 0;
    int contador = 0;
    int eng = 1;
    int p = 0;

    if ( ( pParejas = ( tPareja ** )malloc( nPalabras * sizeof( tPareja * ) ) ) == NULL )
    {
        return NULL;
    }

    for ( p = 0; p < nPalabras; p++ )
    {
        if ( ( pParejas[ p ] = ( tPareja * )malloc( sizeof( tPareja ) ) ) == NULL ) return NULL;
    }

    printf( "\n" );
    printf( "Introduzca primero la palabra en ingles y a continuacion en espagnol.\n" );
    printf( "Presionar <Enter> para aceptar el ingreso de cada palabra.\n" );
    printf( "Para terminar pulse solo <Enter>.\n\n" );

    do
    {
		longitud = strlen( gets( cadena ) );

        if ( longitud && eng )
        {
            pParejas[ contador ]->eng = ( char * )malloc( longitud * sizeof( char ) + 1 );
			strcpy( pParejas[ contador ]->eng, cadena );

            if ( pParejas[ contador ]->eng == NULL ) return NULL;

            eng = 0;
        }
        else if ( longitud && !eng )
        {
            pParejas[ contador ]->esp = ( char * )malloc( longitud * sizeof( char ) + 1 );
			strcpy( pParejas[ contador ]->esp, cadena );

            if ( pParejas[ contador ]->esp == NULL ) return NULL;

            eng = 1;
			contador++;
			printf( "\n" );
        }
    }
    while ( ( ( longitud > 0 ) && ( contador < nPalabras ) ) || !eng );

    return pParejas;
}

char *Traducir( char *palabra, tPareja **pDiccionario, int nPalabras )
{
	int p = 0;
	char *pTraducida = NULL;

	for ( p = 0; p < nPalabras; p++ )
	{
		if ( strcmp( pDiccionario[ p ]->eng, palabra) == 0 )
		{
			pTraducida = pDiccionario[ p ]->esp;
			return pTraducida;
		}
	}

	return "Termino no encontrado";
}
