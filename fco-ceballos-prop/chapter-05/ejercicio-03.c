/* Realizar un programa que permita evaluar la serie:
 *                  Sumatoria <a = 0; b> de 1 / (x + ay)
 */

#include <stdio.h>

double evaluarSerie(int a, int b, double x, double y);

main()
{
    int leido = 0;
    int a = 0, b = 0;
    double x = 0, y = 0, suma = 0;

    // Leer los datos, filtra números negativos

    do
    {
        printf("Ingrese el valor final (b): ");
        scanf("%d", &b);
    }
    while (b < 0);

    // Filtra valores que causarían indeterminación

    do
    {
        printf("Ingrese el valor de x: ");
        scanf("%lf", &x);
    }
    while (x == 0);

    do
    {
        printf("Ingrese el valor de y: ");
        scanf("%lf", &y);
    }
    while (x == -y);

    // Procesar datos

    suma = evaluarSerie(a, b, x, y);
    
    // Mostrar resultados

    printf("La sumatoria es: %g", suma);
}

double evaluarSerie(int a, int b, double x, double y)
{
    int i;
    double suma = 0;
    
    for (i = a ; i <= b ; i++)
    {
        suma += 1 / (x + i * y);
    }

    return suma;
}