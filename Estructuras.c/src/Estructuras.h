/*
 * Estructuras.h
 *
 *  Created on: 28 abr. 2022
 *      Author: izzy
 */

#ifndef ESTRUCTURAS_H_
#define ESTRUCTURAS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nombre[20];
	char Descripcion[20];
	float precio;
}Producto;

float getFloat(char mensaje[], char mensajeError[], float minimo, float maximo, float *numeroIngresado);
int getString(char* mensaje,char* Error,int reintentos,int longitud, char* pResultado);

int myGets(char* cadena, int longitud);


#endif /* ESTRUCTURAS_H_ */
