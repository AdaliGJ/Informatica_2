
//Laboratorio #7
//Jeremy Cáceres y Adalí Garrán


#include <iostream>

using namespace std;
struct mapa {
	bool** posiciones;
	int ancho;
	int largo;
};

struct vector {
	int x;
	int y;
};


class Vehiculo {


public:
	//Problema #1
	Vehiculo(mapa _mapa, vector _posicion) {
		espacio = _mapa;
		posicion = _posicion;

		//La velocidad inicial del vehículo será (0,0)
		velocidad.x = 0;
		velocidad.y = 0;
	}

	//Problema #2
	void estadoActual() {//Imprimer la velocidad y posición actuales del vehículo
		printf("La posición actual del veículo es (%i, %i)\n", posicion.x, posicion.y);
		printf("La velocidad actual del veículo es (%i, %i)\n\n", velocidad.x, velocidad.y);

	}

	//Problema #3
	void acelerar(vector aceleracion) {//Se suma la aceleración a la velocidad
		velocidad.x = velocidad.x + aceleracion.x;
		velocidad.y = velocidad.y + aceleracion.y;
	}

	//Problema #4
	bool validarAvance() {//Ve que todas las posiciones intermedias hasta la nueva, sean válidas
		int posx = posicion.x + velocidad.x;
		int posy = posicion.y + velocidad.y;

		int contador = posicion.x;//El punto de inicio será la primera posicón de x
		bool b1;

		int m = (posy - posicion.y) / (posx - posicion.x);//Pendiente de una ecuación lineal

		while (b1 == true) {
			int encY = (m*(contador - posicion.x)) + posicion.y;//Encuentra los valores en y por los que pasa el vehículo por cada x que avanza
			if (espacio.posiciones[contador][encY] == true && contador <= posx) {//Si el valor estpa en el mapa y el contador no supera a la x final b1 = true, y se sigue el ciclo con la posición siguiente
				b1 = true;
				contador++;
			}
			else {//Si no se cumple alguna de las dos condciones, b1 = false y se termina el ciclo
				b1 = false;
			}
		}
		return b1;
	}


	//Problema #5
	void avanzar(int tiempo) {//Avanza la velocidad establecida cada unidad de tiempo

		for (int i = 0; i < tiempo; i++) {
			posicion.x = posicion.x + velocidad.x;
			posicion.y = posicion.y + velocidad.y;

			//En caso de velocidades positivas
			if (posicion.x > espacio.ancho) {//La siguiente posición x despúes del final del mapa se medirá de nuevo desde el x inicial del mapa
				posicion.x = 0 + velocidad.x;
			}
			if (posicion.y > espacio.largo) {//La siguiente posición y despúes del final del mapa se medirá de nuevo desde el y inicial del mapa
				posicion.y = 0 + velocidad.y;
			}

			//En caso de velocidades negativas
			if (posicion.x < 0) {//La siguiente posición x despúes del inicio del mapa se medirá de nuevo desde el x final del mapa
				posicion.x = espacio.ancho + velocidad.x;//como la velocidad es negativa en este caso, se van restando posiciones
			}
			if (posicion.y < 0) {//La siguiente posición y despúes del inicio del mapa se medirá de nuevo desde el y final del mapa
				posicion.y = espacio.largo + velocidad.y;
			}

		}

	}

private:
	mapa espacio;
	vector posicion;
	vector velocidad;

};

int main()
{
	//Para prueba de funcionamiento
	mapa m1;
	m1.posiciones;
	m1.ancho = 5;
	m1.largo = 7;

	vector pos0;
	pos0.x = 0;
	pos0.y = 0;

	vector acel;
	acel.x = 1;
	acel.y = 1;

	//Prueba problema #1 
	Vehiculo v = Vehiculo(m1, pos0);//Crea una variable Vehículo con las condiciones dadas

	//Prueba problema #2 
	v.estadoActual();//Imprime las condiciones actuales del vehículo

	//Prueba problema #3
	v.acelerar(acel);
	v.estadoActual();//mostrará una velocidad nueva

	//Prueba problema #4
	v.validarAvance();

	//Prueba problema #5
	v.avanzar(3);
	v.estadoActual();//mostrará la nueva posición (no se pasa de los límites)

	v.avanzar(6);
	v.estadoActual();//mostrará la nueva posición (se pasa de los límites)

	return 0;
}
