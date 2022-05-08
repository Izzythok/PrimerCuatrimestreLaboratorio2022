/*
 * MiBiblioteca.c
 *
 *  Created on: 23 abr. 2022
 *      Author: Izzyto
 */
#include "Prueba.h"
#define Max_Buffer 1020

static int esNumerico(char* cadena);
static float get_Numero(float* pNumero);
static int myGets(char* cadena, int longitud);
static int idAutoincremental = 1000;
static int eProducto_ObtenerIdUnico(void);

float getFloat(char mensaje[], char mensajeError[], float minimo, float maximo,int reintentos, float *numeroIngresado)
{
	float auxliarNumeroIngresado;
	int retornogetInt;
	int rtn=0;

	if(minimo<maximo && mensaje!=NULL && mensajeError!=NULL && reintentos>0)
	{
		printf("%s\n",mensaje);
		retornogetInt = get_Numero(&auxliarNumeroIngresado);

		do
		{
			if(retornogetInt!=1 || minimo>auxliarNumeroIngresado || maximo<auxliarNumeroIngresado)
			{
				printf("%s\n",mensajeError);
				printf("%s\n",mensaje);
				retornogetInt = get_Numero(&auxliarNumeroIngresado);
				reintentos--;
			}
			else
			{
				*numeroIngresado = auxliarNumeroIngresado;
				reintentos=0;
				rtn=1;
			}

		}while(reintentos>0);

	}
	return rtn;
}

int getInt(char mensaje[], char mensajeError[], int minimo, int maximo,int reintentos, int *numeroIngresado)
{
	float auxliarNumeroIngresado;
	int retornogetInt;
	int rtn=0;

	if(minimo<maximo && mensaje!=NULL && mensajeError!=NULL && reintentos>0)
	{
		printf("%s\n",mensaje);
		retornogetInt = get_Numero(&auxliarNumeroIngresado);
		do
		{
			if(retornogetInt!=1 || minimo>auxliarNumeroIngresado || maximo<auxliarNumeroIngresado)
			{
				printf("%s\n",mensajeError);
				printf("%s\n",mensaje);
				retornogetInt = get_Numero(&auxliarNumeroIngresado);
				reintentos--;
			}
			else
			{
				*numeroIngresado = (int)auxliarNumeroIngresado;
				reintentos=0;
				rtn=1;
			}

		}while(reintentos>0);

	}
	return rtn;
}

