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

void mostrarResultados(int banderaCase1,
                       int banderaCase2,
                       int banderaCase3,
                       int primerOperando,
                       int segundoOperando,
                       int resultadoSuma,
                       int resultadoResta,
                       float resultadoDivision,
                       int resultadoMultiplicacion,
                       int resultadoFactorialA,
                       int resultadoFactorialB)
{
    if(banderaCase1 == 1 && banderaCase2 == 1 && banderaCase3 == 1)
    {
        printf("\n   a) El resultado de %d+%d es: %d\n", primerOperando, segundoOperando, resultadoSuma);
        printf("   b) El resultado de %d-%d es: %d\n", primerOperando, segundoOperando, resultadoResta);

        if(segundoOperando != 0)
        {
            printf("   c) El resultado de %d/%d es: %.2f\n", primerOperando, segundoOperando, resultadoDivision);
        }else
        {
            printf("   c) No es posible dividir por cero\n");
        }

        printf("   d) El resultado de %d*%d es: %d\n", primerOperando, segundoOperando, resultadoMultiplicacion);
        printf("   e) El factorial de %d es: %d y El factorial de %d es: %d\n\n", primerOperando, resultadoFactorialA, segundoOperando, resultadoFactorialB);

    }else
    {
        if(banderaCase1 == 0 || banderaCase2 == 0)
        {
            if(banderaCase3 == 0)
            {
                printf("\n   Error! Se le debe asignar un valor a ambos operadores y calcularlos para informar los resultados!\n\n");
            }
        }else
        {
            if(banderaCase3 == 0)
            {
                printf("\n   Error! Se debe calcular los operadores para informar los resultados!\n\n");
            }
        }
    }
}
