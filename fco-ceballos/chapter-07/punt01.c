/* Escribir los valores de una matriz.
 * Versión utilizando indexación.
/* punt01.c
 */

#include <stdio.h>

void main()
{
	int lista[] = { 24, 30, 15, 45, 34 };
	int ind;

	for ( ind = 0; ind < 5; ind++ )
		printf( "%d  ", lista[ ind ] );
}
