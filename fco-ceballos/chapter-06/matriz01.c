/************* Creación de una matriz unidimensional *************/
/* matriz01.c
 */

#include <stdio.h>

#define N_ELEMENTOS 10 // número de elementos de la matriz

int main(int argc, char const *argv[])
{
    int m[N_ELEMENTOS]; // crear la matriz m
    int i = 0;          // subíndice

    printf("Introducir los valores de la matriz.\n");

    // Entrada de datos

    for (i = 0; i < N_ELEMENTOS; i++)
    {
        printf("m[%d] = ", i);
        scanf("%d", &m[i]);
    }
    
    // Salida de datos

    printf("\n\n");

    for (i = 0 ; i < N_ELEMENTOS; i++)
    {
        printf("%d ", m[i]);
    }

    printf("\n\nFin del proceso.\n");

    return 0;
}