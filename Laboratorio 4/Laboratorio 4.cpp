#include <stdio.h>
#include <iostream>

//Ejercicio #1
bool divisionSegura(int numerador, int denominador, int* respuesta) {
	if (denominador != 0) {

		int resultado = (numerador / denominador);
		*respuesta = resultado;//Guarda el resultado de la división en el puntero

		return true;
	}
	else {

		return false;
	}
}

//Ejercicio #2
int* mayor(int valores[], int cantidad) {//Encuentra la posición del valor mayor del arreglo
	int* valorMayor = &valores[0];

	for (int i = 0; i < cantidad; i++) {
		if (valores[i] > *valorMayor) {
			valorMayor = &valores[i];
		}
	}
	return valorMayor;
}

int* mayor2(int valores[], int cantidad) {//Encuentra la posición del segundo valor mayor del arreglo
	int* segundoMayor = &valores[0];

	for (int i = 0; i < cantidad; i++) {
		if ((valores[i] > *segundoMayor) && (&valores[i] != mayor(valores, cantidad))) {
			segundoMayor = &valores[i];
		}
	}
	return segundoMayor;
}

bool sumaMayor(int valores[], int cantidad, int** respuesta) {
	if (cantidad > 1) {

		respuesta[0] = mayor(valores, cantidad);//Guarda en el índice 0, la posición del valor mayor del arreglo
		respuesta[1] = mayor2(valores, cantidad);//Guarda en el índice 1, la posición del segundo valor mayor del arreglo

		return true;
	}
	else {
		return false;
	}
}


//Ejercicio #3
int fibonacciAux(int n) {//Función auxiliar que calcula el n-simo fibonacci
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return ((fibonacciAux(n - 1)) + (fibonacciAux(n - 2)));
	}
}

void fibonacciN(const int n, int* valores) {

	for (int i = 0; i < n; i++) {
		valores[i] = fibonacciAux(i);//Almacena cada fibonacci en una posición
	}

}

//Ejercicio #4
void fibonacciN2(const int n, int* valores) {//Función optimizada, no necesita una auxiliar 
	if (n == 0) {
		valores[0] = 0;  //Solo se guarda el fibonacci 0
	}
	else if (n == 1) {
		valores[0] = 0;   //Solo se guardan el fibonacci 0 y el 1
		valores[1] = 1;
	}
	else {
		valores[0] = 0; //Para todos los demás n
		valores[1] = 1;

		for (int i = 2; i <= n; i++) {//Se almacenan los números al momento de calcular, en lugar de guardar luego de calcular
			valores[i] = (valores[i - 1] + valores[i - 2]);
		}
	}
}


int main()
{

	//Prueba Ejercicio #1
	int vector[10];
	divisionSegura(40, 5, vector);
	std::cout << "El resultado de la división 40/5 almacenado en " << vector << " es " << *vector << "\n";

	//Prueba Ejercicio #2
	int vector2[] = { 1,3,2,4,8,5,6,7 };
	int vector2_1[10];
	int* respuesta1 = &vector2_1[0];
	int** respuesta2 = &respuesta1;
	sumaMayor(vector2, 8, respuesta2);
	std::cout << sumaMayor(vector2, 8, respuesta2) << " Los números mayores del arreglo son " << *mayor(vector2, 8) << " y " << *mayor2(vector2, 8) << "\n";


	//Prueba Ejercicio #3
	int vector3[10];
	fibonacciN(10, vector3);
	std::cout << "El fibonacci almacenado en el índice 5 es " << vector3[6] << "\n"; //0,1,1,2,3,5,8, el resultado debe ser 8, tomando en cuenta que 0 es el índice 0

	//Prueba Ejercicio #4
	int vector4[10000];//Almacena 10000 fibonacci
	fibonacciN2(10000, vector4);
	std::cout << "El fibonacci almacenado en el índice 25 es " << vector4[25];
}