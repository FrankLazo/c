/****************** Miembros que son punteros ******************/
/* pparam02.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

typedef struct persona
{
	long dni;
	char *nombre;
} tpersona;

tpersona *asigmem( void );
int asignarDni( tpersona *, long );
void *asignarNombre( tpersona *, char * );
void mayusculas( tpersona );

int main()
{
	tpersona per1 = { 0, 0 };
	tpersona *pper2 = 0;
	unsigned int DNI;
	char nombre[ 80 ];

	// Asignar datos y mostrar resultados
	do
	{
		printf( "DNI: " );
		scanf( "%u", &DNI );
		fflush( stdin );
	}
	while ( !asignarDni( &per1, DNI ) );

	printf( "Nombre: " );
	gets( nombre );

	if ( !asignarNombre( &per1, nombre ) ) return -1;

	mayusculas( per1 );
	printf( "%u %s\n", per1.dni, per1.nombre );

	// Cambiar el nombre
	printf( "Nombre: " );
	gets( nombre );

	asignarNombre( &per1, nombre );
	printf( "%u %s\n", per1.dni, per1.nombre );

	// Asignar memoria para otra estructura
	pper2 = asigmem();
	if ( pper2 == NULL ) return -1;

	// Las dos estructuras compartirían el mismo bloque de memoria
	// *pper2 = per1;

	// Para copiar una estructura en otra
	pper2->dni = per1.dni;
	asignarNombre( pper2, per1.nombre );

	// Liberar la memoria asignada
	free( per1.nombre );
	free( pper2->nombre );
	free( pper2 );

	return 0;
}

tpersona *asigmem( void )
{
	tpersona *p = ( tpersona * )malloc( sizeof( tpersona ) );
	memset( p, 0, sizeof( tpersona ) );
	return p;
}

int asignarDni( tpersona *p, long n )
{
	if ( n > 0 ) p->dni = n;
	return n > 0;
}

void *asignarNombre( tpersona *p, char *nom )
{
	if ( p->nombre != 0 ) free( p -> nombre );

	if ( ( p->nombre = ( char * )malloc( strlen( nom ) + 1 ) ) == 0)
		return 0;

	return ( void * )strcpy( p->nombre, nom );
}

void mayusculas( tpersona per )
{
	strupr( per.nombre );
}
