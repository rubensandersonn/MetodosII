//  
//  r_k_4.cpp - Metodos Numericos II
//  Rubens Anderson de Sousa Silva - 362984 - Computação UFC 2017
//
/*
  a implementar:
        estado.hpp
        opeEstado.hpp
            somaEstados
            multiplyEstadoByEscalar
        Funcao_S.hpp
*/

#include "../headers/r_k_4.hpp"
#include <iostream>
#include <math.h>
#include <vector>

#using namespace std;

r_k_4::r_k_4(Funcao_S * f, double a, double b, double epsilon)
{
    funcao_f = f;
    lInf        = min(a,b);
    lSup        = max(a,b);
    delta_t    = epsilon;
    n    = fabs(b-a) / epsilon;

}

vector<estado> r_k_4::start(estado s0)
{
    vector<estado> r;
    r.push_back(s0);

    int i = 0;
    double ti = lInf;
    do{

        r.push_back(r_k_4::find_next_si(r[i], ti));
        i++;
        ti = ti + i*(lSup - lInf)/n;

    }while(ti < lSup);

    return r;
}

estado r_k_4::find_next_si(estado Si, double ti)
{
    // Si + 1/4 * = Si + dt/4 f(Si, ti)
    // Si + 2/4 * = Si+1/4 + dt/4 f(Si+1/4, ti+1/4)
    // Si + 3/4 * = Si+2/4 + dt/4 f(Si+2/4, ti+2/4)
    // Si + 4/4 * = Si+3/4 + dt/4 f(Si+3/4, ti+3/4)
    // Si+1 = Si + (dt/90) * (7 fi + 32 f+1/4 + 12 fi-2/4 + 32 fi-3/4 + 7 fi+1)

    estado s14;
    estado s24;
    estado s34;
    estado s44;

    forward_euler * fr1 = new forward_euler(funcao_f, lInf, linf + delta_t/4, delta_t/4);
    forward_euler * fr2 = new forward_euler(funcao_f, linf + (1*delta_t)/4 , linf + (2*delta_t)/4, delta_t/4);
    forward_euler * fr3 = new forward_euler(funcao_f, linf + (2*delta_t)/4 , linf +  (3*delta_t)/4, delta_t/4);
    forward_euler * fr4 = new forward_euler(funcao_f, linf + (3*delta_t)/4 , linf +  (4*delta_t)/4, delta_t/4);
    forward_euler * fr5 = new forward_euler(funcao_f, linf + (3*delta_t)/4 , linf +  (4*delta_t)/4, delta_t/4);

    vector<estado> v = fr1->start(Si);
    s14 = v[0];


    v = fr2->start(s14);
    s24 = v[0];

    v = fr3->start(s24);
    s34 = v[0];

    v = fr4->start(s34);
    s44 = v[0];

    estado  s0 = opeEstado::multiplyEstadoByEscalar(Si, 7);
     s14 = opeEstado::multiplyEstadoByEscalar(s14, 32);
     s24 = opeEstado::multiplyEstadoByEscalar(s24, 12);
     s34 = opeEstado::multiplyEstadoByEscalar(s34, 32);
     s44 = opeEstado::multiplyEstadoByEscalar(s44, 7);

    estado R = opeEstado::somaEstados(s0, s14);
     R = opeEstado::somaEstados(R, s24);
     R = opeEstado::somaEstados(R, s34);
     R = opeEstado::somaEstados(R, s44);

    return opeEstado::multiplyEstadoByEscalar(R, delta_t/90);
}
