#ifndef __Bolsa_Letras_h__
#define __Bolsa_Letras_h__

#include <fstream>
#include <iostream>
#include <set>

#include "../include/Conjunto_Letras.h"

using namespace std;

class Bolsa_Letras{
private:
    multiset<char> bolsa;
public:

    Bolsa_Letras();

    int size() const;


    void llenar(const Conjunto_Letras &CL);


    vector<char> sacar(int num_letras);


    friend ostream & operator<<(ostream & os, const Bolsa_Letras &BL);


    Conjunto_Letras & operator>>(const Conjunto_Letras &CL, Bolsa_Letras &BL);


};

#endif