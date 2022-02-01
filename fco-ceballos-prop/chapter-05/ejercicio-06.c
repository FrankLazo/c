/* Un centro numérico es un número que separa una lista de números enteros (co-
 * menzando en 1) en dos grupos de números, cuyas sumas son iguales. El primer
 * centro numérico es el 6, el cual separa la lista (1 a 8) en los grupos: (1, 2, 3, 4, 5)
 * y (7, 8) cuyas sumas son ambas iguales a 15. El segundo centro numérico es el 35,
 * el cual separa la lista (1 a 49) en los grupos: (1 a 34) y (36 a 49) cuyas sumas son
 * ambas iguales a 595. Escribir un programa que calcule los centros numéricos en-
 * tre 1 y n.
 * 
 */

#include <stdio.h>

void imprimirCentrosNumericos(int n);

main()
{
    int n = 0;

    // Leer el número de filas

    do
    {
        printf("Ingrese el limite superior.\n");
        printf("Entero positivo: ");
        scanf("%d", &n);
    }
    while (n < 1);
 
    // Procesar datos y mostrar resultados

    imprimirCentrosNumericos(n);
}

void imprimirCentrosNumericos(int n)
{
    int sum_inferior;
    int sum_superior;
    int centro, i, j;

    for (centro = 1 ; centro < n ; centro++)
    {
        sum_inferior = 0;
        sum_superior = 0;
        j = centro + 1;

        for (i = 1 ; i < centro ; i++)
        {
            sum_inferior += i;
        }

        do
        {
            sum_superior += j;
            j++;
        }
        while (sum_superior < sum_inferior && j <= n);
        
        if (sum_inferior == sum_superior)
        {
            printf("%d ", centro);
        }
    }

    printf("\n");
}