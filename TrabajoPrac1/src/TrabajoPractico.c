/*
 * TrabajoPractico.c
 *
 *  Created on: 3 abr. 2022
 *      Author: izzy
 */


#include "TrabajoPrac1.h"

void Menu(){
	int Salir;
	int opciones;
	float Km;
	float Aerolineas;
	float Latam;
	float TarjetaDeDebitoConDescuentoAerolineas;
	float TarjetaDeDebitoConDescuentoLatam;


	Km=7090;
	Aerolineas=0;
	Latam=0;

	do{
		printf("1. Ingresar Kilómetros: ( km=%.2f)\n\n",Km);

		printf("2. Ingresar Precio de Vuelos: (Aerolíneas=%.2f, Latam=%.2f)\n",Aerolineas,Latam);
		puts("- Precio vuelo Aerolíneas:");
		puts("- Precio vuelo Latam: \n");

		puts("3. Calcular todos los costos:");
		puts("a) Tarjeta de débito (descuento 10%)");
		puts("b) Tarjeta de crédito (interés 25%)");
		puts("c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)");
		puts("d) Mostrar precio por km (precio unitario)");
		puts("e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n");

		puts("4. Informar Resultados");

		puts("\n5. Carga forzada de datos\n");

		puts("6. Salir");

		scanf("%d",&opciones);

		switch(opciones)
		{
			case 1:
				IngresoDekm(&Km);
				break;
			case 2:
				IngresoPreciosVuelos(&Aerolineas,&Latam);
				break;
			case 3:
				CalcularTodosLosCostos(&Aerolineas,&Latam,&TarjetaDeDebitoConDescuentoLatam,&TarjetaDeDebitoConDescuentoAerolineas);
				break;
			case 4:
				InformarResultados(Km,Aerolineas,Latam,TarjetaDeDebitoConDescuentoLatam,TarjetaDeDebitoConDescuentoAerolineas);
				break;
			case 6:
				Salir=6;
				break;
		}

	}while(Salir!=6);


}

void IngresoDekm(float* km){

	getFloat("Ingrese los Kilometros: ","Error, el dato ingresado no es correcto o no esta entre el rango indicado",0,90000,km);
}


void IngresoPreciosVuelos(float* Aerolineas, float* Latam)
{
	getFloat("- Precio vuelo Aerolíneas:","Error, el dato ingresado no es correcto o no esta entre el rango indicado",0,10000000,Aerolineas);
	getFloat("- Precio vuelo Latam:","Error, el dato ingresado no es correcto o no esta entre el rango indicado",0,10000000,Latam);
}

void CalcularTodosLosCostos(float* Aerolineas, float* Latam, float* LatamDebito,float* AerolineasDebito)
{
	DescuentoEnPorcentaje(Aerolineas,10,AerolineasDebito);
	DescuentoEnPorcentaje(Latam,10,LatamDebito);
}

void InformarResultados(float Kilometros, float valorAerolineas, float valorLatam,float Alatam, float Aaerolineas)
{
	int opciones;

			printf("Kilometros ingresados: %.2f\n",Kilometros);

			printf("“Latam: %.2f\n",valorAerolineas);
			printf("a) Precio con tarjeta de débito: %.2f\n",Alatam);
			printf("b) Precio con tarjeta de crédito: r\n");
			printf("c) Precio pagando con bitcoin : r\n");
			printf("d) Precio unitario: r\n");
			printf("Aerolíneas: %.2f\n",valorLatam);
			printf("a) Precio con tarjeta de débito: %.2f\n",Aaerolineas);
			printf("b) Precio con tarjeta de crédito: r\n");
			printf("c) Precio pagando con bitcoin : r\n");
			printf("d) Precio unitario: r\n");
			printf("La diferencia de precio es : r\n");

			puts("Para volver al menu: 1");
			puts("salir: 6");
			scanf("%d",&opciones);

			switch(opciones)
			{
				case 1:
					Menu();
					break;
				case 6:
					break;
					break;
			}
}






