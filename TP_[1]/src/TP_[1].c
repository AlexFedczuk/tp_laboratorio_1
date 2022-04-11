/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Alex Yago Fedczuk
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Nota: 10/04/2022
 	 	 FALTARIA REALIZAR EL FUNCIONAMIENTO DE LA OPCION 3,4,5
 	 	 PODRIA AGREGAR UN SUB MENU EN LA SEGUNDA OPCION, SI QUIERO...

 	 	 COMENTAR TODAS LA FUNCIONES!!!

 	 	 CUIDADO CON LAS CONTANTES!
 */
#include "funciones.h"

int main()
{
	setbuf(stdout, NULL);
    // A este valor abria que hacerle una validacion, ya que se puede ingresar basura. VALIDAR QUE ES UN ENTERO
    int opcionMenu;
    // Esta bandera para indicar si muestro al menu estatico o dinamico.
    int opcionUnoCargada;
    int opcionDosCargada;
    int opcionTresCargada;
    float kmIngresados;
    float precioAereolineas;
    float precioLatam;

    opcionUnoCargada = 0;
    opcionDosCargada = 0;
    opcionTresCargada = 0;
    //kmIngresados = -1;
    //precioAereolineas = -1;
    //precioLatam = -1;



    do{
        mostrarMenu(opcionUnoCargada, opcionDosCargada, kmIngresados, precioAereolineas, precioLatam);
        opcionMenu = pedirNumeroEntero("Ingrese una opcion del menu principal: ");

        switch(opcionMenu)
        {
            case 1:
                kmIngresados = pedirValorNoNegativo("Ingrese los Km: "); // VALIDAR NUMEROS NEGATIVOS
                opcionUnoCargada = 1;
                break;
            case 2:
            	precioAereolineas = pedirValorNoNegativo("Ingrese el precio de vuelo Aereolineas: "); // VALIDAR NUMEROS NEGATIVOS
            	precioLatam = pedirValorNoNegativo("Ingrese el precio de vuelo Latam: ");
            	// VALIDAR NUMEROS NEGATIVOS
                opcionDosCargada = 1;
                break;
            case 3:
                if(opcionUnoCargada == 1 && opcionDosCargada == 1)// Para validar que hay datos para calcular!
                {
                    // Aca realizaria los calculos...
                	opcionTresCargada = 1;
                }else if(opcionUnoCargada == 0 && opcionDosCargada == 1){
                    printf("\nERROR! Debe ingresar datos, faltaria cargar los Kilometros!\n");
                }else if(opcionUnoCargada == 1 && opcionDosCargada == 0){
                    printf("\nERROR! Debe ingresar datos, faltaria cargar Precios de Vuelos!\n");
                }else if(opcionUnoCargada == 0 && opcionDosCargada == 0){
                    printf("\nERROR! Debe ingresar datos, faltaria cargar los Kilometros y Precios de Vuelos!\n");
                }
                break;
            case 4:
            	if(opcionTresCargada == 1)// Para validar que hay datos para calcular!
            	{
            		//informarResultados();// Falta terminar funcion...
            	}else{
            		printf("\nERROR! Debe calcular los costos, para poder informar los resultados!\n");
            	}
                break;
            case 5:
                // Consultar bien que sucede en esta opcion.
                break;
            default:
            	if(opcionMenu < 1 || opcionMenu > 6)
            	{
            		printf("\nERROR! Ingrese una opcion del menu principal!\n");
            	}
                system("pause"); // Una pausa para el usuario.
                system("cls");// Por alguna razon, no la reconoce la funcion...
                break;
        }
    }while(opcionMenu != 6);

    return 0;
}


