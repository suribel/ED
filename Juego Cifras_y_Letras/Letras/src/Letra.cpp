#include <fstream>
#include <iostream>
#include "Letra.h"

using namespace std;

Letra::Letra()
{
    caracter = '\0';
    apariciones = 0;
    puntuacion = 0;
}

Letra::Letra(char caracter, int apariciones, int puntuacion)
{
    this->caracter = caracter;
    this->apariciones = apariciones;
    this->puntuacion = puntuacion;
}


Letra & Letra::operator= (const Letra & otra)
{
    if (&otra != this)
    {
        caracter = otra.caracter;
        apariciones = otra.apariciones;
        puntuacion = otra.puntuacion;
    }    
    return *this;    
}

bool Letra::operator<(const Letra & L) const
{
    return caracter < L.caracter;
}
//para funcion find
bool Letra::operator ==(const Letra &L)
{
    return caracter == L.caracter;
}

char Letra::getCaracter() const
{
    return caracter;
}
int Letra::getApariciones() const
{
    return apariciones;
}

void Letra::setApariciones(int i)
{
    apariciones = i;
}
int Letra::getPuntuacion() const
{
    return puntuacion;
}

void Letra::setPuntuacion(int p)
{
    puntuacion = p;
}


ostream & operator<<(ostream & os, const Letra &L)
{
  
    os << L.caracter << "   " << L.apariciones << "   " << L.puntuacion << endl;

    return os;
}


istream & operator>>(istream & is, Letra &L)
{	
    is >> L.caracter >> L.apariciones >> L.puntuacion;

    return is;
}