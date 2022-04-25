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

<<<<<<< HEAD
	int numero=0;

	getFloat("ingrese un numero", "Error", -2000, 100000, &numero);

	printf("%d",numero);
=======
	float numero=0;

	getFloat("ingrese un numero", "Error", -2000, 100000, &numero);

	printf("%d",(int)numero);
>>>>>>> 53cc4cb (actualizacion 2)
	return 0;
}
