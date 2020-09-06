#include "operacionesMatematicas.h"

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

    if(operador == 0)
    {
        resultado = 1;
    }else
    {
        resultado = operador * FactorizarUnEntero(operador - 1);
    }

    return resultado;
}
