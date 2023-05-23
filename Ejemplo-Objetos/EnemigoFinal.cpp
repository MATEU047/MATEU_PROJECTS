#include "EnemigoFinal.h"
using namespace std;

//CONSTRUCTOR
//TIENE COMO PARÁMETROS DE ENTRADA LOS ATRIBUTOS PROPIOS
//Y LOS ATRIBUTOS DE LA CLASE QUE HEREDA
//LOS PARÁMETROS DE LA CLASE QUE HEREDA SE PASAN COMO PARÁMETROS DE ENTRADA
//AL CONSTRUCTOR HEREDADO
EnemigoFinal::EnemigoFinal(int pHp,
						   string pName,
						   int pAttack,
						   int pPosicionX,
						   int pPosicionY,
						   int pSuperAttack,
						   int pCritico) : Personaje(pHp,
														pName,
														pAttack,
														pPosicionX,
														pPosicionY) {superAttack = pSuperAttack;
																     critico = pCritico;
						}


//GETTERS AND SETTERS
int EnemigoFinal::getSuperAttack() {
	return superAttack;
}
int EnemigoFinal::getCritico() {
	return critico;
}

void EnemigoFinal::setSuperAttack(int pSuperAttack) {
	superAttack = pSuperAttack;
}
void EnemigoFinal::setCritico(int pCritico) {
	critico = pCritico;
}

//METODOS PROPIOS
void EnemigoFinal::printAllStats() {
	cout << "	La vida del enemigo final es " << getHp() << endl;
	cout << "	El ataque normal del enemigo final es " << getAttack() << endl;
	cout << "	El ataque de fuego del enemigo final es " << getSuperAttack() << endl;
	cout << "	El ataque de hielo del enemigo final es " << getCritico() << endl;
	cout << endl;
}