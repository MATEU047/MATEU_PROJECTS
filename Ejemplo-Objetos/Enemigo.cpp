#pragma once
#include "enemigo.h"
#include  <iostream>
using namespace std;

	//constructor
Personaje::Personaje(int pHp, string pName, int pAttack, int pPosicionX, int pPosicionY) {
	hp = pHp;
	name = pName;
	attack = pAttack;
	pPosicionX = posicionX;
	pPosicionX = posicionY;
	}

	//getters
	int Personaje::getHp() {
		return hp;
	}
	string Personaje::getName() {
		return name;
	}
	int Personaje::getAttack() {
		return attack;
	}
	int Personaje::getPosicionX()
	{
		return posicionX;
	}
	int Personaje::getPosicionY()
	{
		return posicionY;
	}

	//setters
	void Personaje::setHp(int php) {
		hp = php;
	}
	void Personaje::setName(string pname) {
		name = pname;
	}
	void Personaje::setAttack(int pattack) {
		attack = pattack;
	}
	void Personaje::setPosicionX(int pPosicionX){
		pPosicionX = posicionX;
	}
	void Personaje::setPosicionY(int pPosicionY){
		pPosicionY = posicionY;
	}


	//Metodos propios
	void Personaje::printStatus() {
		cout << "El nombre del enemigo es " << getName() << " y tiene una vida de  " << getHp() << endl;
 	}