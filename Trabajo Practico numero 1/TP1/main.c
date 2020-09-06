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
#include "Funciones.h"
#include "operacionesMatematicas.h"

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
        MostrarMenu(banderaPrimerOperando,
                    primerOperando,
                    banderaSegundoOperando,
                    segundoOperando);

        opcionElegida = TomarOpcionElegida(opcionElegida);

        switch(opcionElegida)
            {
                case 1:
                    primerOperando = PedirNumeroEntero("\n   Ingrese el primer operando: ");
                    banderaPrimerOperando = HacerLogicaBanderaOperador(banderaPrimerOperando);
                    banderaCase1 = 1;
                    break;

                case 2:
                    segundoOperando = PedirNumeroEntero("\n   Ingrese el segundo operando: ");
                    banderaSegundoOperando = HacerLogicaBanderaOperador(banderaSegundoOperando);
                    banderaCase2 = 1;
                    break;

                case 3:
                    if(banderaCase1 == 1 && banderaCase2 == 1)
                    {
                        resultadoSuma = SumarDosEnteros(primerOperando, segundoOperando);
                        resultadoResta = RestarDosEnteros(primerOperando, segundoOperando);
                        resultadoMultiplicacion = MultiplicarDosEnteros(primerOperando, segundoOperando);
                        resultadoDivision = DividirDosEnteros(primerOperando, segundoOperando);
                        resultadoFactorialA = FactorizarUnEntero(primerOperando); //FactorizarUnEntero(primerOperando);
                        resultadoFactorialB = FactorizarUnEntero(segundoOperando); //FactorizarUnEntero(segundoOperando);

                        banderaCase3 = 1;
                    }else
                    {
                        printf("\n   Error! Se le debe asignar un valor a ambos operadores para calcularlos!\n\n");
                    }
                    break;

                case 4:
                    mostrarResultados(banderaCase1,
                                      banderaCase2,
                                      banderaCase3,
                                      primerOperando,
                                      segundoOperando,
                                      resultadoSuma,
                                      resultadoResta,
                                      resultadoDivision,
                                      resultadoMultiplicacion,
                                      resultadoFactorialA,
                                      resultadoFactorialB);
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

// Quedaria por terminar de revisar el problema del factoreo, cuando se desborda la variable!
