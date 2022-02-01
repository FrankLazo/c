/* Escribir un programa para evaluar la expresión (ax + by)^n. Para ello, tenga en
 * cuenta las siguientes expresiones:
 *
 * (ax + by)^n = Sumatoria( k = 0, n, Combinatoria( n, k ) * (ax)^(n - k) * (by)^k )
 * Combinatoria( n, k ) = n! / ( k! * (n - k)! )
 * n! = n * (n - 1) * (n - 2) * ... * 2 * 1
 *
 * a) Escribir una función cuyo prototipo sea:
 *
 *    long factorial(int n);
 *
 *    La función factorial recibe como parámetro un entero y devuelve el factorial
 *    del mismo.
 *
 * b) Escribir una función con el prototipo:
 *
 *    long combinaciones(int n, int k);
 *
 *    La función combinaciones recibe como parámetros dos enteros, n y k, y de-
 *    vuelve como resultado el valor de Combinatoria( n, k ).
 *
 * c) Escribir una función que tenga el prototipo:
 *
 *    double potencia(double base, int exponente);
 *
 *    La función potencia recibe como parámetros dos enteros, base y exponente, y
 *    devuelve como resultado el valor de base^exponente.
 *
 * d) La función main leerá los valores de a, b, n, x e y, y utilizando las funciones
 *    anteriores escribirá como resultado el valor de (ax + by)^n.
 *
 */

#include <stdio.h>
#include <stdlib.h>

long factorial( int n );
long combinaciones( int n, int k );
double potencia( double base, int exponente );

int main( int argc, char *argv[] )
{
	int k = 0;
	int n = 0;
	double a = 0;
	double b = 0;
	double x = 0;
	double y = 0;
	double sumatoria = 0;
	int correcto = 0;

	system( "cls" );

	printf( "Evaluar la expresion (ax + by)^n\n" );
	printf( "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	printf( "\n" );

	// Entrada de datos
	do
	{
		printf( "Ingrese el valor de a: " );
		correcto = scanf( "%lf", &a );
		fflush( stdin );
	}
	while ( !correcto );

	do
	{
		printf( "Ingrese el valor de b: " );
		correcto = scanf( "%lf", &b );
		fflush( stdin );
	}
	while ( !correcto );

	do
	{
		printf( "Ingrese el valor de n: " );
		correcto = scanf( "%d", &n );
		fflush( stdin );
	}
	while ( n < 0 || !correcto );

	do
	{
		printf( "Ingrese el valor de x: " );
		correcto = scanf( "%lf", &x );
		fflush( stdin );
	}
	while ( !correcto );

	do
	{
		printf( "Ingrese el valor de y: " );
		correcto = scanf( "%lf", &y );
		fflush( stdin );
	}
	while ( !correcto );

	// Proceso de datos
	for ( k = 0; k <= n; k++ )
		sumatoria += combinaciones( n, k ) * potencia( a * x, n - k ) * potencia( b * y, k );

	// Salida de datos
	printf( "\n" );
	printf( "El resultado de la expresion es: %g\n", sumatoria );

	return 0;
}

long factorial( int n )
{
	int f = 0;
	long factorial = 1;

	for ( f = 1; f <= n; f++ )
		factorial *= f;

	return factorial;
}

long combinaciones( int n, int k )
{
	return factorial( n ) / ( factorial( k ) * factorial( n - k ) );
}

double potencia( double base, int exponente )
{
	int e = 0;
	double potencia = 1;

	for ( e = 0; e < exponente; e++ )
		potencia *= base;

	return potencia;
}
