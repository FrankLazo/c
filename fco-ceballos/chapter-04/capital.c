/* Realizar un programa que de como resultado los intereses producidos y el capital
 * total acumulado de una cantidad c, invertida a un interés r durante t días.
 * 
 * La fórmula utilizada para el cálculo de los intereses es:
 * 
 *                          I = (c * r * t) / (360 * 100)
 * 
 * siendo:
 * I = Total de intereses producidos.
 * c = Capital.
 * r = Tasa de interés nominal en tanto por ciento.
 * t = Período de cálculo en días.
 */

/********************* Capital e Intereses *********************/
/* capital.c
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    double c, intereses, capital;
    float r;
    int t;

    system("cls"); /* limpiar pantalla */

    /* Entrada de datos */
    printf("Capital invertido        ");
    scanf("%lf", &c);
    printf("\nA un %% anual del         ");
    scanf("%f", &r);
    printf("\nDurante cu%cntos d%cas     ", 160, 161);
    scanf("%d", &t);
    printf("\n\n");

    /* Cálculos */
    intereses = c * r * t / (360L * 100);
    capital = c + intereses;

    /* Escribir resultados */
    printf("Intereses producidos...%10.0f\n", intereses);
    printf("Capital acumulado......%10.0f\n", capital);
}