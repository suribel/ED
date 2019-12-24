#ifndef __Diccionario_h__
#define __Diccionario_h__

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Diccionario{
private:
    set<string> datos;
public:
    /**
    @brief Construye un diccionario vacío.
    **/
    Diccionario(){}
    /**
    @brief Devuelve el numero de palabras en el diccionario
    **/
    int size() const ;
    /**
    @brief Obtiene todas las palabras en el diccionario de un longitud dada
    @param longitud: la longitud de las palabras de salida
    @return un vector con las palabras de longitud especifica en el parametro de entrada
    **/
    vector<string> PalabrasLongitud(int longitud);
    /**
    @brief Indica si una palabra está en el diccionario o no
    @param palabra: la palabra que se quiere buscar
    @return true si la palabra esta en el diccionario. False en caso contrario
    **/
    bool Esta(string palabra);
    /**
    @brief Lee de un flujo de entrada un diccionario
    @param is:flujo de entrada
    @param D: el objeto donde se realiza la lectura.
    @return el flujo de entrada
    **/
    friend istream & operator>>(istream & is,Diccionario &D);
    /**
    @brief Escribe en un flujo de salida un diccionario
    @param os:flujo de salida
    @param D: el objeto diccionario que se escribe
    @return el flujo de salida
    **/
    friend ostream & operator<<(ostream & os, Diccionario &D);

    void insertar(string palabra);

    class iterator{
    private:
        set<string>::iterator it;
    public:
        iterator (){}
        string operator *();
        iterator & operator ++();
        bool operator ==(const iterator &i);
        bool operator !=(const iterator &i);
        friend class Diccionario;
    };
    
    iterator begin();
    iterator end();

    //crear begin y end const



};

#endif