#ifndef __Conjunto_Letras_h__
#define __Conjunto_Letras_h__

#include <fstream>
#include <iostream>
#include <set>

#include "Letra.h"

using namespace std;

class Conjunto_Letras{
private:
    set<Letra> conjunto;
public:

    /**
    @brief Construye un Conjunto de Letras vacío.
    **/
    Conjunto_Letras();
    /**
    @brief Devuelve el tamaño del conjunto
    @return el tamaño
    **/
    int size() const ;
    /**
    @brief Inserta Letra en el conjunto
    @param L: la letra que se va a introducir
    **/
    void insertar(const Letra &L);
    /**
    @brief Hace la suma de las puntuaciones de cada letra de una palabra
    @param palabra: la palabra que se va comprobar
    @return la suma
    **/
    int getPuntuacion(string palabra) const;
    /**
    @brief Escribe en un flujo de salida un Conjunto de Letras
    @param os:flujo de salida
    @param D: el objeto Conjunto de Letras que se escribe
    @return el flujo de salida
    **/
    friend ostream & operator<<(ostream & os, const Conjunto_Letras &CL);
    /**
    @brief Lee de un flujo de entrada un Conjunto de Letras
    @param is:flujo de entrada
    @param D: el objeto donde se realiza la lectura.
    @return el flujo de entrada
    **/
    friend istream & operator>>(istream & is, Conjunto_Letras &CL);
    

    class iterator{
    private:
        set<Letra>::iterator it;
    public:
        /**
        @brief Construye un iterador vacio
        **/
        iterator (){}
        /**
        @brief operador para acceder al elemento apuntado
        @return el elemento al que apunta
        **/
        Letra operator *();
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
        
        friend class Conjunto_Letras;
    };

    class const_iterator{
    private:
        set<Letra>::const_iterator it;
    public:
        /**
        @brief Construye un iterador vacio
        **/
        const_iterator (){}
        /**
        @brief operador para acceder al elemento apuntado
        @return el elemento al que apunta
        **/
        Letra operator *();
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
        
        friend class Conjunto_Letras;
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

    /**
    @brief iterador de comienzo de la estructura
    @return el iterador
    **/
    const_iterator begin() const;
    /**
    @brief iterador de final de la estructura
    @return el iterador
    **/
    const_iterator end() const;

    

    iterator find(char c);

};

#endif