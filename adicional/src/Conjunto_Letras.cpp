#include <fstream>
#include <iostream>
#include <set>

#include "../include/Conjunto_Letras.h"

using namespace std;

Conjunto_Letras::()
{

}

int Conjunto_Letras::size() const
{
    return conjunto.size();
}


void Conjunto_Letras::insertar(const Letra &L)
{
    conjunto.insert(L);
}

int getPuntuacion(string palabra) const
{
    set<Letra>::iterator it;

    int result = 0;
    bool encontrado;

    for (int i = 0; i < palabra.size(); ++i)
    {
        encontrado = false;
        for (it=CL.begin(); it!=CL.end() && !encontrado; ++it)
        {        
            if (palabra[i] == (*it).getCaracter())
            {
                result += (*it).getPuntuacion();
                encontrado = true;
            }
            
        }
    }

    return result;
}

ostream & operator<<(ostream & os, const Conjunto_Letras &CL)
{
    set<Letra>::iterator it;

    for (it=CL.begin(); it!=CL.end(); ++it){        
        os << (*it) << endl;
    }

    return os;
}

istream & operator>>(istream & is, Conjunto_Letras &CL)
{
    Letra letra;

    while (is>>letra)
    {
        CL.insertar(letra);        
    }

    return is;
}