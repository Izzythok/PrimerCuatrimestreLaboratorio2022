/*
 * Prueba.h
 *
 *  Created on: 23 abr. 2022
 *      Author: Izzyto
 */

#ifndef PRUEBA_H_
#define PRUEBA_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max_Longitud_Char 50
#define OCUPADO 1
#define LIBRE 0
#define BAJA -1

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	char marca[30];
	int isEmpty;
	int id;
	float p;
	eFecha FechaDeVencimiento;
}eProducto;

void eProducto_imprimirUno(eProducto producto);
int eProducto_imprimirTodos(eProducto listaDeProductos[],int longitud,int Estado);
int eProducto_Inicializar(eProducto listaDeProductos[],int longitud);
int eProducto_BuscarEspacioLibre(eProducto listaDeProductos[], int longitud);
int eProducto_Alta(eProducto listaDeProductos[], int longitud);
eProducto eProducto_CargarUnProducto();
int eProducto_Baja(eProducto listaDeProductos[], int longitud);
int eProducto_BuscarIndexPorId(eProducto listaDeProductos[], int longitud);
int eProducto_Modificacion(eProducto listaDeProductos[], int longitud);
eProducto eProducto_ModificarUnProducto(eProducto p);



float getFloat(char mensaje[], char mensajeError[], float minimo, float maximo,int reintentos, float *numeroIngresado);
int getInt(char mensaje[], char mensajeError[], int minimo, int maximo,int reintentos, int *numeroIngresado);
int getString(char* mensaje,char* Error,int longitud, char* pResultado);


#endif /* PRUEBA_H_ */
