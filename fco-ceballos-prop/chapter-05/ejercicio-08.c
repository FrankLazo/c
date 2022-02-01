/* Realizar un programa que calcule el importe a pagar por un vehículo al circular
 * por una autopista. El vehículo puede ser una bicicleta, una moto, un coche o un
 * camión. Para definir el conjunto vehículos utilizaremos un tipo enumerado (vea
 * en el capítulo 2 los tipos enumerados). El importe se calculará según los siguien-
 * tes datos:
 * 
 *  - Un importe fijo de 100 unidades para las bicicletas.
 *  - Las motos y los coches pagarán 30 unidades por Km.
 *  - Los camiones pagarán 30 unidades por Km más 25 unidades por Tn.
 * 
 * La presentación en pantalla de la solución, será de la forma siguiente:
 * 
 *         1 - bicicleta
 *         2 - moto
 *         3 - coche
 *         4 - camión
 *         5 - salir 
 * 
 * Seleccione la opción deseada: 4
 * Kilómetros y toneladas? 100 50
 * Importe = 4250
 * 
 */

#include <stdio.h>

double calcularImporte(double kilometros, double toneladas);

main()
{
    double kilometros = 0;
    double toneladas = 0;
    double importe = 0;

    enum vehiculos
    {
        bicicleta = 1,
        moto,
        coche,
        camion,
        salir
    };

    enum vehiculos vehiculo;

    // Mostrar opciones

    printf("\t\t1 - bicicleta\n");
    printf("\t\t2 - moto\n");
    printf("\t\t3 - coche\n");
    printf("\t\t4 - camion\n");
    printf("\t\t5 - salir\n\n");

    // Leer la opción y cantidades

    printf("Seleccione la opcion deseada: ");
    scanf("%d", &vehiculo);

    // Procesar datos

    switch (vehiculo)
    {
        case 1:
        case 2:
            importe = 100;
            break;

        case 3:
            printf("Kilometros? ");
            scanf("%lf", &kilometros);
            importe = calcularImporte(kilometros, toneladas);
            break;

        case 4:
            printf("Kilometros y toneladas? ");
            scanf("%lf %lf", &kilometros, &toneladas);
            importe = calcularImporte(kilometros, toneladas);
            break;

        default:
            importe = -1;
            break;
    }

    // Procesar datos y mostrar resultados

    if (importe >= 0)
    {
        printf("Importe = %g\n", importe);
    }
}

double calcularImporte(double kilometros, double toneladas)
{
    double importe = 0;

    importe += kilometros * 30;

    if (toneladas)
    {
        importe += toneladas * 25;
    }

    return importe;
}