/*
 * MiBiblioteca.c
 *
 *  Created on: 23 abr. 2022
 *      Author: Izzyto
 */
#include "Prueba.h"

static int esNumerico(char* cadena);
<<<<<<< HEAD
static int getInt(int* pNumero);

void getFloat(char mensaje[], char mensajeError[], int minimo, int maximo, int *numeroIngresado){

	int auxliarNumeroIngresado;
=======
static float getInt(float* pNumero);

float getFloat(char mensaje[], char mensajeError[], float minimo, float maximo, float *numeroIngresado){

	float auxliarNumeroIngresado;
>>>>>>> 53cc4cb (actualizacion 2)
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
<<<<<<< HEAD

}

static int getInt(int* pNumero)
=======
	return 1;

}

static float getInt(float* pNumero)
>>>>>>> 53cc4cb (actualizacion 2)
{
	char auxiliar[1020];
	if(pNumero!=NULL)
	{
		if (myGets(auxiliar, 1020)==1 && esNumerico(auxiliar)==1)
		{
<<<<<<< HEAD
			*pNumero= atoi(auxiliar);
=======
			*pNumero= atof(auxiliar);
>>>>>>> 53cc4cb (actualizacion 2)
			return 1;
		}
	}
	return 0;
}

static int esNumerico(char* cadena)
{
	int i;
<<<<<<< HEAD
=======
	int contador=0;
>>>>>>> 53cc4cb (actualizacion 2)
	if(cadena!=NULL)
	{
		if(cadena[0]=='-')
		{
<<<<<<< HEAD
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
=======
			contador=1;
			for(i=1;cadena[i]!='\0' && cadena[1]>'.';i++)
			{
				if((cadena[i]<='9' && cadena[i]>='0') || cadena[i]=='.')
				{
					contador++;
>>>>>>> 53cc4cb (actualizacion 2)
				}
			}
		}
		else
		{
<<<<<<< HEAD
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
=======
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
>>>>>>> 53cc4cb (actualizacion 2)
}

int myGets(char* cadena, int longitud)
{
	char auxiliar[1020];
	if(cadena!=NULL && longitud>0 && fgets(auxiliar,sizeof(auxiliar),stdin) == auxiliar)
	{
<<<<<<< HEAD

=======
>>>>>>> 53cc4cb (actualizacion 2)
		auxiliar[strlen(auxiliar)-1]='\0';
		strncpy(cadena,auxiliar,longitud);
		return 1;
	}
	return 0;
}


