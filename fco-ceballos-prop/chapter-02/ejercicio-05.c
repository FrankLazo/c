/* Escriba las sentencias necesarias para visualizar el tamaño en bytes de cada uno
 * de los tipos primitivos de C.
 */

#include <stdio.h>

main()
{
	enum dias_semana
	{
		lunes, martes, miercoles, jueves, viernes, sabado, domingo
	} semana;
	
	printf("El tama%co en bytes de un tipo char es: \t\t%d bytes.\n", 164, sizeof(char));
	printf("El tama%co en bytes de un tipo short es: \t%d bytes.\n", 164, sizeof(short));
	printf("El tama%co en bytes de un tipo int es: \t\t%d bytes.\n", 164, sizeof(int));
	printf("El tama%co en bytes de un tipo long es: \t\t%d bytes.\n", 164, sizeof(long));
	printf("El tama%co en bytes de un tipo enum es: \t\t%d bytes.\n", 164, sizeof(semana));
	printf("El tama%co en bytes de un tipo float es: \t%d bytes.\n", 164, sizeof(float));
	printf("El tama%co en bytes de un tipo double es: \t%d bytes.\n", 164, sizeof(double));
}
