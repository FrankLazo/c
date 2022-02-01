/****************** Leer una lista de nombres ******************/
/* cadenas.c
 */

#include <stdio.h>

#define FILAS_MAX 100
#define COLS_MAX 80

int main(int argc, char const *argv[])
{
    // Matriz de cadenas de caracteres

    char nombre[FILAS_MAX][COLS_MAX];
    int nFilas = 0;
    int fila = 0;
    char *fin, respuesta;

    do
    {
        printf("Numero de filas de la matriz:    ");
        scanf("%d", &nFilas);
    }
    while (nFilas < 1 || nFilas > FILAS_MAX);
    
    fflush(stdin);

    printf("Escriba los nombres que desea introducir.\n");
    printf("Puede finalizar pulsando las teclas [Ctrl][z].\n");

    for (fila = 0 ; fila < nFilas ; fila++)
    {
        printf("Nombre[%d]: ", fila);
        fin = gets(nombre[fila]);
        
        // Si se pulsó [Ctrl][z], salir del bucle

        if (fin == NULL)
        {
            break;
        }
    }

    nFilas = fila; // número de filas leídas

    do
    {
        printf("%cDesea visualizar el contenido de la matriz? (s/n): ", 168);
        respuesta = tolower(getchar());
        fflush(stdin);
    }
    while (respuesta != 's' && respuesta != 'n');

    if (respuesta == 's')
    {
        // Visualizar la lista de nombres
        printf("\n");

        for (fila = 0 ; fila < nFilas ; fila++)
        {
            printf("%s\n", nombre[fila]);
        }
    }

    printf("\nFin del proceso.\n");

    return 0;
}