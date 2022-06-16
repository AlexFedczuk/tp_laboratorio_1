/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"


int main(void)
{
	setbuf(stdout, NULL); // hay que probar ahora!

	//startTesting(1);  // ll_newLinkedList, 100%.
	//startTesting(2);  // ll_len, 100%.
	//startTesting(3);  // getNode - test_getNode
	//startTesting(4);  // addNode - test_addNode
	//startTesting(5);  // ll_add
	startTesting(6);  // ll_get 40%, 3 errores.
	//startTesting(7);  // ll_set 50%, Error en el valor de retorno de <get> al solicitar el primer elemento steado con <set>.
	//startTesting(8);  // ll_remove 60%, Error en el valor de retorno de <get> al solicitar un elemento luego de eliminar su antecesor.
	//startTesting(9);  // ll_clear 66%, Error en el valor de retorno de <get> al solicitar un elemento luego de eliminar sus antecesores con <clear>.
	//startTesting(10); // ll_deleteLinkedList 100%.
	//startTesting(11); // ll_indexOf 50%, Error en el valor de retorno de <indexOf> si los parametros son correctos y el elemento esta contenido se debe retornar la posicion del elemento.
	//startTesting(12); // ll_isEmpty 50%, Error en el valor de retorno de <isEmpty> si los parametros son correctos y la lista tiene elementos debe retornar 0.
	//startTesting(13); // ll_push 40%, 3 errores.
	//startTesting(14); // ll_pop  40%, 3 errores.
	//startTesting(15); // ll_contains 66%, Error en el valor de retorno de <contains> si los parametros son correctos y contiene el elemento debe retornar 1.
	//startTesting(16); // ll_containsAll 75%, Error en el valor de retorno <containsAll> si la lista2 no esta contenida se debe retornar 0.
	//startTesting(17); // ll_subList 75%, Error en el valor de retorno de <subList> el to esta fuera de indice (> len()), se deberia retornar NULL.
	//startTesting(18); // ll_clone 100%.
	//startTesting(19); // ll_sort 80%, Error al intentar obtener un elemento luego de ordenar

    return 0;
}
