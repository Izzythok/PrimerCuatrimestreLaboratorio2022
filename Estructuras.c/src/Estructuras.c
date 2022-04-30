/*
 ============================================================================
 Name        : c.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Estructuras.h"

int main(void) {
	setbuf(stdout,NULL);

	//int a;
	char b[5];

	getString("ingrese el nombre","Error",3,5, b);
	//myGets(b, 5);
	printf("%s\n",b);

	return EXIT_SUCCESS;
}
