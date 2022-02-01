/* si_o_no.c
 */

#include <stdio.h>

main()
{
    char car = '\0';

    printf("Desea continuar s/n (si o no) ");
    // car = getchar();
    // while (car != 's' && car != 'n')
    // {
    //     fflush(stdin);
    //     printf("Desea continuar s/n (si o no) ");
    //     car = getchar();
    // }
    while ((car = getchar()) != 's' && car != 'n')
    {
        fflush(stdin);
        printf("Desea continuar s/n (si o no) ");
    }    
}