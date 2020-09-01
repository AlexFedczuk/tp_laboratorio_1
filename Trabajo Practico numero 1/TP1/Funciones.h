#include <stdio.h>


/** \brief Mostrar el menu de opciones de la calculadora
 *
 * \param banderaPrimerOperando sera utilizada para saber
          que tipo de mensaje debe mostrarse
 * \param primerOperando el numero a ser mostrado en el
          mensaje
 * \param banderaSegundoOperando sera utilizada para saber
          que tipo de mensaje debe mostrarse
 * \param segundoOperando el numero a ser mostrado en el
          mensaje
 * \return void
 *
 */
void MostrarMenu(int banderaPrimerOperando, int primerOperando, int banderaSegundoOperando, int segundoOperando);

/** \brief Tomar la opcion elegida por el usuario en el
           menu de la calculadora
 *
 * \param opcionElegida la opcion elegida por el usuario
 * \return Devuelve el numero entero ingresado por el usuario
 *
 */
int TomarOpcionElegida(int opcionElegida);

/** \brief Pedirle al usuario un numero entero
 *
 * \param mensaje[30] char El mensaje a mostrar
          al usuario para instruirlo
 * \return int El numero ingresado por el usuario
 *
 */
int PedirNumeroEntero(char mensaje[30]);

/** \brief Hace la logica de bandera necesaria,
           para los case del programa
 *
 * \param banderaOperando int la bandera con la cual trabajar
 * \return int Devuelve en el estado que debe estar la bandera
 *
 */
int HacerLogicaBanderaOperador(int banderaOperando);

/** \brief Sumar dos enteros y devolver el resultado
 *
 * \param primerOperador int
 * \param segundoOperador int
 * \return El resultado de la suma realizada
 *
 */
int SumarDosEnteros(int primerOperador, int segundoOperador);

/** \brief Restar dos enteros y devolver el resultado
 *
 * \param primerOperador int
 * \param segundoOperador int
 * \return El resultado de la resta
 *
 */
int RestarDosEnteros(int primerOperador, int segundoOperador);

/** \brief Multiplicar dos enteros y devolver el resultado
 *
 * \param primerOperador int
 * \param segundoOperador int
 * \return El resultado de la multiplicacion realizada
 *
 */
int MultiplicarDosEnteros(int primerOperador, int segundoOperador);

/** \brief Dividir dos enteros  y devolver el resultado, evitando divisiones por cero
 *
 * \param primerOperador int
 * \param segundoOperador int
 * \return El resultado de la operacion realizada
 *
 */
float DividirDosEnteros(int primerOperador, int segundoOperador);

/** \brief Factorizar un numero entero y devolver el resultado
 *
 * \param operador int
 * \return El resultado de la factorizacion de el entero
 *
 */
int FactorizarUnEntero(int operador);
