/*
 ============================================================================
 Name        : Prueba.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Prueba.h"
#define Max_Productos 3

int main(void) {

	setbuf(stdout,NULL);
	eProducto ListaDeProductos[Max_Productos];
	int a;

	eProducto_Inicializar(ListaDeProductos, Max_Productos);
	a = eProducto_Alta(ListaDeProductos, Max_Productos);
	if(a>=0)
	{
		puts("CARGA EXITOSA!");
		eProducto_imprimirUno(ListaDeProductos[a]);
	}
	else
	{
		if (a == -1)
				{
					puts("LISTA LLENA!");
				}
				else
				{
					puts("FALLA EN LA CARGA!");
				}
	}

	return 0;
}
