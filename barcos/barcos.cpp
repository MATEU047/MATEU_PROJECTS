#include <iostream>
#include "barco.h"
using namespace std;

int turnos = 5;

void tirarDado( Moto& moto) {
	int dado = rand() % 6 + 1;
	cout << "El corredor " << moto.getName() << " ha sacado un " << dado << "\n";
	moto.setVelocidad(moto.getVelocidad() + dado);
}

void nitro(Moto& moto) {
	if (moto.getNitro() == 0) {
		cout << moto.getName() << " ya ha usado su nitro en esta carrera." << endl;
		return;
	}

	moto.setNitro(0);
	int aleatorio = rand() % 2;

	if (aleatorio == 0) {
		moto.setVelocidad(moto.getVelocidad() / 2);
		cout << moto.getName() << " usó el nitro y tuvo mala suerte. Velocidad actual: " << moto.getVelocidad() << endl;
	}
	else {
		moto.setVelocidad(moto.getVelocidad() * 2);
		cout << moto.getName() << " usó el nitro y tuvo suerte. Velocidad actual: " << moto.getVelocidad() << endl;
	}
}

void avanzar(Moto& moto) {
	moto.setDistancia(moto.getDistancia() + moto.getVelocidad() * 100);
	cout << moto.getName() << " avanzó ha una velocidad de " << moto.getVelocidad() << " metros. Distancia recorrida: " << moto.getDistancia() << endl;
}

void ganador(Moto& moto1, Moto& moto2) {
	if (moto1.getDistancia() > moto2.getDistancia()) {

		cout << " El jugador " << moto1.getName() << " Ha ganado con una distancia de " << moto1.getDistancia() << endl;
	}

	if (moto1.getDistancia() < moto2.getDistancia()) {

		cout << " El jugador " << moto2.getName() << " Ha ganado con una distancia de " << moto2.getDistancia() << endl;
	}
}


int main(){
	srand(time(0));

	Moto moto1("Mateu", 0, 0, true);
	Moto moto2("teacher", 0, 0, true);

	cout << " Bienvenidos al juego de las carreras de moto" << endl;
	cout << " Demos comienzo a la carrera :) " << endl;


	for (int turno = 1; turno <= 5; turno++) {
		cout << "  || Turno " << turno << "||" << endl;
		tirarDado(moto1);
		tirarDado(moto2);

		avanzar(moto1);
		avanzar(moto2);


		if (turno != 6) {
			cout << "¿" << moto1.getName() << " quiere usar el nitro? (s/n): ";
			char respuesta;
			cin >> respuesta;

			if (respuesta == 's') {
				nitro(moto1);
			}

			cout << "¿" << moto2.getName() << " quiere usar el nitro? (s/n): ";
			cin >> respuesta;

			if (respuesta == 's') {
				nitro(moto2);
			}
		}
		
	}
	ganador(moto1, moto2);

}


