/* La mediana de una lista de n números se define como el valor que es menor o
 * igual que los valores correspondientes a la mitad de los números, y mayor o igual
 * que los valores correspondientes a la otra mitad. Por ejemplo, la mediana de:
 *
 * 16 12 99 95 18 87 10
 *
 * es 18, porque este valor es menor que 99, 95, 87 (mitad de los números) y mayor
 * que 16, 12 y 10 (otra mitad).
 *
 * Realizar un programa que lea un número impar de valores y dé como resultado la
 * mediana. La entrada de valores finalizará cuando se detecte la marca de fin de fi-
 * chero.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int esPar( int );
void ordenar( int *, int );

void main()
{
	int valores[ MAX ];
	int contador = 0;
	int controlador;

	// Presentación
	system( "cls" );
	printf( "Hallar la mediana de un conjunto de valores\n" );
	printf( "-------------------------------------------\n" );

	// Entrada de datos
	printf( "\nIngrese una cantidad impar de valores.\n" );
	printf( "\nIngrese un valor: " );

	while ( ( controlador = scanf( "%d", &valores[ contador ] ) ) != EOF || esPar( contador ) )
	{
		if ( controlador == EOF )
		{
			printf( "Es necesario un numero impar de valores.\n" );
			printf( "Ingrese una cantidad impar de valores: " );
		}
		else if ( controlador )
		{
			printf( "Ingrese otro valor: " );
			fflush( stdin );
			contador++;
		}
		else
		{
			printf( "Valor incorrecto.\n" );
			printf( "Ingrese otro valor: " );
		}

		fflush( stdin );
	}

	// Proceso de datos
	ordenar( valores, contador );

	// Salida de datos
	printf( "\n" );
	printf( "La mediana es: %d", valores[ ( contador - 1 ) / 2 ] );
	printf( "\n" );

	printf( "\nFin del programa.\n" );
}

int esPar( int numero )
{
	if ( numero % 2 == 0 )
		return 1;
	else
		return 0;
}

void ordenar( int *numeros, int longitud )
{
	int menor;

	for ( int i = 0; i < longitud; i++ )
	{
		menor = numeros[ i ];

		for ( int j = i + 1; j < longitud; j++ )
		{
			if ( numeros[ j ] < menor )
			{
				numeros[ i ] = numeros[ j ];
				numeros[ j ] = menor;
				menor = numeros[ i ];
			}
		}
	}
}
