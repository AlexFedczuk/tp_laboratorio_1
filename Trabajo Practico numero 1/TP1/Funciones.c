#include "Funciones.h"

void MostrarMenu(int banderaPrimerOperando,
                 int primerOperando,
                 int banderaSegundoOperando,
                 int segundoOperando)
{
    printf("     **** MENU PRINCIPAL ****\n");

    if(banderaPrimerOperando == 0)
    {
        printf("\n   1. Ingresar 1er operando (A=x)\n");
    }else
    {
        printf("\n   1. Ingresar 1er operando (A=%d)\n", primerOperando);
    }

    if(banderaSegundoOperando == 0)
    {
        printf("   2. Ingresar 2do operando (B=y)\n");
    }else
    {
        printf("   2. Ingresar 2do operando (B=%d)\n", segundoOperando);
    }

    printf("   3. Calcular todas las operaciones\n");
    printf("   4. Informar resultados\n");
    printf("   5. Salir\n");
}

int TomarOpcionElegida(int opcionElegida)
{
    do
    {
        printf("\n   Elija una opcion: ");
        scanf("%d", &opcionElegida);

        if(opcionElegida <1 || opcionElegida > 5)
        {
            printf("\n   Error! La opcion elegida es invalida!\n");
        }
    }
    while(opcionElegida < 1 || opcionElegida > 5);

    return opcionElegida;
}

int PedirNumeroEntero(char mensaje[30])
{
    int numeroIngresado;

    printf(mensaje);
    scanf("%d", &numeroIngresado);

    return numeroIngresado;
}

int HacerLogicaBanderaOperador(int banderaOperando)
{
    if(banderaOperando == 0)
    {
        banderaOperando = 1;
    }

    return banderaOperando;
}

int SumarDosEnteros(int primerOperador, int segundoOperador)
{
    int resultado;

    resultado = primerOperador + segundoOperador;

    return resultado;
}

int RestarDosEnteros(int primerOperador, int segundoOperador)
{
    int resultado;

    resultado = primerOperador - segundoOperador;

    return resultado;
}

int MultiplicarDosEnteros(int primerOperador, int segundoOperador)
{
    int resultado;

    resultado = primerOperador * segundoOperador;

    return resultado;
}

float DividirDosEnteros(int primerOperador, int segundoOperador)
{
    int resultado;

    if(segundoOperador != 0)
    {
        resultado = (float)primerOperador / segundoOperador;
    }

    return resultado;
}

int FactorizarUnEntero(int operador)
{
    int resultado;

    for(int i = 1; i <= operador; i++)
    {
        resultado = operador * i;
    }

    return resultado;
}
