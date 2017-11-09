//  
//  estado.cpp - Metodos Numericos II
//  Rubens Anderson de Sousa Silva - 362984 - Computação UFC 2017
//
//  

#ifndef Funcao_S_hpp
#define Funcao_S_hpp

#include "Funcao.hpp"
#include "estado.hpp"

class Funcao_S
{
public:
    virtual estado f(estado, double) = 0;
};

#endif /* Funcao_S_hpp */

