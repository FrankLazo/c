/* Una empresa dedicada a la venta de electrodomésticos y a su posterior manteni-
 * miento desea tener una aplicación que automatice todos sus procesos de gestión.
 *
 * Esto supone tener la información de todos los clientes que compran electro-
 * domésticos junto con los contratos de mantenimiento (esta última información,
 * lógicamente, sólo estará disponible en los casos que el cliente contrate un seguro
 * de mantenimiento para los electrodomésticos adquiridos) almacenada en una ma-
 * triz dinámica de estructuras.
 *
 * Cada cliente podrá asegurar o no el electrodoméstico comprado y cada elec-
 * trodoméstico asegurado dará lugar a un contrato de mantenimiento.
 *
 * La estructura tcon almacena la información de cada electrodoméstico com-
 * prado y asegurado:
 *
 * typedef struct
 * {
 *   char Descripcion[80];  // Descripción del electrodoméstico
 *   int ValorCompra;		// Valor del electrodoméstico
 *   int ImpContrato;		// Importe del contrato de mantenimiento
 *   char NumSerie[15];     // Número de serie del aparato
 *   char NumContrato[10];  // Número del contrato
 * } tcon;
 *
 * Para almacenar los contratos de mantenimiento subscritos por cada cliente, se
 * define una estructura tcontrato así:
 *
 * typedef struct
 * {
 *   tcon *Contrato;        // Puntero a una estructura tcon
 *   int nContratosAct;     // Número actual de contratos por cliente
 * } tcontrato;
 *
 * Para almacenar los datos de los clientes que han comprado electrodomésticos
 * aunque no hayan asegurado ninguno, se define una estructura tcliente así:
 *
 * typedef struct
 * {
 *   char Nombre[35];       // Nombre del cliente
 *   char Apellidos[55];    // Apellidos del cliente
 *   char Direccion[35];    // Dirección del cliente
 *   char Codigo[15];       // Código del cliente
 *   tcontrato ContratoCli; // Estructura del tipo tcontrato
 * } tcliente;
 *
 * La matriz dinámica de estructuras con la información de los clientes estará re-
 * ferenciada por la variable pcliente definida a continuación:
 *
 * tcliente *pcliente;
 *
 * Partiendo de las declaraciones anteriores y suponiendo que existe una matriz
 * apuntada por pcliente correctamente iniciada, implemente las siguientes funcio-
 * nes:
 *
 * a) Función AutorizaReparacion. Indica si se autoriza o no una reparación de un
 *    electrodoméstico dependiendo de los siguientes requisitos:
 *
 *    * Existe un contrato para el electrodoméstico con el número de serie especi-
 *      ficado.
 *    * El coste de la reparación no excede del 25% del valor de compra.
 *
 *    int AutorizaReparacion(tcliente *pcliente,
 *                           char numSerie[15],
 *                           int numClientes,
 *                           int impReparacion);
 *
 *    Parámetros:
 *    pcliente         puntero a la matriz de estructuras tcliente.
 *    numSerie         número de serie del aparato.
 *    numClientes      número de clientes existentes.
 *    impReparacion    coste de la reparación.
 *
 *    Valor retornado:
 *    Un 0 si el importe de la reparación excede el 25% de la compra, un 1 si se au-
 *    toriza y un 2 si el número de serie no existe.
 *
 * b) Función DarDeAltaUnContrato. Dará de alta un contrato para un cliente exis-
 *    tente en pcliente, solicitando los datos desde el teclado. El prototipo de la fun-
 *    ción DarDeAltaUnContrato se indica a continuación:
 *
 *    void DarDeAltaUnContrato(tcliente *pcliente, int i);
 *
 *    Parámetros:
 *    pcliente         puntero a la matriz de estructuras tcliente.
 *    i                posición del cliente poseedor del nuevo contrato.
 *
 *    Valor retornado: ninguno.
 *
 *    Nota: el nuevo contrato introducido se insertará en la posición primera si este
 *    cliente no tuviera contratos vigentes. En caso contrario, se insertará después
 *    del último contrato existente (se sugiere utilizar la función realloc).
 *
 * c) Función BuscarPosicion. Permite encontrar la posición de un determinado
 *    cliente en la matriz dinámica de estructuras. El prototipo para esta función es
 *    el siguiente:
 *
 *    int BuscarPosicion(tcliente *pcliente,
 *                       char *codigo, int numClientes);
 *
 *    Parámetros:
 *    pcliente         puntero a la matriz de estructuras tcliente.
 *    codigo           código del cliente.
 *    numClientes      número de clientes existentes.
 *
 *    Valor retornado:
 *    Un entero que indica la posición que ocupa el cliente en la matriz, o -1 si el
 *    cliente no se encuentra.
 *
 * d) Función Listar. Mostrará en pantalla un listado de todos los datos de los clien-
 *    tes. En el caso de que un cliente no tenga ningún contrato mostrará un mensa-
 *    je indicándolo.
 *
 *    void Listar(tcliente *pcliente, int numClientes);
 *
 *    Parámetros:
 *    pcliente         puntero a la matriz de estructuras tcliente.
 *    numClientes      número de clientes existentes.
 *
 *    Valor retornado: ninguno.
 *
 * e) Función LiberarMemoria. Liberará toda la memoria que se haya asignado du-
 *    rante la ejecución del programa. Su prototipo es:
 *
 *    void LiberarMemoria(tcliente *pcliente, int numClientes);
 *
 *    Parámetros:
 *    pcliente         puntero a la matriz de estructuras tcliente.
 *    numClientes      número de clientes existentes.
 *
 *    Valor retornado: ninguno.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructuras
typedef struct
{
    char Descripcion[80];
    int ValorCompra;
    int ImpContrato;
    char NumSerie[15];
    char NumContrato[10];
} tcon;

typedef struct
{
    tcon *Contrato;
    int nContratosAct;
} tcontrato;

typedef struct
{
    char Nombre[35];
    char Apellidos[55];
    char Direccion[35];
    char Codigo[15];
    tcontrato ContratoCli;
} tcliente;

// Prototipos
int AutorizaReparacion( tcliente *pcliente, char numSerie[15], int numClientes, int impReparacion );
void DarDeAltaUnContrato( tcliente *pcliente, int i );
int BuscarPosicion( tcliente *pcliente, char *codigo, int numClientes );
void Listar(tcliente *pcliente, int numClientes);
void LiberarMemoria(tcliente *pcliente, int numClientes);

int main()
{
    int c = 0;
    int posicion = 0;
    int reparacion = 0;
    int numClientes = 3;
    char codigo[15];
    tcliente *pcliente = NULL;

    // Asignar memoria
    pcliente = ( tcliente * )malloc( numClientes * sizeof( tcliente ) );

    // Rellenar datos de ejemplo
    for ( c = 1; c <= numClientes; c++ )
    {
        sprintf( pcliente[ c - 1 ].Nombre, "Nombre del cliente %d", c );
        sprintf( pcliente[ c - 1 ].Apellidos, "Apellidos del cliente %d", c );
        sprintf( pcliente[ c - 1 ].Direccion, "Direccion del cliente %d", c );
        sprintf( pcliente[ c - 1 ].Codigo, "00000%d", c );
        pcliente[ c - 1 ].ContratoCli.Contrato = NULL;
        pcliente[ c - 1 ].ContratoCli.nContratosAct = 0;
    }

	system( "cls" );

    Listar( pcliente, numClientes );

    // Buscar clientes
    strcpy( codigo, "000002" );
    posicion = BuscarPosicion( pcliente, codigo, numClientes );
    if ( posicion >= 0 ) printf( "El cliente %s se encuentra en la posicion %d.\n", codigo, posicion );
    else printf( "El cliente %s no existe.\n", codigo );

    strcpy( codigo, "000009" );
    posicion = BuscarPosicion( pcliente, codigo, numClientes );
    if ( posicion >= 0 ) printf( "El cliente %s se encuentra en la posicion %d.\n", codigo, posicion );
    else printf( "El cliente %s no existe.\n", codigo );

    // Dar de alta contratos
    DarDeAltaUnContrato( pcliente, 2 );
    Listar( pcliente, numClientes );

    // Autorizar reparaciones
    reparacion = AutorizaReparacion( pcliente, "E-0001", numClientes, 20 );

    switch ( reparacion )
    {
        case 0:  printf( "No se autoriza la reparacion.\n" ); break;
        case 1:  printf( "Se autoriza la reparacion.\n" ); break;
        case 2:  printf( "No existe el numero de serie.\n" ); break;
        default: break;
    }

    LiberarMemoria( pcliente, numClientes );

    return 0;
}

/*
 * FUNCIÓN AUTORIZA REPARACION
 *
 */

