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
                        resultadoFactorialA = FactorizarUnEntero(primerOperando);
                        resultadoFactorialB = FactorizarUnEntero(segundoOperando);

                        if(banderaCase3 == 0)
                        {
                            banderaCase3 = 1;
                        }else
                        {
                            if(banderaCase3 == 1)
                            {
                                banderaCase3 = 0;
                            }
                        }

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
