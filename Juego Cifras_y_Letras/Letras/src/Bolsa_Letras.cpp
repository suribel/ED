#include <fstream>
#include <iostream>
#include <set>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

#include "Bolsa_Letras.h"

using namespace std;

Bolsa_Letras::Bolsa_Letras()
{

}
int Bolsa_Letras::size() const
{
    return bolsa.size();
}

void Bolsa_Letras::llenar(const Conjunto_Letras &CL)
{
    Conjunto_Letras::const_iterator it;

    for (it=CL.begin(); it!=CL.end(); ++it){        
        for (int i = 0; i < (*it).getApariciones(); ++i)
        {
            bolsa.push_back((*it).getCaracter());
        }
        
    }
}

vector<char> Bolsa_Letras::sacar(int num_letras)
{
    vector<char>::iterator it;
    vector<char> sacados;        

    for (int i = 0; i < num_letras; ++i)
    {            
        srand(time(NULL));
        int num = rand() % bolsa.size();
        it = bolsa.begin() + num;
        sacados.push_back(*it);
        bolsa.erase (it);
    }

    return sacados;        
}

ostream & operator<<(ostream & os, const Bolsa_Letras &BL)
{
    vector<char>::const_iterator it;

    for (it=BL.bolsa.begin(); it!=BL.bolsa.end(); ++it){        
        os << (*it) << endl;
    }

    return os;
}

