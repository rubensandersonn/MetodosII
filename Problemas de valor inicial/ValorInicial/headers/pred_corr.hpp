//  
//  pred_corr.cpp - Metodos Numericos II
//  Rubens Anderson de Sousa Silva - 362984 - Computação UFC 2017
//
//  

#ifndef pred_corr_hpp
#define pred_corr_hpp

#include <iostream>
#include <math.h>
#include <vector>

#include "estado.hpp"
#include "opeEstado.hpp"
#include "opeMatriz.hpp"
#include "Funcao_S.hpp"
#include "r_k_4.hpp"

using namespace std;

class pred_corr
{
public:
    pred_corr(Funcao_S * f, double a, double b, double epsilon);
    
    virtual std::vector<estado> start(estado);
    
    estado find_next_si(vector<estado> v, int i);
private:
    
    Funcao_S * funcao_f;
    double  lInf;
    double  lSup;
    double  delta_t;
    int     n;
};


#endif /* pred_corr_hpp */
