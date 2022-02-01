/* Indique qué resultado da el siguiente programa. A continuación ejecute el pro-
 * grama y compare los resultados.
 * 
 * #include <stdio.h>
 * main()
 * {
 *   char car1 = 'A', car2 = 65, car3 = 0;
 *   car3 = car1 + 'a' - 'A';
 *   printf("%d %c\n", car3, car3);
 *   car3 = car2 + 32;
 *   printf("%d %c\n", car3, car3);
 * }
 */

#include <stdio.h>

main()
{
    char car1 = 'A', car2 = 65, car3 = 0;

    car3 = car1 + 'a' - 'A';
    printf("%d %c\n", car3, car3);
    
    car3 = car2 + 32;
    printf("%d %c\n", car3, car3);
}