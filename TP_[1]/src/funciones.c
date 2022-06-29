#include "funciones.h"

void mostrarMenu(int opcionUnoCargada, int opcionDosCargada, float kmIngresados, float precioAereolineas, float precioLatam){
	
    printf("Menu pricipal\n");
	
    if(opcionUnoCargada == 0){
        printf("1. Ingresar Kilómetros (km = x)\n");// Cuidado con las tildes.
    }else{
        printf("1. Ingresar Kilómetros (km = %.2f)\n", kmIngresados);// Cuidado con las tildes.
    }
	
    if(opcionDosCargada == 0){
        printf("2. Ingresar Precio de Vuelos (Aerolíneas = y, Latam = z)\n");// Cuidado con las tildes.
    }else{
        printf("2. Ingresar Precio de Vuelos (Aerolíneas = %.2f, Latam = %.2f)\n", precioAereolineas, precioLatam);// Cuidado con las tildes.
    }
	
    printf("3. Calcular todos los costos\n");
    printf("4. Informar Resultados\n");
    printf("5. Carga forzada de datos\n"); // Esta opcion ejecuta el CALCULO y el INFORME.
    printf("6. Salir\n\n");
}

void informarResultados(
		float latamDebito,
		float latamCredito,
		float latamBitcoin,
		float latamUnitario,
		float aereolineasDebito,
		float aereolineasCredito,
		float aereolineasBitcoin,
		float aereolineasUnitario,
		float diferencia)
{
    printf("\nLatam:\n");
    printf("a) Precio con tarjeta de debito: %.2f\n", latamDebito);
    printf("b) Precio con tarjeta de credito: %.2f\n", latamCredito);
    printf("c) Precio pagando con bitcoin : %.2f\n", latamBitcoin);
    printf("d) Precio unitario: %.2f\n\n", latamUnitario);
    printf("Aerolineas:\n");
    printf("a) Precio con tarjeta de debito: %.2f\n", aereolineasDebito);
    printf("b) Precio con tarjeta de credito: %.2f\n", aereolineasCredito);
    printf("c) Precio pagando con bitcoin : %.2f\n", aereolineasBitcoin);
    printf("d) Precio unitario: %.2f\n\n", aereolineasUnitario);
    printf("La diferencia de precio es : %.2f\n\n", diferencia);
}

void hardcodearValores(float* kmIngresados, float* precioLatam, float* precioAereolineas){
    *kmIngresados = 7090.0;
    *precioAereolineas = 1335000.66;
    *precioLatam = 1350000.76;
}

void informarCargaForzada(
		float precioLatam,
		float precioAereolineas,
		float kmIngresados,
		float latamDebito,
		float latamCredito,
		float latamBitcoin,
		float latamUnitario,
		float aereolineasDebito,
		float aereolineasCredito,
		float aereolineasBitcoin,
		float aereolineasUnitario,
		float diferencia)
{
	printf("\nKMs Ingresados: %.2f km\n\n", kmIngresados);
    	printf("Precio Aerolineas: $%.2f\n", precioAereolineas);
    	printf("a) Precio con tarjeta de debito: $ %.2f\n", aereolineasDebito);
   	printf("b) Precio con tarjeta de credito: $ %.2f\n", aereolineasCredito);
   	printf("c) Precio pagando con bitcoin: %.2f BTC\n", aereolineasBitcoin);
    	printf("d) Precio unitario: %.2f\n\n", aereolineasUnitario);
    	printf("\nPrecio Latam: $%.2f\n", precioLatam);
    	printf("a) Precio con tarjeta de debito: $ %.2f\n", latamDebito);
    	printf("b) Precio con tarjeta de credito: $ %.2f\n", latamCredito);
    	printf("c) Precio pagando con bitcoin : %.2f BTC\n", latamBitcoin);
    	printf("d) Precio unitario: $ %.2f\n\n", latamUnitario);
    	printf("La diferencia de precio es: $ %.2f\n\n", diferencia);
}
