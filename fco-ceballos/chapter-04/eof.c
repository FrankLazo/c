/* eof.c
 */

#include <stdio.h>

int main()
{
    int r = 0;
    float precio = 0;

    printf("Precio: ");
    r = scanf("%g", &precio);

    (r == EOF) ? printf("Fin de la entrada de datos\n")
               : printf("%g\n", precio);
}