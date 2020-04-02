//Laboratorio #8
//Jeremy Cáceres y Adalí Garrán

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>

using namespace std;


//Ejercicio #1 
float parseFloat(const string& real) {

	//strtof: función ya existente para convertir un string en float
	float resultado = strtof(real.c_str(), nullptr);

	return resultado;
}


//Problema #2

//Función auxiliar problema 2: separar el string cuando aparezca una coma
vector<string> separar(string str, char separador = ',') {

	int inicial = 0;
	int contador = 0;
	string separada;
	vector<string> resultados;

	while (contador >= 0) {
		contador = str.find(separador, inicial);
		separada = str.substr(inicial, contador - inicial);
		inicial = contador + 1;
		resultados.push_back(separada);
	}

	return resultados;
}

//Definición de la clase: problema 2
class Vector3d {

public:

	Vector3d(string coordenadas) {
		vector<string> coords = separar(coordenadas);//Primero separa el vector en 3 strings

		//Utilizar parseFloat para convertir cada string en una componente del vector
		x = parseFloat(coords[0]);
		y = parseFloat(coords[1]);
		z = parseFloat(coords[2]);
	}


	//Problema #3: calcula la distancia entre el vector y otro vector que toma como parámetro
	float distancia(Vector3d otro) {
		float xx = pow((x - otro.x), 2);
		float yy = pow((y - otro.y), 2);
		float zz = pow((z - otro.z), 2);

		return sqrt(xx + yy + zz);
	}

	//getters, definidos para hacer las pruebas después
	float getX() {
		return x;
	}
	float getY() {
		return y;
	}
	float getZ() {
		return z;
	}


private:

	//Variables de la clase
	float x;
	float y;
	float z;
};


int main()
{

	//Prueba ejercicio #1
	string valor_str("456.7");
	float valor = parseFloat(valor_str);
	printf("El valor del string es: %f\n", valor);

	//Prueba ejercicio #2
	string coords("40,2.3,7.756");
	Vector3d v(coords);
	printf("Las coordenadas son: (%f,%f,%f)\n", v.getX(), v.getY(), v.getZ());

	//Pruba ejercicio #3
	Vector3d v1("3,4,5");
	Vector3d v2("2,1,6");
	float dist = v1.distancia(v2);
	printf("La distancia entre v1 y v2 es: %f\n", dist);

	//Ejercicio #4
	vector<Vector3d> vectores;//Arreglo con todos los vectores que se ingresarán
	string numeros;//parametro del Vector3d
	float distanciaTotal = 0;
	int contador = 0;

	cout << "Ingrese los vectores de 3 dimensiones (x,y,z) que desee:\n";

	while (numeros != "\n") {//Ciclo continuo que no acabará hasta que no se ingresen vectores
		getline(cin, numeros);//Ingresar cada vector

		if (!numeros.empty()) {
			vectores.push_back(Vector3d(numeros));//Cada vez que se ingresa un vector, se agrega al arreglo de vectores
			contador++;
		}
		else {
			break;//Al dar Enter (vector vacío) se rompe el ciclo
		}
	}
	if (vectores.empty()) {
		distanciaTotal = 0;//Si no hay vectores en el arreglo, la suma de las distancias será 0
	}
	else {
		for (int i = 0; i < contador - 1; i++) {
			//La distancia total es la suma de las distancias entre un vector y su anterior en el arreglo de vectores
			distanciaTotal = distanciaTotal + vectores[i].distancia(vectores[i + 1]);
		}
	}

	cout << "La distancia total entre los vectores es: " << distanciaTotal;


	char x;
	std::cin >> x;

	return 0;
}
