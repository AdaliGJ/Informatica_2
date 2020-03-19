#include <iostream>
#include <math.h>

using namespace std;

//Laboratorio #6
//Adalí Garrrán y Jeremy Cáceres

struct Lista
{
	int valor;
	Lista *resto;
};

//Problema #1

Lista *crear(const int *valores, const int cantidad) {//Crea una Lista a partir de un array de ints

	Lista *lista = (Lista*)malloc(sizeof(Lista)*cantidad);
	if (cantidad == 0) {
		return nullptr;
	}
	else {
		for (int i = 0; i < cantidad; i++) {
			lista[i].valor = valores[i];//El elemento valor de cada nodo de la lista

			if (i <= cantidad - 2) {
				lista[i].resto = &lista[i + 1];//El elemento resto de la lista, es igual a todo lo que se encuentra en la posición del siguiente índice de la lista
			}
			else {
				lista[cantidad - 1].resto = nullptr; //Si ya no hay elementos en el array, el resto de la lista es nullptr. 
			}
		}
	}
	return lista;
}


//Problema #2

void eliminar(Lista* valores) {//Elimina una lista

	while (valores != nullptr) {
		delete &valores->valor;//Elimina el puntero
		valores = valores->resto;
	}
	delete valores;
}


//Promblema #3

void unir(Lista* primera, Lista* segunda) {//Une dos listas en una sola
	Lista* aux;
	if (primera == nullptr) {
		primera = segunda;
	}
	else {
		if (segunda != nullptr) {
			aux = primera;
			while (aux->resto != nullptr) {
				aux = aux->resto;
			}
			aux->resto = segunda;
		}
	}
}

// Problema #4

int longitud(const Lista* valores) {//cuenta la cantidad de elementos en una lista
	int contador = 1;
	if (valores->resto == nullptr) {
		return 0;
	}

	else {

		while (valores->resto != nullptr) {
			contador++;
			valores = valores->resto;
		}

		return contador;
	}
}

//Problema #5

bool lookup(const Lista* valores, const int indice, int& resultado) {
	int contador = longitud(valores);
	int i = indice;

	if (i >= contador) {
		return false;
	}
	else {
		while (0 < i) {
			i--;
			valores = valores->resto;
		}
		resultado = valores->valor;
		return true;
	}
}

//Problema #6

struct Triangulo {//Son 3 vértices
	int p1[2];
	int p2[2];
	int p3[2];
};

struct ListaTriangulos {
	Triangulo primero;
	ListaTriangulos* resto;
};

//Problema #7

float lado1(Triangulo triangulo) {//Longitud lado 1

	float x2 = pow((triangulo.p1[0] - triangulo.p2[0]), 2);
	float y2 = pow((triangulo.p1[1] - triangulo.p2[1]), 2);

	float resultado = sqrt(x2 + y2);

	return resultado;
}

float lado2(Triangulo triangulo) {//Longitud lado 2

	float x2 = pow((triangulo.p1[0] - triangulo.p3[0]), 2);
	float y2 = pow((triangulo.p1[1] - triangulo.p3[1]), 2);

	float resultado = sqrt(x2 + y2);

	return resultado;
}

float lado3(Triangulo triangulo) {//Longitud lado 3

	float x2 = pow((triangulo.p2[0] - triangulo.p3[0]), 2);
	float y2 = pow((triangulo.p2[1] - triangulo.p3[1]), 2);

	float resultado = sqrt(x2 + y2);

	return resultado;
}


float area(const Triangulo& triangulo) {
	//Utilizando fórmula de Herón (área de un triangulo con la longitud de los lados)

	float s = (lado1(triangulo) + lado2(triangulo) + lado3(triangulo)) / 2;

	float areat = sqrt(s*(s - lado1(triangulo))*(s - lado2(triangulo))*(s - lado3(triangulo)));

	return areat;
}

//Problema #8

int contarTriangulos(const ListaTriangulos* valores) {//Aux, será el número de triangulos por el que se divide la suma de la áreas
	int contador = 1;
	if (valores->resto == nullptr) {
		return 0;
	}
	else {

		while (valores->resto != nullptr) {
			contador++;
			valores = valores->resto;
		}

		return contador;
	}
}

float areaPromedio(const ListaTriangulos* triangulos) {//Función principal
	int cantidad = contarTriangulos(triangulos);

	float sumas = 0;

	for (int i = 0; i < cantidad; i++) {
		sumas = sumas + area(triangulos->primero);
		triangulos = triangulos->resto;
	}

	float promedio = sumas / cantidad;
	return promedio;
}



int main()
{
	Lista lista;//Lista dada
	lista.valor = 1;
	lista.resto = (Lista*)malloc(sizeof(Lista));

	lista.resto->valor = 2;
	lista.resto->resto = nullptr;

	Lista* lista2 = &lista;

	//Prueba ejercicio #4: se porbará esta función primero porque servirá para probar otras
	printf("la longitud de la lista dada es %i\n", longitud(lista2));//muestra dos como resultado

	//Prueba ejercicio #1
	int arreglo[3];//definir un arreglo
	arreglo[0] = 1;
	arreglo[1] = 2;
	arreglo[2] = 3;

	Lista* creada = crear(arreglo, 3);//llamar a la función crear
	printf("la longitud de la lista creada es %i\n", longitud(creada));//muestre 3, por lo que se creó la lista con los 3 elementos


	//Prueba ejercicio #3
	Lista lista3;//crear otra lista para unirla a la primera
	lista3.valor = 3;
	lista3.resto = (Lista*)malloc(sizeof(Lista));

	lista3.resto->valor = 4;
	lista3.resto->resto = nullptr;

	Lista* lista4 = &lista3;


	unir(lista2, lista4);//lamar a la función
	printf("La longitud de la nueva lista es %i\n", longitud(lista2));//imprime el número 4 (2 elementos de cada lista)

	//Prueba ejercicio #5
	int r1;
	int r2;

	lookup(lista2, 0, r1);
	lookup(lista4, 1, r2);
	printf("El ínidce 0 de la primera lista es %i y el índice 1 de la segunda es %i\n", r1, r2);

	//Prueba ejercicio #7
	Triangulo triangulo;//Definir un triangulo
	triangulo.p1[0] = 0;
	triangulo.p1[1] = 0;
	triangulo.p2[0] = 0;
	triangulo.p2[1] = 5;
	triangulo.p3[0] = 3;
	triangulo.p3[1] = 0;

	cout << "El area del triangulo es: " << area(triangulo) << "\n";//El área es 7.5 según la fórmula


	//Prueba ejercicio #8
	Triangulo triangulo2;//Definir otro
	triangulo2.p1[0] = 0;
	triangulo2.p1[1] = 0;
	triangulo2.p2[0] = 0;
	triangulo2.p2[1] = 9;
	triangulo2.p3[0] = 3;
	triangulo2.p3[1] = 0;


	ListaTriangulos triangulos;//definir una lista de triangulos 
	triangulos.primero = triangulo;
	triangulos.resto = (ListaTriangulos*)malloc(sizeof(ListaTriangulos));

	triangulos.resto->primero = triangulo2;
	triangulos.resto->resto = nullptr;

	ListaTriangulos* listaT = &triangulos;

	printf("El área promedio de los triangulos es: %f\n", areaPromedio(listaT));//retorna 10.5 porque, A1 = 7.5, A2 = 13.5.


	//Prueba ejercicio #2
	cout << &lista3 << "\n\n";//posición inicial
	eliminar(lista4);
	cout << &lista3 << "\n\n";//La lista ya no existe, por eso esta parte muestra error
	return 0;
}