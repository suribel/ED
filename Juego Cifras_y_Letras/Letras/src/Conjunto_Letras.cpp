#include <fstream>
#include <iostream>
#include <set>
#include "Conjunto_Letras.h"

using namespace std;

Conjunto_Letras::Conjunto_Letras()
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

int Conjunto_Letras::getPuntuacion(string palabra) const
{
    const_iterator it;

    int result = 0;
    bool encontrado;

    for (int i = 0; i < (int)palabra.size(); ++i)
    {
        encontrado = false;
        for (it=begin(); it!=end() && !encontrado; ++it)
        {        
            if (toupper(palabra[i]) == (*it).getCaracter())
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
    Conjunto_Letras::const_iterator it;

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

    
////////////////////////////////////////
// iterator
////////////////////////////////////////


Letra Conjunto_Letras::iterator::operator *()
{
    return *it;
}

Conjunto_Letras::iterator & Conjunto_Letras::iterator::operator ++()
{
    ++it;
    return *this;
}

bool Conjunto_Letras::iterator::operator ==(const iterator &i)
{
    return it == i.it;
}
bool Conjunto_Letras::iterator::operator !=(const iterator &i)
{
    return it != i.it;
}


Conjunto_Letras::iterator Conjunto_Letras::begin()
{
    iterator ite;
    ite.it = conjunto.begin();
    return ite;
}

Conjunto_Letras::iterator Conjunto_Letras::end()
{
    iterator ite;
    ite.it = conjunto.end();
    return ite;
}

    
////////////////////////////////////////
// const_iterator
////////////////////////////////////////


Letra Conjunto_Letras::const_iterator::operator *()
{
    return *it;
}

Conjunto_Letras::const_iterator & Conjunto_Letras::const_iterator::operator ++()
{
    ++it;
    return *this;
}

bool Conjunto_Letras::const_iterator::operator ==(const const_iterator &i)
{
    return it == i.it;
}
bool Conjunto_Letras::const_iterator::operator !=(const const_iterator &i)
{
    return it != i.it;
}


Conjunto_Letras::const_iterator Conjunto_Letras::begin() const
{
    const_iterator ite;
    ite.it = conjunto.begin();
    return ite;
}
Conjunto_Letras::const_iterator Conjunto_Letras::end() const
{
    const_iterator ite;
    ite.it = conjunto.end();
    return ite;
}


Conjunto_Letras::iterator Conjunto_Letras::find(char c)
{
    Conjunto_Letras::iterator it;
    bool encontrado=false;
    for (it=begin(); it!=end() && !encontrado; ++it)
    {
        if (c == (*it).getCaracter())
            {
                encontrado = true;
            } 
    }

    return it;
    
}