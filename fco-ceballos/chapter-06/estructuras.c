/********** Operaciones con estructuras **********/
/* estructuras.c
 */

#include <stdio.h>

typedef struct
{
	int dia, mes, anyo;
} tfecha;

typedef struct
{
	char nombre[40];
	char direccion[40];
	long telefono;
	tfecha fecha_nacimiento;
} tficha;

int main (int argc, char const *argv[])
{
	tficha persona, otra_persona;

	// Introducir datos

	printf("Nombre:          ");
	gets(persona.nombre);
	printf("Direccion:       ");
	gets(persona.direccion);
	printf("Telefono:        ");
	scanf("%ld", &persona.telefono);
	printf("Fecha de nacimiento:\n");
	printf("Dia:             ");
	scanf("%d", &persona.fecha_nacimiento.dia);
	printf("Mes:             ");
	scanf("%d", &persona.fecha_nacimiento.mes);
	printf("Anyo:            ");
	scanf("%d", &persona.fecha_nacimiento.anyo);

	// Copiar una estructura en otra
	otra_persona = persona;

	// Escribir los datos de la nueva estructura

	printf("\n\n");
	printf("Nombre:      %s\n", otra_persona.nombre);
	printf("Direccion:   %s\n", otra_persona.direccion);
	printf("Telefono:    %ld\n", otra_persona.telefono);
	printf("Fecha de nacimiento:\n");
	printf("  Dia:       %d\n", otra_persona.fecha_nacimiento.dia);
	printf("  Mes:       %d\n", otra_persona.fecha_nacimiento.mes);
	printf("  Anyo:      %d\n", otra_persona.fecha_nacimiento.anyo);

	return 0;
}
