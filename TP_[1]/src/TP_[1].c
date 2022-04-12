/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Alex Yago Fedczuk
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Nota: 10/04/2022
 	 	 FALTARIA REALIZAR EL FUNCIONAMIENTO DE LA OPCION 4,5
 	 	 PODRIA AGREGAR UN SUB MENU EN LA OPCION 2, SI QUIERO...

 	 	 COMENTAR TODAS LA FUNCIONES!!!

 	 	 CUIDADO CON LAS CONTANTES!
 */
#include "funciones.h"

int main()
{
	setbuf(stdout, NULL);
    int opcionMenu;
    int opcionUnoCargada;
    int opcionDosCargada;
    int opcionTresCargada;
    float kmIngresados;
    float precioLatam;
    float precioAereolineas;
    float latamDebito;
    float latamCredito;
    float latamBitcoin;
    float latamUnitario;
    float aereolineasDebito;
    float aereolineasCredito;
    float aereolineasBitcoin;
    float aereolineasUnitario;
    float diferencia;

    opcionUnoCargada = 0;
    opcionDosCargada = 0;

    do{
        mostrarMenu(opcionUnoCargada, opcionDosCargada, kmIngresados, precioAereolineas, precioLatam);
        opcionMenu = pedirNumeroEntero("Ingrese una opcion del menu principal: ");

        switch(opcionMenu)
        {
            case 1:
                kmIngresados = pedirValorNoNegativo("Ingrese los Km: ");
                opcionUnoCargada = 1;
                opcionTresCargada = 0;
                break;
            case 2:
            	precioAereolineas = pedirValorNoNegativo("Ingrese el precio de vuelo Aereolineas: ");
            	precioLatam = pedirValorNoNegativo("Ingrese el precio de vuelo Latam: ");
                opcionDosCargada = 1;
                opcionTresCargada = 0;
                break;
            case 3:
                if(opcionUnoCargada == 1 && opcionDosCargada == 1){
                	latamDebito = aplicarDescuento(precioLatam, DESCUENTO);
                	latamCredito = aplicarAumento(precioLatam, AUMENTO);
                	latamBitcoin = pesosABitcoin(precioLatam, VALOR_BITCOIN);
                	latamUnitario = calcularPrecioUnitario(kmIngresados, precioLatam);
                	aereolineasDebito = aplicarDescuento(precioAereolineas, DESCUENTO);
                	aereolineasCredito = aplicarAumento(precioAereolineas, AUMENTO);
                	aereolineasBitcoin = pesosABitcoin(precioAereolineas, VALOR_BITCOIN);
                	aereolineasUnitario = calcularPrecioUnitario(kmIngresados, precioAereolineas);
                	diferencia = calcularDiferencia(precioLatam, precioAereolineas);
                	opcionTresCargada = 1;
                	printf("\nLos costos se han calculado!\n");
                }else if(opcionUnoCargada == 0 && opcionDosCargada == 1){
                    printf("\nERROR! Debe ingresar datos, faltaria cargar los Kilometros!\n");
                }else if(opcionUnoCargada == 1 && opcionDosCargada == 0){
                    printf("\nERROR! Debe ingresar datos, faltaria cargar Precios de Vuelos!\n");
                }else if(opcionUnoCargada == 0 && opcionDosCargada == 0){
                    printf("\nERROR! Debe ingresar datos, faltaria cargar los Kilometros y Precios de Vuelos!\n");
                }
                break;
            case 4:
            	if(opcionTresCargada == 1)
            	{
            		informarResultados(
            				latamDebito,
            				latamCredito,
            				latamBitcoin,
            				latamUnitario,
            				aereolineasDebito,
            				aereolineasCredito,
            				aereolineasBitcoin,
            				aereolineasUnitario,
            				diferencia);
            	}else{
            		printf("\nERROR! Debe calcular los costos antes, para poder informar los resultados!\n");
            	}
                break;
            case 5:
                // Esta en el GDB Online lo que hace!
                break;
            default:
            	if(opcionMenu < 1 || opcionMenu > 6)
            	{
            		printf("\nERROR! Ingrese una opcion del menu principal!\n");
            	}
                system("pause");
                system("cls");// Por alguna razon, no la reconoce la funcion...
                break;
        }
    }while(opcionMenu != 6);

    return 0;
}


