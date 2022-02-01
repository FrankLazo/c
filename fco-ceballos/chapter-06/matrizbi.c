/********* Suma de las filas de una matriz bidimensional *********/
/* matrizbi.c
 */

#include <stdio.h>

#define FILAS_MAX 10  // Número máximo de filas
#define COLS_MAX 10   // Número máximo de columnas

int main(int argc, char const *argv[])
{
    float m[FILAS_MAX][COLS_MAX];   // matriz m de dos dimensiones
    float sumaFila;     // Suma de los elementos de una fila
    int filas, cols;    // filas y columnas de la matriz de trabajo
    int fila, col;      // fila y columna del elemento accedido

    do
    {
        printf("Numero de filas de la matriz:    ");
        scanf("%d", &filas);
    }
    while (filas < 1 || filas > FILAS_MAX);
    
    do
    {
        printf("Numero de columnas de la matriz:    ");
        scanf("%d", &cols);
    }
    while (cols < 1 || cols > COLS_MAX);

    // Entrada de datos

    printf("Introducir los valores de la matriz.\n");

    for (fila = 0 ; fila < filas ; fila++)
    {
        for (col = 0 ; col < cols ; col++)
        {
            printf("m[%d][%d] = ", fila, col);
            scanf("%f", &m[fila][col]);
        }
    }

    // Escribir la suma de cada fila

    for (fila = 0 ; fila < filas ; fila++)
    {
        sumaFila = 0;

        for (col = 0 ; col < cols ; col++)
        {
            sumaFila += m[fila][col];
        }

        printf("Suma de la fila %d = %g\n", fila, sumaFila);
    }

    printf("\nFin del proceso.\n");

    return 0;
}