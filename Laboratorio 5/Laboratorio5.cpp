#include <iostream>
#include <math.h>


//Ejercicio #1

	//Función principal: crea una copia del puntero "valores"
int* copiar(int* valores, int cantidad) {

	int tamano = sizeof(int)*cantidad;

	int* arreglo2 = (int*)malloc(tamano);//Reserva memoria

	for (int i = 0; i < cantidad; i++) {
		arreglo2[i] = valores[i];//copia todos los elementos de valores en respuesta
	}
	return arreglo2;
}

//Ejercicio #2

	//Función auxiliar que determina si un número es primo o no
bool esPrimo(int n1, int contador = 2) {
	if (n1 == 1) {
		return false;
	}
	else if (n1 == 2) {
		return true;
	}
	else if (n1 % contador == 0) {
		return false;
	}
	else if (contador == n1 - 1) {
		return true;
	}
	else {
		return esPrimo(n1, (contador + 1));
	}
}
//Función auxiliar que determina la cantidad de números primos menores a n
int nPrimos(int n) {
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (esPrimo(i)) {
			c++;
		}
		else {
			c;
		}
	}
	return c;
}

//Función principal: guarda los primos menores a máximo en un puntero
int* primos(const int maximo) {
	int tamano = sizeof(int)*(nPrimos(maximo));

	int* arreglo = (int*)malloc(tamano);
	int contador = 0;

	for (int i = 2; i < maximo; i++) {
		if (esPrimo(i)) {
			arreglo[contador] = i;//Solo guardará el número si es primo
			contador++;
		}
	}
	return arreglo;
}


//Ejercicio #3
float distanciaE(int x, int y) {
	float resultado = (sqrt((pow((x - 0), 2)) + (pow((y - 0), 2))));//Fórmula de distancia euclideana

	return resultado;
}

//Función auxiliar que determina si la distancia es menor a la establecida
bool esMenor(int* vectores, int distancia) {
	int x = vectores[0];
	int y = vectores[1];

	if (distanciaE(x, y) < distancia) {
		return true;
	}
	else {
		return false;
	}
}

//Función auxiliar que determina la cantidad de vectores que cumplen con la condición
int contadorVec(int** vectores, const int cantidad, const int distancia) {
	int c = 0;

	for (int i = 0; i < cantidad; i++) {
		if (esMenor(vectores[i], distancia)) {
			c++;
		}
	}
	return c;
}

//Función principal: guarda los vectores con distancia entre ellos y (0,0) menor a "distancia"
int** vectoresCercanos(int** vectores, const int cantidad, const int distancia) {

	int tamanoVect = sizeof(int) * 2; //El espacio que ocupará cada vector
	int tamanoVecVec = contadorVec(vectores, cantidad, distancia); //Cantidad de vectores que cumplen con la condición

	int** arreglo = (int**)malloc(tamanoVect*tamanoVecVec);//se reservará el espacio del tamaño de cada vector (2*int) por la cantidad de vectores que contendrá

	int c = 0;

	for (int i = 0; i < cantidad; i++) {
		if (esMenor(vectores[i], distancia)) {//solo guardará el vector si la distancia euclideana es menor a distancia
			arreglo[c] = vectores[i];
			c++;
		}
	}
	return arreglo;
}


int main()
{

	//Prueba ejercicio #1
	int arreglo[] = { 1,6,3 };

	int* copia = copiar(arreglo, 3);//Guardar la función con valores en una variable

	printf("Los elementos de la copia son: %i, %i, %i\n", copia[0], copia[1], copia[2]);
	//imprime 1,6,3: exactamente los mismos elementos de arreglo[]

	//Prueba ejercicio #2
	int* nPrim = primos(8); //Guardar la función con valores en una variable

	printf("Los primos menores a 8 son: %i,%i,%i,%i \n", nPrim[0], nPrim[1], nPrim[2], nPrim[3]);//imprime 2,3,5,7

	//Prueba ejercicio #3
	int vec[] = { 1,2 };
	int vec2[] = { 5,8 };
	int vec3[] = { 3,4 };

	int *vecTot[] = { vec, vec2, vec3 }; //Arreglo de vectores

	int** vecvec = vectoresCercanos(vecTot, 3, 6);//Guardar la función con valores en una variable

	printf("Los vectores cuya distancia con (0,0) es menor a 6 son: (%i,%i), (%i,%i)", vecvec[0][0], vecvec[0][1], vecvec[1][0], vecvec[1][1]);
	//Imprime (1,2) y (3,4) porque su distancia con (0,0) es menor a 6.
	//El segundo vector del **vecTot es {5,8}, pero se ve que no se imprime porque la distancia es mayor a 6.

	return 0;
}