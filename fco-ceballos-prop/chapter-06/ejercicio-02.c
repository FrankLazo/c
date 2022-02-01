/* Se desea realizar un histograma con los pesos de los alumnos de un determinado
 * curso.
 *
 * Peso      Numero de alumnos
 * ---------------------------
 *  21		 **
 *  22		 ****
 *  23       ***************
 *  24		 ******
 *  ..		 ...
 *
 * El número de asteriscos se corresponde con el número de alumnos del peso espe-
 * cificado.
 *
 * Realizar un programa que lea los pesos e imprima el histograma correspondiente.
 * Suponer que los pesos están comprendidos entre los valores 10 y 100 Kg. En el
 * histograma sólo aparecerán los pesos que se corresponden con uno o más alum-
 * nos.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define PESO_MAX 100
#define PESO_MIN 10

void main()
{
	int peso_alumnos[ PESO_MAX - PESO_MIN ];
	int numero_alumnos = 1;
	int peso;

	// Inicializar matriz
	for ( int i = 0; i < PESO_MAX - PESO_MIN; i++ )
		peso_alumnos[ i ] = 0;

	// Presentación
	system( "cls" );
	printf( "Histograma del peso de los alumnos de un curso\n" );
	printf( "----------------------------------------------\n" );
	printf( "\n(Para terminar de ingresar datos presione <Ctrl + Z>)\n\n" );
	printf( "Peso de alumno %d: ", numero_alumnos );

	// Entrada de datos
	while ( scanf( "%d", &peso ) != EOF )
	{
		if ( peso > PESO_MAX || peso < PESO_MIN )
		{
			printf( "Peso fuera de rango. Ingrese un nuevo peso: " );
		}
		else
		{
			peso_alumnos[ peso - PESO_MIN ]++;
			numero_alumnos++;
			printf( "Peso de alumno %d: ", numero_alumnos );
		}
	}

	// Salida de datos
	printf( "\n" );
	printf( "Peso      Numero de alumnos\n" );
	printf( "---------------------------\n" );

	for ( int i = 0; i < PESO_MAX - PESO_MIN; i++ )
	{
		if ( peso_alumnos[ i ] )
		{
			printf( "%3d", i + PESO_MIN );
			printf( "       " );

			for ( int j = 0; j < peso_alumnos[ i ]; j++ )
				printf( "*" );

			printf( "\n" );
		}
	}

	printf( "\nFin del programa.\n" );
}
