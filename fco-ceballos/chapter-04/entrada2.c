/* entrada2.c
 */

#include <stdio.h>

int main()
{
    int a, r; float b; char c;

    printf("Introducir un valor entero, un real y un char\n=>");
    r = scanf("%d %f %c", &a, &b, &c);
    printf("\nN%cmero de datos le%cdos: %d\n", 163, 161, r);
    printf("Datos le%cdos: %d %f %c\n", 161, a, b, c);

    printf("\nValor hexadecimal: ");
    scanf("%i", &a);
    printf("Valor decimal:     %i\n", a);
}