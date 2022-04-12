/*
 * FuncionesPunto3.c
 *
 *  Created on: 10 abr. 2022
 *      Author: izzy
 */
#include "TrabajoPrac1.h"

void getFloat(char mensaje[], char mensajeError[], float minimo, float maximo, float *numeroIngresado){

	float auxliarNumeroIngresado;
	int retornoScanf;

	if(minimo<maximo && mensaje!=NULL && mensajeError!=NULL)
	{
		printf("%s\n",mensaje);
		retornoScanf = scanf("%f",&auxliarNumeroIngresado);

		while(retornoScanf!=1 || minimo>auxliarNumeroIngresado || maximo<auxliarNumeroIngresado)
		{
			printf("%s\n",mensajeError);
			printf("%s\n",mensaje);
			fflush(stdin);
			retornoScanf = scanf("%f",&auxliarNumeroIngresado);
		}

		*numeroIngresado = auxliarNumeroIngresado;

	}

}

void DescuentoEnPorcentaje(float* valor, float porcentaje,float* valorDevuelto)
{
	*valorDevuelto=(*valor)-((*valor)*(porcentaje/100));
}
