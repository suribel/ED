#include <fstream>
#include <iostream>

#include "../include/Letra.h"

using namespace std;

Letra()
{
    caracter = '/0';
    apariciones = 0;
    puntuacion = 0;
}

Letra(char caracter, int apariciones, int puntucion)
{
    this->caracter = caracter;
    this->apariciones = apariciones;
    this->puntucion = puntucion;
}


Letra & operator= (const Letra & otra)
{
    if (&otra != this)
    {
        caracter = otra.caracter;
        apariciones = otra.apariciones;
        puntucion = otra.puntucion;
    }    
    return *this;    
}


char getCaracter() const
{
    return caracter;
}
int getApariciones() const
{
    return apariciones;
}
int getPuntucion() const
{
    return puntucion;
}


ostream & operator<<(ostream & os, const Letra &L)
{
  
    os << "Caracter " << L.caracter << endl;
    os << "Apariciones " << L.apariciones << endl;
    os << "Puntucion " << L.puntucion << endl;

    return os;
}


istream & operator>>(istream & is, Letra &L)
{	
    is >> L.caracter >> L.apariciones >> L.puntucion;

    return is;
}