#include "funciones.h"

void mostrarMenu(int opcionUnoCargada, int opcionDosCargada, float kmIngresados, float precioAereolineas, float precioLatam){
    printf("Menu pricipal\n");
    if(opcionUnoCargada == 0){
        printf("1. Ingresar Kil�metros (km = x)\n");// Cuidado con las tildes.
    }else{
        printf("1. Ingresar Kil�metros (km = %.2f)\n", kmIngresados);// Cuidado con las tildes.
    }
    if(opcionDosCargada == 0){
        printf("2. Ingresar Precio de Vuelos (Aerol�neas = y, Latam = z)\n");// Cuidado con las tildes.
    }else{
        printf("2. Ingresar Precio de Vuelos (Aerol�neas = %.2f, Latam = %.2f)\n", precioAereolineas, precioLatam);// Cuidado con las tildes.
    }
    printf("3. Calcular todos los costos\n");
    printf("4. Informar Resultados\n");
    printf("5. Carga forzada de datos\n"); // Esta opcion ejecuta el CALCULO y el INFORME.
    printf("6. Salir\n\n");
}

void informarResultados(
		float latamDebito,
		float latamCredito,
		float latamBitcoin,
		float latamUnitario,
		float aereolineasDebito,
		float aereolineasCredito,
		float aereolineasBitcoin,
		float aereolineasUnitario,
		float diferencia)
{
    printf("\nLatam:\n");
    printf("a) Precio con tarjeta de d�bito: %.2f\n", latamDebito);
    printf("b) Precio con tarjeta de cr�dito: %.2f\n", latamCredito);
    printf("c) Precio pagando con bitcoin : %.2f\n", latamBitcoin);
    printf("d) Precio unitario: %.2f\n\n", latamUnitario);
    printf("Aerol�neas:\n");
    printf("a) Precio con tarjeta de d�bito: %.2f\n", aereolineasDebito);
    printf("b) Precio con tarjeta de cr�dito: %.2f\n", aereolineasCredito);
    printf("c) Precio pagando con bitcoin : %.2f\n", aereolineasBitcoin);
    printf("d) Precio unitario: %.2f\n\n", aereolineasUnitario);
    printf("La diferencia de precio es : %.2f\n\n", diferencia);
}

bool parseInt(char *string, int *integer) {
	/* Tomaremos el tamanio de la cadena. */
	int length = strlen(string);
	/* 'i' sera nuestro index, que ira recorriendo cada uno de los caracteres de la cadena ingresada. */
	int i = 0;
	/* Aquellos caracteres que representan un entero seran guardados aqui. */
	char integer_buffer[BUFFER_SIZE];
	/* Aqui el indice de nuetra "cadena" en construccion. */
	int integer_chars = 0;

	/* Con la funcion "isspace" estaremos comprobando si donde esta parando nuestro indice es un espacio o no. */
	while (isspace(string[i]))
		i++;

	/* Aqui validamos en el caso qe sean espacio en blanco lo que ingreso el usuario*/
	if (length == i)
		return false;

	/* Aqui guradariasmos el signo negativo del entero*/
	if (string[i] == '-') {
		/* Si el simbolo negativo no esta acompaniado de un numero entero, entonces no es valido*/
		integer_buffer[integer_chars] = '-';
		integer_chars++;
		i++;

		/* Si el simbolo negativo no esta acompaniado de un numero entero, entonces no es valido*/
		if (!isdigit(string[i]))
			return false;
	}

	while (i < length && !isspace(string[i])) {
		/* Si encontramos un caracter que no represenata un numero, entonces es invalido */
		if (!isdigit(string[i]))
			return false;

		/* Guarda el numero encontrado en la otra cadena, el buffer */
		integer_buffer[integer_chars] = string[i];
		integer_chars++;
		i++;
	}

	/* Coloca un '\0', para cortar la cadena formada en el buffer */
	integer_buffer[integer_chars] = '\0';

	/* Para avanzar atraves de los caracteres de 'espacio' */
	while (isspace(string[i]))
		i++;

	/* Despues de haber leido el numero, si encuentra un caracter invalido, corta antes de ese caracter */
	if (string[i] != '\0')
		return false;

	/* Transforma la cadena creada en el buffer a un valor entero */
	*integer = atoi(integer_buffer);

	/* Termina el procedimiento */
	return true;
}

int pedirNumeroEntero(char mensaje[]) {
	setbuf(stdout, NULL);
	int numero = 0;
	bool parsedCorrect = true;
	char buffer[BUFFER_SIZE];

	do {
		printf(mensaje);
		/* Aqui procedo a guradar la cadena de caracteres que ingreso el usuario. */
		fgets(buffer, BUFFER_SIZE, stdin);

		/* Aqui valido si el procedimiento del "parseInt" fue un exito o no. */
		parsedCorrect = parseInt(buffer, &numero);

		/* Si el usuario ingreso "basura" se lo menciono. */
		if (!parsedCorrect)
			printf("ERROR! El valor ingresado debe ser un numero de tipo entero!\n");

	} while (!parsedCorrect);

	return numero;
}

