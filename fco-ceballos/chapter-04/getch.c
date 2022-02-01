/* getch.c - Funciones _getch y _getche
 */

#include <stdio.h>
#include <conio.h>

int main()
{
    char byte1, byte2;

    printf("Pulse la combinaci%cn de teclas cuyo c%cdigo\n"
           "extendido desea conocer\n", 162, 162);
    byte1 = _getch(); byte2 = _getch();
    printf("%d \t %d\n", byte1, byte2);

    printf("Pulse una tecla para continuar ");
    _getche();
    printf("\nFin del programa\n");
}