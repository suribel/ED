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
    Diccionario();
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
    friend ostream & operator<<(ostream & os, const Diccionario &D);
    /**
    @brief Inserta palabra en el diccionario
    @param palabra: la palabra que se va a introducir
    **/
    void insertar(string palabra);

    class iterator{
    private:
        set<string>::iterator it;
    public:
        /**
        @brief Construye un iterador vacio
        **/
        iterator (){}
        /**
        @brief operador para acceder al elemento apuntado
        @return el elemento al que apunta
        **/
        string operator *();
        /**
        @brief operador para incremantar la posicion apuntada
        @return el iterador por referencia
        **/
        iterator & operator ++();
        /**
        @brief operador para ver si son iguales iteradores
        @param i:el iterador con el que hago la comparacion
        @return true o false
        **/
        bool operator ==(const iterator &i);
        /**
        @brief operador para ver si no son iguales iteradores
        @param i: el iterador con el que hago la comparacion
        @return true o false
        **/
        bool operator !=(const iterator &i);
        
        friend class Diccionario;
    };
    
    /**
    @brief iterador de comienzo de la estructura
    @return el iterador
    **/
    iterator begin();
    /**
    @brief iterador de final de la estructura
    @return el iterador
    **/
    iterator end();

    class const_iterator{
    private:
        set<string>::const_iterator it;
    public:
        /**
        @brief Construye un iterador vacio
        **/
        const_iterator (){}
        /**
        @brief operador para acceder al elemento apuntado
        @return el elemento al que apunta
        **/
        string operator *();
        /**
        @brief operador para incremantar la posicion apuntada
        @return el iterador por referencia
        **/
        const_iterator & operator ++();
        /**
        @brief operador para ver si son iguales iteradores
        @param i:el iterador con el que hago la comparacion
        @return true o false
        **/
        bool operator ==(const const_iterator &i);
        /**
        @brief operador para ver si no son iguales iteradores
        @param i: el iterador con el que hago la comparacion
        @return true o false
        **/
        bool operator !=(const const_iterator &i);
        
        friend class Diccionario;
    };
    
    /**
    @brief iterador de comienzo de la estructura constante
    @return el iterador
    **/
    const_iterator begin() const;
    /**
    @brief iterador de final de la estructura constante
    @return el iterador
    **/
    const_iterator end() const;

    /**
    @brief iterador de comienzo de la estructura constante para objeto no constante
    @return el iterador
    **/
    const_iterator cbegin() const;
    /**
    @brief iterador de final de la estructura constante para objeto no constante
    @return el iterador
    **/
    const_iterator cend() const;



};

#endif