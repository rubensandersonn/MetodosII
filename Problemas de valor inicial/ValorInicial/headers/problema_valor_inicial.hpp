//  
//  forward_euler.cpp - Metodos Numericos II
//  Rubens Anderson de Sousa Silva - 362984 - Computação UFC 2017
//
// 

#ifndef problema_valor_inicial_hpp
#define problema_valor_inicial_hpp

#include "Funcao_S.hpp"
#include "Funcao.hpp"
#include "estado.hpp"
#include <vector>
#include <iostream>


class problema_valor_inicial
{
public:

    virtual vector<estado> start(estado) = 0;

};

#endif /* problema_valor_inicial_hpp */
