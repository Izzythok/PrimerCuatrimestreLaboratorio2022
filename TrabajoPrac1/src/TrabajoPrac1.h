/*
 * TrabajoPractico1.h
 *
 *  Created on: 3 abr. 2022
 *      Author: izzy
 *      float Blatam,float Clatam, float Dlatam,
 */
#ifndef TrabajoPractico1_H_
#define TrabajoPractico1_H_

#include <stdio.h>
#include <stdlib.h>

void Menu();
void IngresoDekm(float* km);
void IngresoPreciosVuelos(float* Aerolineas, float* Latam);
void CalcularTodosLosCostos(float* Aerolineas, float* Latam, float* LatamDebito,float* AerolineasDebito);
void InformarResultados(float Kilometros, float valorAerolineas, float valorLatam,float Alatam, float Aaerolineas);


void getFloat(char mensaje[], char mensajeError[], float minimo, float maximo, float *numeroIngresado);
void DescuentoEnPorcentaje(float* valor,float porcentaje,float* valorDevuelto);


#endif
