/*
											Laboratorio # 2

Jeremy C�ceres
Adal� Garr�n

*/

#include <stdio.h>
#include <iostream>


using namespace std;

//Ejercicio #1: funci�n que determine si un n�mero es primo o no (recursi�n)
bool esPrimo(int n1, int contador = 2)//La funci�n toma como par�metro un entero y un contador que inicia en 2
{
	if (n1 == 1)//se toma 1 como un n�mero no primo
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
	else if (contador == n1 - 1)//un n�mero primo es divisible entre 1 y �l mismo, por ello, para 1 antes de n1
	{
		return true;
	}
	else
	{
		return esPrimo(n1, (contador + 1));//La funci�n se llama recursivamente para verificar si es primo o no aumentando el contador
	}
}

//Ejercicio #2: funci�n que determine si un n�mero es primo o no (ciclos)
bool esPrimoCiclica(int n1, int contador = 2) {
	while (contador < n1) {//Condici�n en el while, el contador no puede superar a n1
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
			contador++;//La funci�n no se llama recursivamente, simplemente se indica que aumenta el contador
		}
	}	
}

//Ejercicio #3: funci�n que determina el n-simo n�mero primo (recursi�n)
int obtenerPrimoRec(int n, int cnt1 = 0, int cnt2 = 1) {
	/*el cnt1 se utilizar� para contar el n�mero de primos hasta n	
	  el cnt2 es el valor del que se comprobar� si es primo o no*/
	
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
		return cnt2 - 1; //se resta 1 a cnt2, porque durante la �ltima recusi�n, se le sum� 1
	}
}

//Ejercicio #4: funci�n que determina el n-simo n�mero primo (ciclos)
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

//La funci�n main contiene pruebas de las funciones definidas
int main()
{//Prueba funci�n n�mero 1, resultado es False
	if (esPrimo(8)) {
		printf("True, el numero es primo\n\n");

	}
	else {
		printf("False, el numero no es primo\n\n");
	}


//Prueba funci�n n�mero 2, resultado es True
	if (esPrimoCiclica(7)) {
		printf("True, el numero es primo\n\n");

	}
	else {
		printf("False, el numero no es primo\n\n");
	}
	 
//Prueba funci�n 3, retorna 541: hay (100 - 1) primos antes de 541
		printf("%i \n\n", obtenerPrimoRec(100));

//Prueba funci�n 4, retorna 2: hay (1 - 1) primos antes de 2
		printf("%i \n\n", obtenerPrimoCiclico(1));


	char x;
	std::cin >> x;

	return 0;

}
