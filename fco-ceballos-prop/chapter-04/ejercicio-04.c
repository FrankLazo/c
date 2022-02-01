/* Realizar un programa que evalúe el polinomio p = 3x⁵ - 5x³ + 2x - 7 y visualice
 * el resultado con el siguiente formato:
 * 
 * Para x = valor, 3x^5 - 5x^3 + 2x - 7 = resultado
 */

#include <stdio.h>

main()
{
    double valor = 0.0, resultado = 0.0;

    printf("Ingrese el valor de x: ");
    scanf("%lf", &valor);

    resultado = (3 * valor * valor * valor * valor * valor);
    resultado = resultado - (5 * valor * valor * valor) + 2 * valor - 7;

    printf("El resultado es: %g\n", resultado);
}