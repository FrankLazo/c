/* gets.c
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    char *c = NULL; // para almacenar el valor retornado por gets
    char texto[40];

    printf("Introducir lineas de texto.\n");
    printf("Para finalizar introducir la marca EOF\n\n");

    // Leer la primera línea de texto

    c = gets(texto);

    while (c != NULL)
    {
        // Operaciones con la línea de texto leída
        // ...
        // Leer otra línea de texto
        c = gets(texto);
    }

    return 0;
}