int AutorizaReparacion( tcliente *pcliente, char numSerie[15], int numClientes, int impReparacion )
{
    int i = 0;

    for ( i = 0; i < numClientes; i++ )
    {
        if ( pcliente[ i ].ContratoCli.Contrato != NULL
             && !strcmp( pcliente[ i ].ContratoCli.Contrato->NumSerie, numSerie ) )
        {
            if ( impReparacion <= pcliente[ i ].ContratoCli.Contrato->ValorCompra * 0.25 ) return 1;
            else return 0;
        }
    }

    return 2;
}

/*
 * FUNCIÓN DAR DE ALTA UN CONTRATO
 *
 */

void DarDeAltaUnContrato( tcliente *pcliente, int i )
{
    int nContrato = pcliente[ i ].ContratoCli.nContratosAct;
    pcliente[ i ].ContratoCli.nContratosAct = nContrato + 1;

    pcliente[ i ].ContratoCli.Contrato = ( tcon * )realloc( pcliente[ i ].ContratoCli.Contrato,
                                                            ( nContrato + 1 ) * sizeof( tcon ) );

    sprintf( pcliente[ i ].ContratoCli.Contrato[ nContrato ].NumContrato, "C-00%d", 1 );
    sprintf( pcliente[ i ].ContratoCli.Contrato[ nContrato ].NumSerie, "E-000%d", 1 );
    strcpy( pcliente[ i ].ContratoCli.Contrato[ nContrato ].Descripcion, "Descripcion del electrodomestico" );
    pcliente[ i ].ContratoCli.Contrato[ nContrato ].ValorCompra = 100;
    pcliente[ i ].ContratoCli.Contrato[ nContrato ].ImpContrato = 20;

    printf( "\n" );
    printf( "%s\n", pcliente[ i ].ContratoCli.Contrato[ nContrato ].NumContrato );
    printf( "%s\n", pcliente[ i ].ContratoCli.Contrato[ nContrato ].NumSerie );
    printf( "%s\n", pcliente[ i ].ContratoCli.Contrato[ nContrato ].Descripcion );
    printf( "%d\n", pcliente[ i ].ContratoCli.Contrato[ nContrato ].ValorCompra );
    printf( "%d\n", pcliente[ i ].ContratoCli.Contrato[ nContrato ].ImpContrato );
}