bool parseFloat(char *string, float *nfloat) {
	/* Tomaremos el tamanio de la cadena. */
	int length = strlen(string);
	/* 'i' sera nuestro index, que ira recorriendo cada uno de los caracteres de la cadena ingresada. */
	int i = 0;
	/* Aquellos caracteres que representan un entero o un punto, seran guardados aqui. */
	char float_buffer[BUFFER_SIZE];
	/* Aqui el indice de nuetra "cadena" en construccion. */
	int float_chars = 0;
	int floating_point = 0;

	/* Con la funcion "isspace" estaremos comprobando si donde esta parando nuestro indice es un espacio o no. */
	while (isspace(string[i]))
		i++;

	/* Aqui validamos en el caso qe sean espacio en blanco lo que ingreso el usuario*/
	if (length == i){
	    //printf("Entro al if (length == i);\n");
	    return false;
	}


	/* Aqui guradariasmos el signo negativo del entero*/
	if (string[i] == '-') {
		/* Si el simbolo negativo no esta acompaniado de un numero entero, entonces no es valido*/
		float_buffer[float_chars] = '-';
		float_chars++;
		i++;

		/* Si el simbolo negativo no esta acompaniado de un numero entero, entonces no es valido*/
		if (!isdigit(string[i])){
		    //printf("Entro al if (!isdigit(string[i]))\n");
		    return false;
		}
	}

	while (i < length && !isspace(string[i])) {
		/* Si encontramos un caracter que no represenata un numero o un punto, entonces es invalido */
		if(!isdigit(string[i]) && !(string[i] == '.'))
		{
		    //printf("Entro al if (!isdigit(string[i]))\n");
			return false;
		}
		if(string[i] == '.' && floating_point == 1)
		{
		    //printf("Entro al if(string[i] == '.' && floating_point == 1)\n");
		    return false;
		}
		if(string[i] == '.')
		{
		    //printf("Entro al if(string[i] == '.')\n");
		    floating_point = 1;
		}


		/* Guarda el numero encontrado en la otra cadena, el buffer */
		float_buffer[float_chars] = string[i];
		float_chars++;
		i++;
	}

	/* Coloca un '\0', para cortar la cadena formada en el buffer */
	float_buffer[float_chars] = '\0';

	/* Para avanzar atraves de los caracteres de 'espacio' */
	while (isspace(string[i]))
		i++;

	/* Despues de haber leido el numero, si encuentra un caracter invalido, corta antes de ese caracter */
	if (string[i] != '\0'){
	    //printf("Entro en if (string[i] != 'cero, el numero')\n");
		return false;
	}

	/* Transforma la cadena creada en el buffer a un valor entero */
	*nfloat = atof(float_buffer);

	/* Termina el procedimiento */
	return true;
}

float pedirNumeroFlotante(char mensaje[]) {
	float numero = 0;
	bool parsedCorrect = true;
	char buffer[BUFFER_SIZE];

	do {
		printf(mensaje);
		/* Aqui procedo a guradar la cadena de caracteres que ingreso el usuario. */
		fgets(buffer, BUFFER_SIZE, stdin);

		/* Aqui valido si el procedimiento del "parseFloat" fue un exito o no. */
		parsedCorrect = parseFloat(buffer, &numero);

		/* Si el usuario ingreso "basura" se lo menciono. */
		if (!parsedCorrect)
			printf("ERROR! El valor ingresado debe ser un numero!\n");

	} while (!parsedCorrect);

	return numero;
}

float pedirValorNoNegativo(char mensaje[]){
	float numeroIngresado;

	do{
		numeroIngresado = pedirNumeroFlotante(mensaje);
		if(numeroIngresado < 0){
			printf("ERROR! No puede ingresar un numero negativo!\n");
		}
	}while(numeroIngresado < 0);

	return numeroIngresado;
}

float aplicarDescuento(float numero, int descuento){
    float resultado;

    resultado = (100 - descuento) * numero / 100;
    // 100% == 100
    // 25% == x = resultado
    return resultado;
}

float aplicarAumento(float numero, int aumento){
    float resultado;

    resultado = (100 + aumento) * numero / 100;
    // 100% == 100
    // 125% == x = resultado
    return resultado;
}

float bitcoinAPesos(float bitcoin, float valorBitcoin){
    float resultado;

    resultado = bitcoin * valorBitcoin;

    return resultado;
}

float pesosABitcoin(float pesos, float valorPesos){
    float resultado;

    if(valorPesos != 0){
    	resultado = pesos / valorPesos;
    }

    return resultado;
}

float calcularPrecioUnitario(float pesos, float km){
    float resultado;

    if(km != 0){
    	resultado = pesos / km;
    }

    return resultado;
}

float calcularDiferencia(float valorUno, float valorDos){
    float resultado;

    resultado = valorUno - valorDos;

    if(resultado < 0){
    	resultado = resultado * (-1);
    }

    return resultado;
}