static float get_Numero(float* pNumero)
{
	char auxiliar[Max_Buffer];
	if(pNumero!=NULL)
	{
		if (myGets(auxiliar, Max_Buffer)==1 && esNumerico(auxiliar)==1)
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

static int myGets(char* cadena, int longitud)
{
	char auxiliar[Max_Buffer];
	if(cadena!=NULL && longitud>0 && fgets(auxiliar,sizeof(auxiliar),stdin) == auxiliar)
	{

		auxiliar[strnlen(auxiliar,sizeof(auxiliar))-1]='\0';
		strncpy(cadena,auxiliar,longitud);
		return 1;
	}
	return 0;
}

int getString(char* mensaje,char* Error,int longitud, char* pString)
{
	char Auxiliar[Max_Buffer];
	int rtn =0;

	if(mensaje!=NULL && Error!=NULL)
	{
		printf("%s\n",mensaje);
		fflush(stdin);
		fgets(Auxiliar,sizeof(Auxiliar),stdin);

		while(strnlen(Auxiliar,sizeof(Auxiliar))>longitud || strnlen(Auxiliar,sizeof(Auxiliar))==0)
		{
			printf("%s\n",Error);
			printf("Se excedio del rango de caracteres Max: %d\n",longitud-1);
			fflush(stdin);
			fgets(Auxiliar,sizeof(Auxiliar),stdin);
		}

		Auxiliar[longitud-1]='\0';
		strncpy(pString,Auxiliar,longitud);
		rtn=1;

	}
	return rtn;

}

//###############################################################################################################################
//ABM

static int eProducto_ObtenerIdUnico()
{
	return idAutoincremental++;
}

void eProducto_imprimirUno(eProducto producto)
{
		printf("Id: %d.\n - Marca: %s \n",producto.id,producto.marca);

}


int eProducto_imprimirTodos(eProducto ListaDeProductos[],int longitud, int Estado)
{
	if(ListaDeProductos!=NULL && longitud>0)
	{
		for(int i=0;i<longitud;i++)
		{
			if(ListaDeProductos[i].isEmpty==Estado)
			{
				eProducto_imprimirUno(ListaDeProductos[i]);
			}
		}
		return 1;
	}
	return 0;
}

int eProducto_Inicializar(eProducto listaDeProductos[],int longitud)
{
	if(listaDeProductos!=NULL && longitud>0)
		{
			for(int i=0;i<longitud;i++)
			{
				listaDeProductos[i].isEmpty=LIBRE;
			}
			return 1;
		}
	return 0;
}

int eProducto_Alta(eProducto listaDeProductos[], int longitud)
{
	int rtn = 0;
	int indexLibre;
	eProducto auxiliarProducto;
	//VA A RETORNAR UN INDEX LIBRE SI ENCONTRO O -1 SI NO LO ENCONTRO.
	indexLibre = eProducto_BuscarEspacioLibre(listaDeProductos, longitud);

	if (listaDeProductos != NULL && longitud>0)
	{

			if (indexLibre >= 0) {
				//CARGO DATOS NO GENERICOS
				auxiliarProducto = eProducto_CargarUnProducto();

				//SI ESTA TODO BIEN - LE DOY UN ID UNICO
				auxiliarProducto.id = eProducto_ObtenerIdUnico();
				//CAMBIO ESTADO A OCUPADO
				auxiliarProducto.isEmpty = OCUPADO;
				//PLUS - PREGUNTAR SI ESTA SEGURO
				//COPIA AUXILIAR EN ARRAY EN POSICION OBTENIDA LIBRE
				listaDeProductos[indexLibre] = auxiliarProducto;
				rtn = indexLibre;
			}
			else
			{
				// ARRAY LLENO
				rtn = -1;
			}
	}

	return rtn;
}

int eProducto_BuscarEspacioLibre(eProducto listaDeProductos[], int longitud)
{
	//-1: no hay espacio
	// Index: si encontro espacio
	int rtn = 0;
	int flag = 0;
	int i;

	if (listaDeProductos != NULL && longitud>0)
	{
			//ESTA OK
			for (i = 0; i < longitud; i++)
			{
				if (listaDeProductos[i].isEmpty == LIBRE)
				{
					flag = 1;
					rtn = i;
					break;
				}
			}

			if (flag == 0)
			{
				rtn = -1;
			}
	}

	return rtn;
}

eProducto eProducto_CargarUnProducto()
{
	eProducto p;

	getInt("Ingrese el dia", "Error", 1, 31, 3, &p.FechaDeVencimiento.dia);
	getInt("Ingrese el mes", "Error", 1, 12, 3, &p.FechaDeVencimiento.mes);
	getInt("Ingrese el anio", "Error", 1900, 2022, 3, &p.FechaDeVencimiento.anio);
	getString("ingrese la marca", "Error", Max_Longitud_Char, p.marca);

	return p;
}

int eProducto_Baja(eProducto listaDeProductos[], int longitud)
{
	//-1: si no encontro el ID
	//0: si salio mal la funcion
	int rtn = 0;
	int indexBaja;

	if (listaDeProductos != NULL && longitud>0)
	{
			//BUSCA UN INDEX POR ID - RETORNA -1 SI NO ENCUENTRA EL ID EN EL ARRAY
			indexBaja = eProducto_BuscarIndexPorId(listaDeProductos, longitud);
			if (indexBaja < 0)
			{
				//HUBO UN ERROR BUSCANDO EL INDEX
				rtn = -1;
			}
			else
			{
				//SI ENCONTRO ME QUEDO CON EL INDEX Y CAMBIO EL ESTADO
				//EXTRA - PREGUNTO SI DESEA DAR DE BAJA - ME LO PUEDO GUARDAR EN UN AUX Y MOSTRARLO PREVIO A ELIMINAR
				listaDeProductos[indexBaja].isEmpty = -1;
			}

	}

	return rtn;
}

int eProducto_BuscarIndexPorId(eProducto listaDeProductos[], int longitud)
{
	//INDEX: SI ENCONTRO UNO OCUPADO
	//-1: SI NO ENCONTRO EL ID
	//0: SI SALIO MAL LA FUNCION
	int rtn = 0;
	int flag = 0;
	int i;
	int buscarID;

	if (listaDeProductos != NULL && longitud>0)
	{

			//ESTA OK

			//MUESTRO TODOS - Le muestro al usuario todos los dados de alta para que elija cual ID dar de baja
			eProducto_imprimirTodos(listaDeProductos, longitud, OCUPADO);

			//PEDIR UN ID
			getInt("Ingrese el ID: ", "ERROR", 1000, 5000, 3, &buscarID);

			for (i = 0; i < longitud; i++)
			{
				if (listaDeProductos[i].isEmpty == OCUPADO)
				{
					if (listaDeProductos[i].id == buscarID)
					{
						flag = 1;
						rtn = i; //retorno index del ID que estoy buscando
						break;
					}
				}
			}
			if (flag == 0)
			{
				rtn = -1;
			}
	}

	return rtn;
}

int eProducto_Modificacion(eProducto listaDeProductos[], int longitud)
{
	//-1: si no encontro el ID
	//0: si salio mal la funcion
	int rtn = 0;
	int indexModificacion;
	eProducto auxiliarProducto;

	if (listaDeProductos != NULL && longitud>0)
	{
			//BUSCA UN INDEX POR ID - RETORNA -1 SI NO ENCUENTRA EL ID EN EL ARRAY
			indexModificacion = eProducto_BuscarIndexPorId(listaDeProductos, longitud);
			if (indexModificacion < 0)
			{
				//HUBO UN ERROR BUSCANDO EL INDEX
				rtn = -1;
			}
			else
			{
				auxiliarProducto = listaDeProductos[indexModificacion];
				//MODIFICAR UN PRODUCTO
				auxiliarProducto = eProducto_ModificarUnProducto(auxiliarProducto);
				//EXTRA - PREGUNTO SI DESEA CONFIRMAR - REEMPLAZO LA COPIA POR EL ORIGINAL
				listaDeProductos[indexModificacion] = auxiliarProducto;
			}

	}

	return rtn;
}

eProducto eProducto_ModificarUnProducto(eProducto p)
{

	int opcion;
	getInt("Ingrese una opcion a modificar", "Error", 1, 4, 3, &opcion);

	//While - para cargar cuantos datos quiera el usuario

	switch (opcion)
	{
	case 1:
		getInt("Ingrese el dia", "Error", 1, 31, 3, &p.FechaDeVencimiento.dia);
		break;
	case 2:
		getInt("Ingrese el mes", "Error", 1, 12, 3, &p.FechaDeVencimiento.mes);
		break;
	case 3:
		getInt("Ingrese el mes", "Error", 1900, 2022, 3, &p.FechaDeVencimiento.anio);
		break;
	case 4:
		getString("ingrese la marca", "Error", Max_Longitud_Char, p.marca);
		break;
	}

	return p;
}
