/*
 * MiBiblioteca.c
 *
 *  Created on: 23 abr. 2022
 *      Author: Izzyto
 */
#include "Prueba.h";

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

int myGets(char* cadena, int longitud)
{
	char auxiliar[1020];
	if(cadena!=NULL && longitud>0 && fgets(auxiliar,sizeof(auxiliar),stdin) == auxiliar)
	{
		strncpy(cadena,auxiliar,longitud);
		return 0;
	}
	return -1;
}


