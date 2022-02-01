/* Realizar el mismo programa anterior, pero empleando ahora coeficientes variables
 * a, b y c.
 */

#include <stdio.h>

main()
{
    double a = 0.0, b = 0.0, c = 0.0;
    double valor = 0.0, resultado = 0.0;

    printf("Ingrese el primer coeficiente: ");
    scanf("%lf", &a);
    printf("Ingrese el segundo coeficiente: ");
    scanf("%lf", &b);
    printf("Ingrese el tercer coeficiente: ");
    scanf("%lf", &c);
    printf("Ingrese el valor de x: ");
    scanf("%lf", &valor);

    resultado = (a * valor * valor * valor * valor * valor);
    resultado = resultado - (b * valor * valor * valor) + c * valor - 7;

    printf("El resultado es: %g\n", resultado);
}