/*
											Laboratorio # 2

Jeremy Cáceres
Adalí Garrán

*/

#include <stdio.h>
#include <iostream>


using namespace std;

//Ejercicio #1: función que determine si un número es primo o no (recursión)
bool esPrimo(int n1, int contador = 2)//La función toma como parámetro un entero y un contador que inicia en 2
{
	if (n1 == 1)//se toma 1 como un número no primo
	{
		return false;
	}
	else if (n1 == 2)
	{
		return true;
	}
	else if (n1 % contador == 0)
	{
		return false;
	}
	else if (contador == n1 - 1)//un número primo es divisible entre 1 y él mismo, por ello, para 1 antes de n1
	{
		return true;
	}
	else
	{
		return esPrimo(n1, (contador + 1));//La función se llama recursivamente para verificar si es primo o no aumentando el contador
	}
}

//Ejercicio #2: función que determine si un número es primo o no (ciclos)
bool esPrimoCiclica(int n1, int contador = 2) {
	while (contador < n1) {//Condición en el while, el contador no puede superar a n1
		if (n1 == 1)
		{
			return false;
		}
		else if (n1 == 2)
		{
			return true;
		}
		else if (n1 % contador == 0)
		{
			return false;
		}
		else if (contador == n1 - 1)
		{
			return true;
		}
		else
		{
			contador++;//La función no se llama recursivamente, simplemente se indica que aumenta el contador
		}
	}	
}

//Ejercicio #3: función que determina el n-simo número primo (recursión)
int obtenerPrimoRec(int n, int cnt1 = 0, int cnt2 = 1) {
	/*el cnt1 se utilizará para contar el número de primos hasta n	
	  el cnt2 es el valor del que se comprobará si es primo o no*/
	
	if (cnt1 != n) 
	{
		if (esPrimo(cnt2)) {
			return obtenerPrimoRec(n, (cnt1 + 1), (cnt2 + 1));
		}
		else 
		{
			return obtenerPrimoRec(n, cnt1, (cnt2 + 1));
		}// si cnt2 es primo, se suma 1 al contador 1, sino no
	}
	else 
	{
		return cnt2 - 1; //se resta 1 a cnt2, porque durante la última recusión, se le sumó 1
	}
}

//Ejercicio #4: función que determina el n-simo número primo (ciclos)
int obtenerPrimoCiclico(int n, int cnt1 = -1, int cnt2 = 1) {
	while (cnt1 <= n)
	{
		if (cnt1 < n)
		{
			if (esPrimo(cnt2))
			{
				cnt1++ && cnt2++;
			}
			else
			{
				cnt2++;
			}
		}
		else
		{
			return cnt2 - 1;
		}
	}
}

//La función main contiene pruebas de las funciones definidas
int main()
{//Prueba función número 1, resultado es False
	if (esPrimo(8)) {
		printf("True, el numero es primo\n\n");

	}
	else {
		printf("False, el numero no es primo\n\n");
	}


//Prueba función número 2, resultado es True
	if (esPrimoCiclica(7)) {
		printf("True, el numero es primo\n\n");

	}
	else {
		printf("False, el numero no es primo\n\n");
	}
	 
//Prueba función 3, retorna 541: hay (100 - 1) primos antes de 541
		printf("%i \n\n", obtenerPrimoRec(100));

//Prueba función 4, retorna 2: hay (1 - 1) primos antes de 2
		printf("%i \n\n", obtenerPrimoCiclico(1));


	char x;
	std::cin >> x;

	return 0;

}
