#include "barco.h"

// constructor
Moto::Moto(string pName, int pVelocidad, int pDistancia, bool pNitro){
    name = pName;
    velocidad = pVelocidad;
    distancia = pDistancia;
    nitro = pNitro;
}

// GET
string Moto::getName(){
    return name;
}

int Moto::getVelocidad(){
    return velocidad;
}

int Moto::getDistancia(){
    return distancia;
}

bool Moto::getNitro(){
    return nitro;
}

// SET
void Moto::setName(string pName) {

    name = pName;
}

void Moto::setVelocidad(int pVelocidad) {
    velocidad = pVelocidad;
}

void Moto::setDistancia(int pDistancia) {
    distancia = pDistancia;
}

bool Moto::setNitro(bool pNitro) {
    nitro = pNitro;
    return nitro;
}



// METODOS
void Moto::estadoMoto() {
    cout << "La moto " << getName() << " Ha recorrido" << getDistancia() << " a una velocidad de "
    << getVelocidad() << endl;
}

