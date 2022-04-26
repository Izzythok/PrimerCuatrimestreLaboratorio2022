/*
 * MiBiblioteca.c
 *
 *  Created on: 23 abr. 2022
 *      Author: Izzyto
 */
#include "Prueba.h"

static int esNumerico(char* cadena);
static float getInt(float* pNumero);

float getFloat(char mensaje[], char mensajeError[], float minimo, float maximo, float *numeroIngresado){

	float auxliarNumeroIngresado;
	int retornogetInt;

	if(minimo<maximo && mensaje!=NULL && mensajeError!=NULL)
	{
		printf("%s\n",mensaje);
		retornogetInt = getInt(&auxliarNumeroIngresado);

		while(retornogetInt!=1 || minimo>auxliarNumeroIngresado || maximo<auxliarNumeroIngresado)
		{
			printf("%s\n",mensajeError);
			printf("%s\n",mensaje);
			retornogetInt = getInt(&auxliarNumeroIngresado);
		}

		*numeroIngresado = auxliarNumeroIngresado;

	}
	return 0;

}

static float getInt(float* pNumero)
{
	char auxiliar[1020];
	if(pNumero!=NULL)
	{
		if (myGets(auxiliar, 1020)==1 && esNumerico(auxiliar)==1)
		{
			*pNumero= atof(auxiliar);
			return 1;
		}
	}
	return 0;
}

static int esNumerico(char* cadena)
{
	int i;
	int contador=0;

	if(cadena!=NULL)
	{
		if(cadena[0]=='-')
		{
			contador=1;
			for(i=1;cadena[i]!='\0' && cadena[1]>'.';i++)
			{
				if((cadena[i]<='9' && cadena[i]>='0') || cadena[i]=='.')
				{
					contador++;
				}
			}
		}
		else
		{
			for(i=0;cadena[i]!='\0' && cadena[0]>'.';i++)
			{
				if((cadena[i]<='9' && cadena[i]>='0') || cadena[i]=='.')
				{
					contador++;
				}
			}
		}

		if(contador==strlen(cadena))
		{
			return 1;
		}
	}
	return 0;
}

int myGets(char* cadena, int longitud)
{
	char auxiliar[1020];
	if(cadena!=NULL && longitud>0 && fgets(auxiliar,sizeof(auxiliar),stdin) == auxiliar)
	{

		auxiliar[strlen(auxiliar)-1]='\0';
		strncpy(cadena,auxiliar,longitud);
		return 1;
	}
	return 0;
}


