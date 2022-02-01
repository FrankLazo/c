/* Realizar un programa que calcule el volumen de una esfera, que viene dado por la
 * fórmula:
 * 
 *                              v = (4 * π * r³) / 3
 */

#include <stdio.h>

#define PI 3.1416

main()
{
    double r = 0, v = 0;

    printf("Ingresar el radio de la esfera: ");
    scanf("%lf", &r);

    v = 4 * PI * r * r * r / 3;

    printf("El volumen de la esfera es: %lf\n", v);
}