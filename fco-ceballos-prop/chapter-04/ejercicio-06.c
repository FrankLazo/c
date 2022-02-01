/* Ejecute el siguiente programa, explique lo que ocurre y realice las modificaciones
 * que sean necesarias para su correcto funcionamiento.
 * 
 * #include <stdio.h>
 * void main()
 * {
 *   int car = 0;
 *   car = getchar();
 *   putchar(car);
 *   car = getchar();
 *   putchar(car);
 * }
 */

#include <stdio.h>

main()
{
    int car = 0;
    car = getchar();
    putchar(car);

    fflush(stdin);
    printf("\n");

    car = getchar();
    putchar(car);
}