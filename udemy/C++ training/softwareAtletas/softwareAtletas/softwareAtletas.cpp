// softwareAtletas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class atleta {
private:
	int numeroAtleta;
	string nombre;
	float tiempoCarrera;
public:
	atleta() {};
	atleta(int numeroAtleta, string nombre, float tiempoCarrera) : numeroAtleta(numeroAtleta), nombre(nombre), tiempoCarrera(tiempoCarrera) {};
	~atleta() {};
	float getTiempoCarrera();
	void mostrarDatos();
	static int indiceGanador(atleta atletas[], int numeroAtletas);
};

float atleta::getTiempoCarrera() {
	return tiempoCarrera;
}

void atleta::mostrarDatos(){
	cout << "Numero de atleta: " << numeroAtleta << endl;
	printf("Nombre: %s\n", nombre.c_str());
	cout << "Tiempo de carrera: " << tiempoCarrera << endl;
}

int atleta::indiceGanador(atleta atletas[], int numeroAtleta) {
	float tiempoCarrera;
	int indice = 0;

	tiempoCarrera = atletas[0].getTiempoCarrera();

	for (int i = 0; i < numeroAtleta; i++) {
		if (atletas[i].getTiempoCarrera() < tiempoCarrera) {
			tiempoCarrera = atletas[i].getTiempoCarrera();
			indice = i;
		}
	}

	return indice;
}

int main()
{
	atleta* atletas;
	int numeroAtletas;
	int numeroAtleta;
	string nombre;
	float tiempoCarrera;

	cout << "Numero de atletas: ";
	cin >> numeroAtletas;
	cout << endl;

	atletas = new atleta[numeroAtletas];

	for (int i = 0; i < numeroAtletas;i++) {
		cout << "Atributos del atleta " << (i+1) << endl;
		cout << "Numero de atleta: ";
		cin >> numeroAtleta;
		cout << "Nombre del atleta: ";
		cin >> nombre;
		cout << "Tiempo de carrera: ";
		cin >> tiempoCarrera;
		
		atletas[i] = atleta(numeroAtleta, nombre, tiempoCarrera);
		cout << endl;
	}

	int indiceAtleta = atleta::indiceGanador(atletas, numeroAtletas);

	cout << "El atleta ganador es: ";
	(atletas+indiceAtleta)->mostrarDatos();

    return 0;
}

