/* Realizar un programa que calcule e imprima la suma de los múltiplos de 5 com-
 * prendidos entre dos valores a y b. El programa no permitirá introducir valores ne-
 * gativos para a y b, y verificará que a es menor que b. Si a es mayor que b,
 * intercambiará estos valores.
 */

#include <stdio.h>

imprimirMultiplos(double a, double b);
maxInt(double a);

main()
{
    double a = 0, b = 0;

    // Leer los datos, filtra números negativos
    do
    {
        printf("Ingrese el primer valor: ");
        scanf("%lf", &a);
    } while (a < 0);

    do
    {
        printf("Ingrese el segundo valor: ");
        scanf("%lf", &b);
    } while (b < 0);
    
    // Procesar y mostrar los resultados
    if (a <= b)
        imprimirMultiplos(a, b);
    else
        imprimirMultiplos(b, a);
}

imprimirMultiplos(double a, double b)
{
    // Asignar valores enteros adecuados
    int m = maxInt(a);
    int n = maxInt(b);
    int suma = 0;

    // Imprimir los múltiplos de 5
    printf("\nLa suma de los multiplos de 5,\n");
    printf("comprendidos entre %g y %g es: \n\n", a, b);

    if (m % 5 == 0)
    {
        printf("%d", m);
        if (n - m >= 5)
            printf(" + ");
    }

    m /= 5;
    for (m++; m <= n/5; m++)
    {
        suma += m;
        printf("%d", m * 5);

        if(m != n/5)
            printf(" + ");
    }

    printf(" = %d\n", suma * 5);
}

maxInt(double a)
{
    int n = a;
    if (n == a)
        return n;
    else
        return n + 1;
}