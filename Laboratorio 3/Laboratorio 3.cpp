#include <iostream>
#include <bits/stdc++.h>

using namespace std;


//Ejercicio #1
void imprimirBinario(int i, int contador = 0) {

	if (contador < 32) {
		if (i % 2 == 0) {
			imprimirBinario((i / 2), (contador + 1));//se llama recursivamente antes del imprimir el valor para que el binario aparezca en el orden correcto
			printf("0");//Si el número es divisible entre dos imprime 0
		}
		else {
			imprimirBinario(((i - 1) / 2), (contador + 1));
			printf("1");//Si el número no es divisible entre dos imprime 1
		}
	}
	else {
		printf(" ");
	}

}

//Ejercicio #2: True si los bits del char aparecen en alguna parte del long en el mismo orden
bool existe(char valor, long numero) {

	int contador = 0;

	while (contador < 64) {
		if ((valor & numero) == valor) {
			return true;
		}
		else {
			numero >>= 1;
			contador++;
		}
	}
	return false;
}


//Ejercicio #3: Contar bits activos en un long
short conteo(long numero, int contador = 0) {
	while (contador < 64) {
		if (numero % 2 == 0) {
			return conteo((numero / 2), (contador + 1)); //si el número es divisible entre dos, no se suma al resultado
		}
		else {
			return 1 + (conteo(((numero - 1) / 2), (contador + 1))); //si el número es divisible no entre dos, se suma 1 al resultado
		}
	}
}

//Ejercicio #4: aplicar And a bits pares y Or a bits impares
int andOr(int valor1, int valor2)
{
	//Obtener los bits pares de valor 1 y 2, 0xAAAAAAAA es un número con 0 en los bits impares 
	int pares_bits1 = valor1 & 0xAAAAAAAA;
	int pares_bits2 = valor2 & 0xAAAAAAAA;

	//Obtener los bits impares de valor 1 y 2, 0x55555555 es un número con 0 en los bits pares  
	int impares_bits1 = valor1 & 0x55555555;
	int impares_bits2 = valor2 & 0x55555555;

	int bitsPares = (pares_bits1 & pares_bits2);//Aplicar and a los bits pares
	int bitsImpares = (impares_bits1 | impares_bits2);//Aplicar or a los bits impares

	return (bitsPares | bitsImpares); //Combinar pares con impares
}

//Ejercicio #5: Construir un int a partir de los bits de 4 chars
int codificar(char c1, char c2, char c3, char c4) {

	int resultado = 0;

	resultado = resultado | c4;//bits 24-31
	resultado = resultado << 8;//correr resultado 8 bits a la izquierda

	resultado = resultado | c3;//bits 16-23
	resultado = resultado << 8;//correr resultado 8 bits a la izquierda

	resultado = resultado | c2;//bits 8-15
	resultado = resultado << 8;//correr resultado 8 bits a la izquierda

	resultado = resultado | c1;//bits 0-7

	return resultado;//8 + 8 + 8 + 8 = 32 bits
}


int main()
{
	//Pruebas de las funciones

	cout << "El número 32 en binario es "; imprimirBinario(32); printf("\n");//0000 0000 0000 0000 0000 0000 0010 0000
	cout << "¿Existe 8 en 456? = " << existe(9, 456) << "\n"; // retorna 1 = True. 9 (1001) está en 456 (0001 1[100 1]000)
	cout << "El número 56 tiene " << conteo(56) << " bits \n"; // retorna 3
	cout << "andOr entre 45 y 86 retorna " << andOr(45, 86) << "\n"; //retorna 85
	cout << codificar(1, 2, 3, 4) << "\n"; //retorna 0000 0100 0000 0011 0000 0010 0000 0001 = 67,305,985

	char x;
	std::cin >> x;

	return 0;
}