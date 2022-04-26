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

int main(void) {

	setbuf(stdout,NULL);

	float numero=0;

	getFloat("ingrese un numero", "Error", -2000, 100000, &numero);

	printf("%.2f",numero);
	return 0;
}
