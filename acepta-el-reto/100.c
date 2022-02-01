/* Constante de Kaprekar
 */

#include <stdio.h>

#define KAPREKAR 6174

int kaprekar(int);
int menorAMayor(int[]);
int mayorAMenor(int);

int main()
{
    int n, i;
    int numKap;
    // int numKap[10000];
    // int vuelta[10000];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &numKap);

        if(numKap == KAPREKAR)
            printf("%d\n", 0);
        else if(numKap % 1111 == 0)
            printf("%d\n", 8);
        else
            printf("%d\n", kaprekar(numKap));
    }

    // for(i = 0; i < n; i++)
    //     scanf("%d", &numKap[i]);

    // for(i = 0; i < n; i++)
    //     vuelta[i] = kaprekar(numKap[i]);

    // for(i = 0; i < n; i++)
    //     printf("%d\n", vuelta[i]);

    return 0;
}

int kaprekar(int numero)
{
    int vueltas = 0, i;
    int digitos[4];

    do
    {
        vueltas++;
        for(i = 0; i < 4; i++)
        {
            digitos[i] = numero % 10;
            numero = (numero - digitos[i]) / 10;
        }
        numero = mayorAMenor(numero) - menorAMayor(digitos);
    } while (numero != KAPREKAR);
    
    return vueltas;
}

int menorAMayor(int &digitos)
{
    int numero, i, j;

    // for(i = 0; i < 4; i++)
    // {
    //     digitos[i] = numero % 10;
    //     numero = (numero - digitos[i]) / 10;
    // }

    for(i = 0; i < 4; i++)
        for(j = i + 1; j < 4; j++)
        {
            int x = 0;

            if(digitos[j] < digitos[i])
            {
                x = digitos[i];
                digitos[i] = digitos[j];
                digitos[j] = x;
            }
        }

    numero = digitos[0]*1000 + digitos[1]*100 + digitos[2]*10 + digitos[3];

    return numero;
}

int mayorAMenor(int numero)
{
    int digitos[4], i, j;

    for(i = 0; i < 4; i++)
        {
            digitos[i] = numero % 10;
            numero = (numero - digitos[i]) / 10;
        }

    for(i = 0; i < 4; i++)
        for(j = i + 1; j < 4; j++)
        {
            int x = 0;

            if(digitos[j] > digitos[i])
            {
                x = digitos[i];
                digitos[i] = digitos[j];
                digitos[j] = x;
            }
        }

    numero = digitos[0]*1000 + digitos[1]*100 + digitos[2]*10 + digitos[3];

    return numero;
}