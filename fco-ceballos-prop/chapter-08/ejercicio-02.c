/* Calcular números de Fibonacci. El número de Fibonacci f(i), siendo i el número
 * de orden (0, 1, 2, 3, ...), es igual al número de Fibonacci f(i-1) más el número de
 * Fibonacci f(i-2), partiendo de que f(0) vale 0 y f(1) vale 1.
 *
 * f(0) = 0
 * f(1) = 1
 * f(2) = f(1) + f(0)
 * f(3) = f(2) + f(1)
 * ...
 * f(i) = f(i-1) + f(i-2)
 *
 * Realizar un programa que pregunte: ¿cuántos números de Fibonacci, a partir
 * del primero, se quieren calcular?, almacene esos números en una matriz del tama-
 * ño necesario y finalmente los muestre. Para ello se deberá utilizar una función NO
 * RECURSIVA con el prototipo indicado a continuación:
 *
 * int fibonacci(int n);
 *
 * La función fibonacci devolverá como resultado el número de Fibonacci cuyo
 * número de orden (0, 1, 2, ...) sea n.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int fibonacci( int n );

int main( int argc, char *argv[] )
{
	int *pFibonacci = NULL;
	int nFibonacci = 0;
	int correcto = 0;
	int i = 0;

	system( "cls" );

	printf( "Numeros de Fibonacci\n" );
	printf( "~~~~~~~~~~~~~~~~~~~~\n" );
	printf( "\n" );

	// Entrada de datos
	do
	{
		printf( "Cuantos numeros de Fibonacci desea calcular (1 - 15)? " );
		correcto = scanf( "%d", &nFibonacci );
		fflush( stdin );
	}
	while ( !correcto || nFibonacci < 1 || nFibonacci > 15 );

	// Asignación de memoria
	pFibonacci = ( int * )malloc( nFibonacci * sizeof( int ) );

	if ( pFibonacci == NULL)
	{
		printf( "Insuficiente memoria. Fin del programa.\n" );
		return -1;
	}

	// Proceso de datos
	for ( i = 0; i < nFibonacci; i++ )
	{
		pFibonacci[ i ] = fibonacci( i + 1 );
	}

	// Salida de datos
	printf( "\n" );

	for ( i = 0; i < nFibonacci; i++ )
	{
		printf( "%d  ", pFibonacci[ i ] );
	}

	// Liberar memoria
	free( pFibonacci );

	return 0;
}

int fibonacci( int n )
{
	int i = 0;
	int auxiliar = 0;
	int fibonacci1 = 0;
	int fibonacci2 = 1;

	if ( n != 1 )
	{
		for ( i = 0; i < n - 2; i++ )
		{
			auxiliar = fibonacci1 + fibonacci2;
			fibonacci1 = fibonacci2;
			fibonacci2 = auxiliar;
		}

		return fibonacci1 + fibonacci2;
	}
	else
		return fibonacci2;
}
