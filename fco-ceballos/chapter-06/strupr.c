/*********** Conversión de minúsculas a mayúsculas ***********/
/* strupr.c
 */

#include <stdio.h>

#define LONG_MAX 81 // Longitud máxima de la cadena

void MinusculasMayusculas(char str[]);

int main(int argc, char const *argv[]) // función principal
{
    char cadena[LONG_MAX];
    int i = 0;

    // Introducir números

    printf("Introducir una cadena: ");
    gets(cadena);

    MinusculasMayusculas(cadena); // llamada a la función
    printf("%s\n", cadena);

    return 0;
}

/**************************************************************
                Función MinúsculasMayúsculas    
**************************************************************/

// Convierte minúsculas a mayúsculas

void MinusculasMayusculas(char str[])
{
    int i = 0, desp = 'a' - 'A';

    for (i = 0 ; str[i] != '\0' ; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - desp;
        }
    }
}