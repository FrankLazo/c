/************* Limpiar el buffer asociado con stdin *************/
/* fflush.c
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int entero;
    double real;
    char respuesta = 's', cadena[81];

    // Introducir números

    printf("Introducir un n%c entero y n%c real:\n", 167, 167);
    scanf("%d %lf", &entero, &real);
    printf("%d + %f = %f\n\n", entero, real, entero + real);

    // Limpiar el buffer de entrada y leer una cadena con gets
    
    fflush(stdin); // o bien gets(cadena)

    printf("Introducir cadenas para gets.\n");

    while (respuesta == 's' && gets(cadena) != NULL)
    {
        printf("%s\n", cadena);

        do
        {
            printf("%cDesea continuar? (s/n) ", 168);
            respuesta = getchar();

            // Limpiar el buffer de entrada

            fflush(stdin); // o bien gets(cadena)
        }
        while ((respuesta != 's') && (respuesta != 'n'));
    }

    return 0;
}