/* Escriba un programa que calcule la suma y la media de cuatro valores de tipo int.
 */

#include <stdio.h>

main()
{	
	int a = 1, b = 2, c = 3, d = 4;
	int suma = a + b + c + d;
	double media = suma/4.0;
	
	printf("La suma es: \t%d\n", suma);
	printf("La media es: \t%g\n", media);
}
