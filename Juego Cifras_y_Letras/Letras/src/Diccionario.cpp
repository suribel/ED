#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "Diccionario.h"

using namespace std;


Diccionario::Diccionario(){}

int Diccionario::size() const
{
    return datos.size();
}

vector<string> Diccionario::PalabrasLongitud(int longitud)
{
    vector<string> palabras;
    iterator ite;

    for (ite=begin(); ite!=end(); ++ite)
    {
        if ((int)(*ite).size() == longitud)
        {
            palabras.push_back((*ite));
        }            
    }

    return palabras;
}

bool Diccionario::Esta(string palabra)
{
    bool esta = false;
    iterator ite;

    for (ite=begin(); ite!=end(); ++ite)
    {
        if ((*ite) == palabra)
        {
            esta = true;
        }            
    }

    return esta;
}

void Diccionario::insertar(string palabra)
{
    if (!Esta(palabra))
    {
        datos.insert(palabra);
    }
    
}
    

//Basado en el codigo propuesto para diccionario de la practica 4
ostream & operator<<(ostream & os, const Diccionario &D)
{
    Diccionario::const_iterator ite;

    for (ite=D.begin(); ite!=D.end(); ++ite){        
        os << (*ite) << endl;
    }

    return os;
}


//Basado en el codigo propuesto para diccionario de la practica 4
istream & operator>>(istream & is,Diccionario &D)
{	
    Diccionario diccionario;
    string palabra;

    //una palabra por linea
    while (is>>palabra){

        diccionario.insertar(palabra);        
    }

    D = diccionario;

    return is;
}   
    
    
////////////////////////////////////////
// iterator
////////////////////////////////////////


string Diccionario::iterator::operator *()
{
    return *it;
}

Diccionario::iterator & Diccionario::iterator::operator ++()
{
    ++it;
    return *this;
}

bool Diccionario::iterator::operator ==(const iterator &i)
{
    return it == i.it;
}
bool Diccionario::iterator::operator !=(const iterator &i)
{
    return it != i.it;
}


Diccionario::iterator Diccionario::begin()
{
    iterator ite;
    ite.it = datos.begin();
    return ite;
}
Diccionario::iterator Diccionario::end()
{
    iterator ite;
    ite.it = datos.end();
    return ite;
}


////////////////////////////////////////
// const_iterator
////////////////////////////////////////


string Diccionario::const_iterator::operator *()
{
    return *it;
}

Diccionario::const_iterator & Diccionario::const_iterator::operator ++()
{
    ++it;
    return *this;
}

bool Diccionario::const_iterator::operator ==(const const_iterator &i)
{
    return it == i.it;
}
bool Diccionario::const_iterator::operator !=(const const_iterator &i)
{
    return it != i.it;
}


Diccionario::const_iterator Diccionario::begin() const
{
    const_iterator ite;
    ite.it = datos.begin();
    return ite;
}
Diccionario::const_iterator Diccionario::end() const
{
    const_iterator ite;
    ite.it = datos.end();
    return ite;
}

Diccionario::const_iterator Diccionario::cbegin() const
{
    const_iterator ite;
    ite.it = datos.begin();
    return ite;
}
Diccionario::const_iterator Diccionario::cend() const
{
    const_iterator ite;
    ite.it = datos.end();
    return ite;
}