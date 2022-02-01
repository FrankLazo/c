/* Realizar un programa que solicite un texto (suponer que los caracteres que forman
 * el texto son sólo letras, espacios en blanco, comas y el punto como final del texto)
 * y a continuación lo escriba modificado de forma que a la A le corresponda la K, a
 * la B la L, ... , a la O la Y, a la P la Z, a la Q la A, ... y a la Z la J, e igual para las
 * letras minúsculas. Suponga que la entrada no excede de una línea y que finaliza
 * con un punto.
 * 
 * Al realizar este programa tenga en cuenta que el tipo char es un tipo entero, por lo
 * tanto las afirmaciones en los ejemplos siguientes son correctas:
 * 
 * - 'A' es menor que 'a'; es equivalente a decir que 65 es menor que 97, porque
 *   el valor ASCII de 'A' es 65 y el de 'a' es 97.
 * 
 * - 'A' + 3 es igual a 'D'; es equivalente a decir que 65 + 3 es igual a 68, y este
 *   valor es el código ASCII del carácter 'D'.
 * 
 */

#include <stdio.h>
#include <conio.h>

char convertirChar(int caracter);

main()
{
    char caracter;

    // Leer, procesar datos y mostrar resultados

    printf("Ingrese el texto:\n");

    while ((caracter = getchar()) != '\n')
    {
        putchar(convertirChar(caracter));
    }
}

char convertirChar(int caracter)
{
    if ( (caracter >= 65 && caracter <= 80) || (caracter >= 97 && caracter <= 112) )
    {
        caracter += 10;
    }

    if ( (caracter >= 81 && caracter <= 90) || (caracter >= 113 && caracter <= 122) )
    {
        caracter -= 16;
    }

    return caracter;
}