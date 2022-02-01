/* raiz_cuadrada.c
 */

#include <stdio.h> // necesaria para printf
#include <math.h>  // necesaria para sqrt (raíz cuadrada)

main()
{
	int i = 9;
	double r = 0;
	
	r = sqrt(i/2);
	printf("La ra%cz cuadrada es %g\n", 161, r);
	
	r = sqrt((double)i/2);
	printf("La ra%cz cuadrada es %g\n", 161, r);
}
