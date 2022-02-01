/* Se define la función f(t) como:
 *
 *        +-
 *        | ∫e^(-t^2)dt si t>=0
 * f(t) = |
 *        |      0      si t<0
 *        +-
 *
 * Se pide escribir un programa que nos permita evaluar f(t). Para ello se reali-
 * zarán los siguientes pasos:
 *
 * a) Escribir una función que permita evaluar el integrando e^(-t^2). El prototipo de
 *    esta función será así:
 *
 *    double f(double t);
 *
 *    Para implementar esta función se aconseja utilizar la función exp(t), que per-
 *    mite evaluar e^t y que se encuentra declarada en el fichero de cabecera math.h
 *    así:
 *
 * 	  double exp(double t);
 *
 * b) Escribir una función que genere números seudoaleatorios dentro de un deter-
 *    minado rango. El prototipo de esta función será así:
 *
 *    double rnd(long &r);
 *
 *    La función rnd, cada vez que se invoque, generará un número seudoaleatorio
 *    comprendido entre 0 y t.
 *
 * c) Escribir un programa que pida un valor de t y utilizando las funciones anterio-
 *    res calcule f(t).
 *
 *    * La función e^(-t^2) es positiva monótona decreciente. En 0 vale 1 y tiende a 0
 *      cuando t crece. La primitiva de esta función, no se conoce.
 *
 *          e^(-t^2) |
 *                   |
 *                 1 +-------------------------------------------
 *                   |*
 *                   |*
 *                   | *
 *                   |   *
 *                   |       *
 *                   |             *
 *                   |                           *            *
 *                 --+-------------------------------------------
 *                 0 |                                          t
 *
 *
 * 	  * La forma de solucionar este problema es análoga al cálculo del volumen
 * 		de una esfera realizado en el apartado Ejercicios resueltos.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N_PRUEBAS 1000

double f( double t );
double rnd( long *r );

int main()
{
	int p = 0;
	int correcto = 0;
	int contador = 0;
	double x = 0.0;
	double y = 0.0;
	double t = 0.0;
	long random = time( NULL ) % 65536;

	system( "cls" );

	do
	{
		printf( "Ingrese un valor para t: " );
		correcto = scanf( "%lf", &t );
		fflush( stdin );
	}
	while ( !correcto );

	for ( p = 0; p < N_PRUEBAS; p++ )
	{
		x = rnd( &random ) * t;
		y = rnd( &random );

		if ( y <= f( x ) ) contador++;
	}

	printf( "El area bajo la grafica es: %g", t * ( ( double )contador / N_PRUEBAS ) );

    return 0;
}

double f( double t )
{
	double aux = 0.0;

	aux = t * t;
	aux = -aux;
	aux = exp( aux );

	return aux;
}

// Parece no haber una distribución regular de números aleatorios
// Para valores de t altos, tienden a salir resultados muy alejados del buscado

double rnd( long *r )
{
	*r = ( 25173 * *r + 13849 ) % 65536;

	return ( ( double )*r / 65535 );
}
