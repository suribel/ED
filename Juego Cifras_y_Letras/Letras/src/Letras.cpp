#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdlib.h>
#include <algorithm> 
#include "Bolsa_Letras.h"
#include "Diccionario.h"

using namespace std;

//Para ver si la palabra tiene los mismos caracteres que los sacados
bool validar(vector<char> sacados, string palabra)
    {
        vector<char>::iterator it;
        bool correcto = true;
        if (sacados.size() < palabra.size())
        {
            correcto = false;
        }
        
        for (int i = 0; i < (int)palabra.size() && correcto; ++i)
        {
            it = find(sacados.begin(), sacados.end(), toupper(palabra[i]));
            if (it!=sacados.end())
            {
                sacados.erase(it);
            }
            else
            {
                correcto = false;
            }
        }
        return correcto;               
    }


int main(int argc, char * argv[]){

    if (argc!=5)
    {
        cout<<"Los parametros son:"<<endl;
        cout<<"1.- El nombre del fichero con el diccionario"<<endl;
        cout<<"2.- El nombre del fichero con las letras"<<endl;
        cout<<"3.- El número de letras que se deben generar de forma aleatoria"<<endl;
        cout<<"4.- Modalidad de juego: L o P"<<endl;
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

    char modo = argv[4][0];
    modo = toupper(modo);
    if ((modo != 'L') && (modo != 'P'))
    {
        cout<<"Modo de juego erroneo"<<argv[2]<<endl;
        return 0;
    }

    int num_letras = atoi(argv[3]);

    Diccionario D;
    cout<<"Cargando diccionario...."<<endl;
    f >> D;

    Conjunto_Letras conjunto;
    cout<<"Cargando letras...."<<endl;
    f2 >> conjunto;

    char jugar = 'S';

    while (jugar == 'S')
    {
        Bolsa_Letras bolsa;
        bolsa.llenar(conjunto);
        vector<char> sacados;

        sacados = bolsa.sacar(num_letras);

        cout << "Las letras son: "; 
        for (int i = 0; i < num_letras; ++i)
        {
            cout << sacados[i] << "  ";        
        }
        cout << endl;
        

        string palabra;
        cout << "Dime tu solucion en minuscula: " << endl;
        cin >> palabra;

        if (validar(sacados, palabra))
        {
            //cout << validar(sacados, palabra);
            //cout << D.Esta(palabra);
            int puntuacion = 0;

            if (modo == 'P')
            {
                puntuacion = conjunto.getPuntuacion(palabra);            
            }
            else if (modo == 'L')
            {
                puntuacion = palabra.size();            
            }

            int max_punt = puntuacion;        
            string max_palabra = palabra;

            cout << palabra << "  Puntuacion: " << puntuacion << endl;
            

            Diccionario::iterator ite;

            for (ite=D.begin(); ite!=D.end(); ++ite){      
                if (validar(sacados, (*ite)))
                {
                    if (modo == 'P')
                    {
                        puntuacion = conjunto.getPuntuacion((*ite));            
                    }
                    else if (modo == 'L')
                    {
                        puntuacion = (*ite).size();            
                    }
                    cout << (*ite) << "  Puntuacion: " << puntuacion << endl;
                    if (max_punt < puntuacion)
                    {
                        max_punt = puntuacion;
                        max_palabra = (*ite);
                    }
                    
                }            
            }

            cout << "Mejor solucion: " << max_palabra << endl;

            cout << "¿Quieres seguir jugando[S/N]? ";
            cin >> jugar;
            jugar = toupper(jugar);


        }
        else
        {
            cout << "ERROR no es valido" << endl;
        }
    }
    
    
    
    
    

    
    
        
        
   
    









}