/*******************************************************************************************

    Apellido y nombre: Fedczuk Alex

    Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
    1. Ingresar 1er operando (A=x)
    2. Ingresar 2do operando (B=y)
    3. Calcular todas las operaciones
        a) Calcular la suma (A+B)
        b) Calcular la resta (A-B)
        c) Calcular la division (A/B)
        d) Calcular la multiplicacion (A*B)
        e) Calcular el factorial (A!)
    4. Informar resultados
        a) “El resultado de A+B es: r”
        b) “El resultado de A-B es: r”
        c) “El resultado de A/B es: r” o “No es posible dividir por cero”
        d) “El resultado de A*B es: r”
        e) “El factorial de A es: r1 y El factorial de B es: r2”
    5. Salir

    • Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
    que contenga las funciones para realizar las cinco operaciones.
    • En el menú deberán aparecer los valores actuales cargados en los operandos A y B
    (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
    • Deberán contemplarse los casos de error (división por cero, etc)
    • Documentar todas las funciones


********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int primerOperando;
    int segundoOperando;
    int opcionElegida;
    int banderaPrimerOperando;
    int banderaSegundoOperando;
    int banderaCase1;
    int banderaCase2;
    int banderaCase3;

    int resultadoSuma;
    int resultadoResta;
    int resultadoMultiplicacion;
    float resultadoDivision;
    int resultadoFactorialA;
    int resultadoFactorialB;

    banderaPrimerOperando = 0;
    banderaSegundoOperando = 0;
    banderaCase1 = 0;
    banderaCase2 = 0;
    banderaCase3 = 0;

    resultadoFactorialA = 1;
    resultadoFactorialB = 1;

    do
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

        switch(opcionElegida)
            {
                case 1:
                    printf("\n   Ingrese el primer operando: ");
                    scanf("%d", &primerOperando);

                    if(banderaPrimerOperando == 0)
                    {
                        banderaPrimerOperando = 1;
                    }

                    banderaCase1 = 1;
                    break;

                case 2:
                    printf("\n   Ingrese el segundo operando: ");
                    scanf("%d", &segundoOperando);

                    if(banderaSegundoOperando == 0)
                    {
                        banderaSegundoOperando = 1;
                    }

                    banderaCase2 = 1;
                    break;

                case 3:
                    if(banderaCase1 == 1 && banderaCase2 == 1)
                    {
                        resultadoSuma = primerOperando + segundoOperando;
                        resultadoResta = primerOperando - segundoOperando;
                        resultadoMultiplicacion = primerOperando * segundoOperando;
                        if(segundoOperando != 0)
                        {
                            resultadoDivision = (float)primerOperando / segundoOperando;
                        }

                        for(int i = 1; i <= primerOperando; i++)
                        {
                            resultadoFactorialA = resultadoFactorialA * i;
                        }

                        for(int i = 1; i <= segundoOperando; i++)
                        {
                            resultadoFactorialB = resultadoFactorialB * i;
                        }

                        banderaCase3 = 1;
                    }else
                    {
                        printf("Error! Se le debe asignar un valor a ambos operandos para calcularlos!");
                    }
                    break;

                case 4:
                    if(banderaCase1 == 1 && banderaCase2 == 1 && banderaCase3)
                    {
                        printf("\na) El resultado de %d+%d es: %d\n", primerOperando, segundoOperando, resultadoSuma);
                        printf("b) El resultado de %d-%d es: %d\n", primerOperando, segundoOperando, resultadoResta);

                        if(segundoOperando != 0)
                        {
                            printf("c) El resultado de %d/%d es: %.2f\n", primerOperando, segundoOperando, resultadoDivision);
                        }else
                        {
                            printf("No es posible dividir por cero\n");
                        }

                        printf("d) El resultado de %d*%d es: %d\n", primerOperando, segundoOperando, resultadoMultiplicacion);
                        printf("e) El factorial de %d es: %d y El factorial de %d es: %d", primerOperando, resultadoFactorialA, segundoOperando, resultadoFactorialB);
                    }else
                    {
                        printf("Error! Se le debe asignar un valor a ambos operandos y calcularlos!");
                    }
                    break;

                default:
                    break;

            }

            system("pause");
            system("cls");
    }
    while(opcionElegida != 5);

    return 0;
}

// Te quedaste en el caso 4 antes de cortar... fijate de volver a revisar los IF, por un tema de eficiencia!

//Probando lalala
