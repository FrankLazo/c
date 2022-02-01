/* Si quiere averiguar su número de Tarot, sume los números de su fecha de naci-
 * miento y a continuación redúzcalos a un único dígito; por ejemplo si su fecha de
 * nacimiento fuera 17 de octubre de 1992, los cálculos a realizar serían:
 * 
 *          17 + 10 + 1992 = 2019 => 2 + 0 + 1 + 9 = 12 => 1 + 2 = 3
 * 
 * lo que quiere decir que su número de Tarot es el 3.
 * 
 * Realizar un programa que pida una fecha, de la forma:
 * 
 *                              día mes año
 * 
 * donde día, mes y año son enteros, y dé como resultado el número de Tarot. El
 * programa verificará si la fecha es correcta, esto es, los valores están dentro de los
 * rangos permitidos.
 * 
 */

#include <stdio.h>

int evaluarFecha(int dia, int mes, int agno);
int obtenerNumeroTarot(int dia, int mes, int agno);

main()
{
    int dia = 0, mes = 0, agno = 0;
    int numeroTarot = 0;
    int resultado = 0;

    // Leer los datos, filtra fechas fuera de rango

    do
    {
        printf("Ingrese su fecha de nacimiento (dd mm aaaa): ");
        scanf("%d %d %d", &dia, &mes, &agno);

        resultado = evaluarFecha(dia, mes, agno);
    }
    while (!resultado);

    // Procesar datos

    numeroTarot = obtenerNumeroTarot(dia, mes, agno);
    
    // Mostrar resultados

    printf("Su numero de tarot es: %d\n", numeroTarot);
}

int esBisiesto (int agno)
{
    if (agno % 4 == 0 && agno % 100 != 0)
    {
        return 1;
    }
    else if (agno % 400 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int evaluarFecha(int dia, int mes, int agno)
{
    if (dia < 1 || mes < 1 || mes > 12 || agno < 1000 || agno > 9999)
    {
        return 0;
    }
    else
    {
        switch (mes)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if (dia > 31)
                {
                    return 0;
                }
                break;
            
            case 4:
            case 6:
            case 9:
            case 11:
                if (dia > 30)
                {
                    return 0;
                }
                break;

            case 2:
                if (esBisiesto(agno) && dia > 29)
                {
                    return 0;
                }
                else if (!esBisiesto(agno) && dia > 28)
                {
                    return 0;
                }
                break;

            default:
                break;
        } 

        return 1;
    }
}

int obtenerNumeroTarot(int dia, int mes, int agno)
{
    int numeroTarot = dia + mes + agno;
    int temporal = 0, cifra = 0;

    do
    {
        do
        {
            cifra = numeroTarot % 10;
            temporal += cifra;
            numeroTarot = (numeroTarot - cifra) / 10;
        }
        while (numeroTarot > 0);
        
        numeroTarot = temporal;
        temporal = 0;
    }
    while (numeroTarot > 10);

    return numeroTarot;
}