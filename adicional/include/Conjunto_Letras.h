#ifndef __Conjunto_Letras_h__
#define __Conjunto_Letras_h__

#include <fstream>
#include <iostream>
#include <set>

#include "../include/Letra.h"

using namespace std;

class Conjunto_Letras{
private:
    set<Letra> conjunto;
public:

    Conjunto_Letras();
    
    int size() const ;

    void insertar(const Letra &L);

    int getPuntuacion(string palabra) const;

    friend ostream & operator<<(ostream & os, const Conjunto_Letras &CL);

    friend istream & operator>>(istream & is, Conjunto_Letras &CL);

};

#endif