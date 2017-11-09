//  
//  forward_euler.cpp - Metodos Numericos II
//  Rubens Anderson de Sousa Silva - 362984 - Computação UFC 2017
//
//  

#ifndef forward_euler_hpp
#define forward_euler_hpp

//#include "problema_valor_inicial.hpp"
#include "estado.hpp"
#include "opeEstado.hpp"
#include "Funcao_S.hpp"

#include "matriz.hpp"
#include "opeMatriz.hpp"

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class forward_euler
{
public:
    forward_euler(Funcao_S * f, double a, double b, double epsilon);
    
    vector <estado> start(estado);
    
    estado find_next_si(estado Si, double ti);
private:
    
    Funcao_S * funcao_f;
    double  lInf;
    double  lSup;
    double  delta_t;
    int     n;
};


#endif /* forward_euler_hpp */
