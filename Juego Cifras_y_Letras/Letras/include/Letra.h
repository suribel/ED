#ifndef __Letra_h__
#define __Letra_h__

#include <fstream>
#include <iostream>

using namespace std;

class Letra{
private:
    char caracter;
    int puntuacion;
    int apariciones;
public:    
    /**
    @brief Construye una letra vacia
    **/
    Letra();
    /**
    @brief Construye una letra con los parametros dados
    @param caracter: El caracter
    @param apariciones: Numero de apariciones de la letra
    @param puntuacion: La puntacion de la letra
    **/
    Letra(char caracter, int apariciones, int puntuacion);
    /**
    @brief Operator para copiar una letra a otra
    @param otra: la letra a copiar
    @return la letra por referencia
    **/
    Letra & operator= (const Letra & otra);
    /**
    @brief Operator para indicar si el caracter de una letra es menor que otra
    @param letra: la letra a comparar
    @return true o false
    **/
    bool operator<(const Letra & L) const;
    /**
    @brief Obtiene el caracter de una letra
    @return El caracter
    **/
    char getCaracter() const;
    /**
    @brief Obtiene el numero de apariciones de una letra
    @return Numero de apariciones de la letra
    **/
    int getApariciones() const;
    /**
    @brief Modifica el numero de apariciones de una letra
    **/
    void setApariciones(int i);
    /**
    @brief Obtiene la puntuacion de una letra
    @return La puntacion de la letra
    **/
    int getPuntuacion() const;
    /**
    @brief Modifica la puntuacion de una letra
    **/
    void setPuntuacion(int p);

    /**
    @brief Escribe en un flujo de salida una Letra
    @param os:flujo de salida
    @param D: el objeto Letra que se escribe
    @return el flujo de salida
    **/
    friend ostream & operator<<(ostream & os, const Letra &L);
/**
    @brief Lee de un flujo de entrada una Letra
    @param is:flujo de entrada
    @param D: el objeto donde se realiza la lectura.
    @return el flujo de entrada
    **/
    friend istream & operator>>(istream & is, Letra &L);

    /**
    @brief operador para ver si son iguales iteradores
    @param i:el iterador con el que hago la comparacion
    @return true o false
    **/
    bool operator ==(const Letra &L);

};

#endif

