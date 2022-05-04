/*
 * Estructuras.h
 *
 *  Created on: 26 abr. 2022
 *      Author: Izzyto
 */

#ifndef ESTRUCTURAS_H_
#define ESTRUCTURAS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char nombre[30];
	char marca[30];
	float Precio;
	int isEmpty;
	int id;
	eFecha FechaDeVencimiento;
}eProducto;

typedef struct
{
	int dia;
	int mes;
	int anio;
	int isEmpty;
}eFecha;

void imprimirUno(eProducto producto);
int imprimirEstructuraArray(eProducto Array[],int longitud);
int verificarCargaDeDatos(eProducto* Array,int longitud);

int CargarPorIndice(eProducto* Array, int indice,int longitud);//Alta de eProducto


float getFloat(char mensaje[], char mensajeError[], float minimo, float maximo, float *numeroIngresado);
int myGets(char* cadena, int longitud);
int getString(char* mensaje,char* Error,int reintentos,int longitud, char* pResultado);

#endif /* ESTRUCTURAS_H_ */
