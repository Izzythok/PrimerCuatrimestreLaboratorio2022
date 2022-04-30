/*
 * BiblioEstruc.c
 *
 *  Created on: 28 abr. 2022
 *      Author: izzy
 */

#include "Estructuras.h"

static int esNumerico(char* cadena);
static float getInt(float* pNumero);
//static int myGets(char* cadena, int longitud);
static int String(char* pString, int longitud);


int getString(char* mensaje,char* Error,int reintentos,int longitud, char* pResultado)
{
	char Auxiliar[1020];
	int rtn =0;
	int retornogetString;

	if(mensaje!=NULL && Error!=NULL && reintentos>0)
	{
		printf("%s\n",mensaje);
		retornogetString = String(Auxiliar,longitud);
		do{
			if(retornogetString!=1)
			{
				printf("%s\n",Error);
				retornogetString = String(Auxiliar,sizeof(Auxiliar));
				reintentos--;
			}
			else
			{
				strncpy(pResultado,Auxiliar,longitud);
				rtn=1;
				reintentos=0;
			}

		}while(reintentos>0);
	}
	return rtn;

}

static int String(char* pString, int longitud)
{
	char auxiliar[1020];
	if(pString!=NULL)
	{
		if (myGets(auxiliar, longitud)==1 && esNumerico(auxiliar)==0)
		{
			strncpy(pString,auxiliar,longitud);
			return 1;
		}
	}
	return 0;
}

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

	if(cadena!=NULL && longitud>0)
	{
		//fflush(stdin);
		fgets(cadena,longitud,stdin);
		cadena[longitud]='\0';
		//strncpy(cadena,aux,longitud);
		return 1;
	}
	return 0;
}
