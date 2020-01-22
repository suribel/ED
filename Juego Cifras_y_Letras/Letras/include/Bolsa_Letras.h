#ifndef __Bolsa_Letras_h__
#define __Bolsa_Letras_h__

#include <fstream>
#include <iostream>
#include <vector>
#include "Conjunto_Letras.h"

using namespace std;

class Bolsa_Letras{
private:
    //Utilizo vector ya que contiene el Random access iterators y es util para la funcion sacar
    vector<char> bolsa;
public:
    /**
    @brief Construye una Bolsa de Letras vacía.
    **/
    Bolsa_Letras();
    /**
    @brief Devuelve el tamaño de la Bolsa
    @return el tamaño
    **/
    int size() const;

    /**
    @brief introduce en la bolsa un numero de caracteres segun los parametros de la letra
    @param CL: El conjunto de letras del que se van a introducir los caracteres
    **/
    void llenar(const Conjunto_Letras &CL);

    /**
    @brief Saca un numero de caractares aleatoriamente
    @param num_letras: el numero de caracteres que se sacan
    @return un vector con los caracteres
    **/
    vector<char> sacar(int num_letras);

    /**
    @brief Escribe en un flujo de salida una Bolsa de Letras
    @param os:flujo de salida
    @param BL: el objeto Bolsa de Letras que se escribe
    @return el flujo de salida
    **/
    friend ostream & operator<<(ostream & os, const Bolsa_Letras &BL);



};

#endif