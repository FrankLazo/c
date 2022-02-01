/* Realizar un programa que pregunte el nombre, el año de nacimiento y el año ac-
 * tual, y dé como resultado:
 * 
 * Hola nombre, en el año 2030 cumplirás n años
 */

#include <stdio.h>

main()
{
    char nombre[50];
    int aNatal = 0, aActual = 0;

    printf("Ingrese su nombre: ");
    scanf("%s", nombre);
    printf("Ingrese su a%co de nacimiento: ", 164);
    scanf("%d", &aNatal);
    printf("Ingrese el a%co actual: ", 164);
    scanf("%d", &aActual);

    printf("Hola %s, en el a%co 2030 cumplir%cs %d a%cos\n", nombre, 164, 160, 2030 - aNatal, 164);
}