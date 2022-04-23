/*
 * MiBiblioteca.c
 *
 *  Created on: 23 abr. 2022
 *      Author: Izzyto
 */
#include "Prueba.h"

static int esNumerico(char* cadena);
static int getInt(int* pNumero);

void getFloat(char mensaje[], char mensajeError[], int minimo, int maximo, int *numeroIngresado){

	int auxliarNumeroIngresado;
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

}

static int getInt(int* pNumero)
{
	char auxiliar[1020];
	if(pNumero!=NULL)
	{
		if (myGets(auxiliar, 1020)==1 && esNumerico(auxiliar)==1)
		{
			*pNumero= atoi(auxiliar);
			return 1;
		}
	}
	return 0;
}

static int esNumerico(char* cadena)
{
	int i;
	if(cadena!=NULL)
	{
		if(cadena[0]=='-')
		{
			i=1;
		}
		for(;cadena[i]!='\0';i++)
		{
			if(cadena[i]>'9' || cadena[i]<'0')
			{
				return 0;
				break;
			}
		}



		if(cadena[0]=='-')
		{
			for(i=1;cadena[i]!='\0';i++)
			{
				if(cadena[i]>'9' || cadena[i]<'0')
				{
					return 0;
					break;
				}
			}
		}
		else
		{
			for(i=0;cadena[i]!='\0';i++)
			{
				if(cadena[i]>'9' || cadena[i]<'0')
				{
					return 0;
					break;
				}
			}
		}
	}
	return 1;
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


