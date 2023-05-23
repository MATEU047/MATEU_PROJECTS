#pragma once
#include "Enemigo.h"
#include <iostream>

using namespace std;

class EnemigoFinal : public Personaje
{
private:
	int superAttack;
	int critico;
	

public:

	//CONSTRUCTOR CON ELEMENTOS DE LA CLASE PADRE Y PROPIA
	EnemigoFinal(int pHp,
				 string pName,
				 int pAttack,
				 int pPosicionX,
				 int pPosicionY,
				 int pSuperAttack,
				 int pCritico);

	//GETTERS AND SETTERS
	int getSuperAttack();
	int getCritico();

	void setSuperAttack(int pFireAttack);
	void setCritico(int pFrozenAttack);

	//METODOS PROPIOS
	void printAllStats();


};

