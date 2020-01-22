#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Letra.h"
#include "Diccionario.h"

using namespace std;


int main(int argc, char * argv[]){

    if (argc!=4)
    {
        cout<<"Los parametros son:"<<endl;
        cout<<"1.- El nombre del fichero con el diccionario"<<endl;
        cout<<"2.- El nombre del fichero con las letras"<<endl;
        cout<<"3.- El nombre del fichero donde guardar las letras"<<endl;
        return 0;
    }

    ifstream f(argv[1]);
    if (!f)
    {
        cout<<"No puedo abrir el fichero"<<argv[1]<<endl;
        return 0;
    }
    
    ifstream f2(argv[2]);
    if (!f2)
    {
        cout<<"No puedo abrir el fichero"<<argv[2]<<endl;
        return 0;
    }

    ofstream f3(argv[3]);
    if (!f3)
    {
        cout<<"No puedo abrir el fichero"<<argv[2]<<endl;
        return 0;
    }


    Diccionario D;
    cout<<"Cargando diccionario...."<<endl;
    f >> D;

    //Conjunto_Letras conjunto;
    cout<<"Cargando letras...."<<endl;
    //f2 >> conjunto;
    vector<Letra> conjunto;
    Letra letra;

    while (f2>>letra)
    {
        conjunto.push_back(letra);        
    }
        
    Diccionario::const_iterator it;

    for (it=D.cbegin(); it!=D.cend(); ++it)
    {
        string palabra = (*it);

        for (int i = 0; i < (int)palabra.size(); ++i)
        {
            char c = toupper(palabra[i]);

            bool encontrado=false;
            for (int j = 0; j < (int)conjunto.size() && !encontrado; ++j)
            {
                if (c == conjunto[j].getCaracter())
                {
                    encontrado = true;
                    conjunto[j].setApariciones(conjunto[j].getApariciones()+1);
                }
            }
        }
    }

    float porcentaje = 0;

    for (int i = 0; i < (int)conjunto.size(); ++i)
    {
        if (porcentaje < conjunto[i].getApariciones())
        {
            porcentaje = conjunto[i].getApariciones();
        }
    }
    int puntos;

    cout << "Llenando archivo con letras: " << endl;
    for (int i = 0; i < (int)conjunto.size(); ++i)
    {
        puntos= ((porcentaje - conjunto[i].getApariciones())/porcentaje) *9 +1;
        conjunto[i].setPuntuacion(puntos);
        f3 << conjunto[i];      
        cout << conjunto[i] << endl;
    }

}






