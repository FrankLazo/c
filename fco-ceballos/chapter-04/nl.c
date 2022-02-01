/* nl.c - Carácter \n
 */

#include <stdio.h>

int main()
{
    float precio = 0;
    char car = 0;

    printf("Precio: ");
    scanf("%g", &precio);
    fflush(stdin);

    printf("Pulse <Entrar> para continuar: ");
    scanf("%c", &car);

    printf("Precio: = %g\n", precio);
}