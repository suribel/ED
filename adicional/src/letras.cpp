#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "Diccionario.h"

using namespace std;

int main(int argc, char * argv[]){

    if (argc!=5){
        cout<<"Los parametros son:"<<endl;
        cout<<"1.- El nombre del fichero con el diccionario";
        cout<<"2.- El nombre del fichero con las letras";
        cout<<"3.- El número de letras que se deben generar de forma aleatoria";
        cout<<"4.- Modalidad de juego: L o P";
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
    if (modo != "L" || modo != "P")
    {
        cout<<"Modo de juego erroneo"<<argv[2]<<endl;
        return 0;
    }

    int num_letras = atoi(argv[3]);
    







    Diccionario D;
    cout<<"Cargando diccionario...."<<endl;
    f>>D;

    // cout<<"Leido el diccionario..."<<endl;
    // cout<<D;

    int longitud;
    cout<<"Dime la longitud de las palabras que quieres ver";
    cin>>longitud;
    vector<string> v=D.PalabrasLongitud(longitud);

    cout<<"Palabras de Longitud" << longitud <<endl;

    for (unsigned int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }        

    string p;
    cout<<"Dime una palabra: ";
    cin>>p;
    if (D.Esta(p)) cout<<"Sí esa palabra existe";
    else cout<<"Esa palabra no existe";
}