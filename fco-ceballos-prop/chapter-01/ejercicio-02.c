/* Practique la edición, la compilación y ejecución con un programa similar al
 * programa aritmeti.c realizado en el apartado anterior. Por ejemplo, modifíquelo
 * para que ahora realice las operaciones de sumar, restar, multiplicar y dividir con
 * tres datos: dato1, dato2, dato3. En un segundo intento, puede también combinar
 * las operaciones aritméticas.
 */
 
#include <stdio.h>

main()
{
	int dato1, dato2, dato3, resultado;
	dato1 = 50;
	dato2 = 10;
	dato3 = 5;
	
	// Suma
	resultado = dato1 + dato2 + dato3;
	printf("%d + %d + %d = %d\n", dato1, dato2, dato3, resultado);
	
	// Resta
	resultado = dato1 - dato2 - dato3;
	printf("%d - %d - %d = %d\n", dato1, dato2, dato3, resultado);
	
	// Producto
	resultado = dato1 * dato2 * dato3;
	printf("%d * %d * %d = %d\n", dato1, dato2, dato3, resultado);
	
	// Cociente
	resultado = dato1 / dato2 / dato3;
	printf("%d / %d / %d = %d\n\n", dato1, dato2, dato3, resultado);
	
	// Combinado
	resultado = dato1 / dato2 * dato3;
	printf("%d / %d * %d = %d\n", dato1, dato2, dato3, resultado);
}