/*
 * FUNCIÓN BUSCAR POSICION
 *
 */

int BuscarPosicion( tcliente *pcliente, char *codigo, int numClientes )
{
    int posicion = 0;

    while ( posicion < numClientes && strcmp( pcliente[ posicion ].Codigo, codigo) ) posicion++;

    return ( posicion != numClientes ) ? posicion : -1;
}

/*
 * FUNCIÓN LISTAR
 *
 */

void Listar(tcliente *pcliente, int numClientes)
{
    int c = 0;

    system( "cls" );

    printf( "Listado de clientes\n" );
    printf( "===================\n" );
    printf( "\n" );
    printf( "\n" );

    for ( c = 0; c < numClientes; c++ )
    {
        printf( "Codigo:             %30s\n", pcliente[ c ].Codigo );
        printf( "Nombre:             %30s\n", pcliente[ c ].Nombre );
        printf( "Apellidos:          %30s\n", pcliente[ c ].Apellidos );
        printf( "Direccion:          %30s\n", pcliente[ c ].Direccion );

        if ( pcliente[ c ].ContratoCli.nContratosAct )
        {
            printf( "Numero de contratos: %29d\n", pcliente[ c ].ContratoCli.nContratosAct );
        }
        else
        {
            printf( "** El cliente no cuenta con ningun contrato. **\n" );
        }

        printf( "\n" );
        printf( "\n" );
    }
}

/*
 * FUNCIÓN LIBERAR MEMORIA
 *
 */

void LiberarMemoria(tcliente *pcliente, int numClientes)
{
    int c = 0;

    for ( c = 0; c < numClientes; c++ )
    {
        if ( pcliente[ c ].ContratoCli.nContratosAct )
            free( pcliente[ c ].ContratoCli.Contrato );
    }

    free( pcliente );
}
