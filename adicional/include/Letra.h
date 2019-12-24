#ifndef __Diccionario_h__
#define __Diccionario_h__

#include <fstream>
#include <iostream>

using namespace std;

class Letra{
private:
    char caracter;
    int apariciones, puntuacion;
public:
    
    Letra();

    Letra(char caracter, int apariciones, int puntucion);

    Letra & operator= (const Letra & otra);

    char getCaracter() const;

    int getApariciones() const;

    int getPuntuacion() const;

    friend ostream & operator<<(ostream & os, const Letra &L);

    friend istream & operator>>(istream & is, Letra &L);

};

#endif

