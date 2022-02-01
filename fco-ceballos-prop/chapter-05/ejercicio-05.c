/* Realizar un programa que genere la siguiente secuencia de dígitos:
 * 
 *                                  1
 *                                2 3 2
 *                              3 4 5 4 3
 *                            4 5 6 7 6 5 4
 *                          5 6 7 8 9 8 7 6 5
 *                        6 7 8 9 0 1 0 9 8 7 6
 *                      7 8 9 0 1 2 3 2 1 0 9 8 7
 *                    8 9 0 1 2 3 4 5 4 3 2 1 0 9 8
 *                  9 0 1 2 3 4 5 6 7 6 5 4 3 2 1 0 9
 *                0 1 2 3 4 5 6 7 8 9 8 7 6 5 4 3 2 1 0
 *              1 2 3 4 5 6 7 8 9 0 1 0 9 8 7 6 5 4 3 2 1
 *            2 3 . . . . . . . . . . . . . . . . . . . . .
 * 
 * El número de filas estará comprendido entre 11 y 20 y el resultado aparecerá cen-
 * trado en la pantalla como se indica en la figura.
 * 
 */

#include <stdio.h>

#define FILAS_MIN 11
#define FILAS_MAX 20

void imprimirPiramide(int filas);

main()
{
    int n_filas = 0;

    // Leer el número de filas

    do
    {
        printf("Ingrese el numero de filas.\n");
        printf("Mayor o igual a 11 y, menor o igual a 20: ");
        scanf("%d", &n_filas);
    }
    while (n_filas < FILAS_MIN || n_filas > FILAS_MAX);
 
    // Procesar datos y mostrar resultados

    imprimirPiramide(n_filas);
}

void imprimirPiramide(int filas)
{
    int i, j, n_columnas, resultado;

    for (i = 1 ; i <= filas ; i++)
    {
        n_columnas = 2 * i - 1;
        resultado = i;

        for (j = i ; j < filas ; j++)
        {
            printf("  ");
        }

        for (j = 0 ; j < n_columnas ; j++)
        {
            printf("%d ", resultado % 10);

            if (j < i - 1)
            {
                resultado++;
            }
            else
            {
                resultado--;
            }
        }

        printf("\n");
    }
}