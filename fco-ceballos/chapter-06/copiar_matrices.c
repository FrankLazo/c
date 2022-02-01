/******************* Copiar una matriz en otra *******************/
/* copiar_matrices.c
 */

#include <stdio.h>

#define FILAS 3
#define COLS 3

int main(int argc, char const *argv[])
{
    float a[FILAS][COLS], c[FILAS][COLS];
    int fila = 0, col = 0;

    // Leer datos para la matriz a

    for (fila = 0 ; fila < FILAS ; fila++)
    {
        for (col = 0 ; col < COLS ; col++)
        {
            printf("a[%d][%d] = ", fila, col);
        	scanf("%f", &a[fila][col]);
        }
    }

	// Copiar la matriz a en c

	for (fila = 0 ; fila < FILAS ; fila++)
	{
		for (col = 0 ; col < COLS ; col++)
		{
			c[fila][col] = a[fila][col];
		}
	}

	// Escribir los datos de la matriz c

	for (fila = 0 ; fila < FILAS ; fila++)
	{
		// Escribir una fila
		for (col = 0 ; col < COLS ; col++)
			printf("%10g", c[fila][col]);

		printf("\n"); // fila siguiente
	}

    return 0;
}
