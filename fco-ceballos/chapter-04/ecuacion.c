/* Realizar un programa que dé como resultado las soluciones reales x1 y x2 de una
 * ecuación de segundo grado, de la forma:
 * 
 *                              ax² + bx + c = 0
 * 
 * Las soluciones de una ecuación de segundo grado vienen dadas por la fórmula:
 * 
 *                          xᵢ = (-b ± √(b² - 4ac)) / (2a)
 * 
 * Las soluciones son reales sólo si (b² - 4ac) es mayor o igual que 0.
 */

/********** Solución de una ecuación de segundo grado **********/
/* ecuacion.c
 */

#include <stdio.h>  // necesario para scanf y printf
#include <stdlib.h> // necesario para system
#include <math.h>   // necesario para sqrt

int main()
{
    double a, b, c, d, x1, x2;

    system("cls");

    /* Entrada de datos */
    printf("Introducir los coeficientes a b c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    /* Comprobar si las raíces son reales */
    d = b * b - 4 * a * c;
    (d < 0) ? printf("Las ra%cces son complejas\n", 161), exit(0)
            : printf("Las ra%cces reales son:\n", 161);

    /* Cálculo de las soluciones */
    d = sqrt(d);
    x1 = (-b + d) / (2 * a);
    x2 = (-b - d) / (2 * a);

    /* Escribir resultados */
    printf("x1 = %g\nx2 = %g\n", x1, x2);
}