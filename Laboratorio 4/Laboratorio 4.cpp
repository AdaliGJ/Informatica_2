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
		valores[i] = fibonacciAux(i);
	}

}

//Ejercicio #4
int fibonacciAux2(int n) {
	int n0 = 0;
	int n1 = 1;
	int nc;

	for (int i = 0; i < n; i++) {
		nc = n0 + n1;
		n0 = n1;
		n1 = nc;
	}
	return n0;
}

void fibonacciN2(const int n, int* valores) {

	for (int i = 0; i < n; i++) {
		valores[i] = fibonacciAux2(i);
	}

}


int main()
{

	//Prueba Ejercicio #1
	int vector[10];
	divisionSegura(40, 5, vector);
	std::cout << *vector << "\n";

	//Prueba Ejercicio #2
	int vector2[] = { 1,3,2,4,8,5,6,7 };
	int vector21[10];
	int* respuesta1 = &vector21[0];
	int** respuesta2 = &respuesta1;
	sumaMayor(vector2, 8, respuesta2);

	//Prueba Ejercicio #3
	int vector3[10];
	fibonacciN(10, vector3);
	std::cout << vector3[5] << "\n";

	//Prueba Ejercicio #4
	int vector4[1000];
	fibonacciN(1000, vector4);
	std::cout << vector4[5];

}