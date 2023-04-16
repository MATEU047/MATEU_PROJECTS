#pragma once
#include <iostream>
using namespace std;

class Moto
{
private:

	string name;
	int velocidad;
	int distancia;
	int nitro;

public:

	//contructor
	 Moto(string pName, int pVelocidad, int pDistancia, bool pNitro);

	//getters
	string getName();
	int getVelocidad();
	int getDistancia();
	bool getNitro();


	//setters
	void setName(string pName);
	void setVelocidad(int pVelocidad);
	void setDistancia(int pDistancia);
	bool setNitro(bool pNitro);


	//methods
	void estadoMoto();
};