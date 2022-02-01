/* Escriba un programa que visualice el resultado de la expresión:
 *
 * (b^2 - 4ac) / 2a
 *
 * para valores de a = 1, b = 5 y c = 2.
 */

#include <stdio.h>

main()
{	
	int a = 1, b = 5, c = 2;
	double resultado = (b*b - 4*a*c) / 2.0;

	printf("El resultado es: %g\n", resultado);
}
