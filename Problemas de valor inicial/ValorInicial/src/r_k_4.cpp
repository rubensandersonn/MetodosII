//  
//  r_k_3.cpp - Metodos Numericos II
//  Rubens Anderson de Sousa Silva - 362984 - Computação UFC 2017
//
/*
  a implementar:
        estado.hpp
        opeEstado.hpp
            somaEstados
            multiplyByEscalar
        Funcao_S.hpp
*/

#include "../headers/r_k_4.hpp"



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
        ti = lInf + i*delta_t;

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

    estado s13 = Si;
    estado s23 = Si;
    estado s33 = Si;
  
    forward_euler * fr1 = new forward_euler(funcao_f, ti, ti + delta_t/3, delta_t/3);
    forward_euler * fr2 = new forward_euler(funcao_f, ti + (1*delta_t)/3 , ti + (2*delta_t)/3, delta_t/3);
    forward_euler * fr3 = new forward_euler(funcao_f, ti + (2*delta_t)/3 , ti +  (3*delta_t)/3, delta_t/3);
    
    vector<estado> v = fr1->start(Si);
    s13 = v[1];


    v = fr2->start(s13);
    s23 = v[1];

    v = fr3->start(s23);
    s33 = v[1];


    estado  s0 = Si;
     s13 = opeEstado::multiplyByEscalar(s13, 3);
     s23 = opeEstado::multiplyByEscalar(s23, 3);
    
    estado R = opeEstado::somaEstados(s0, s13);
     R = opeEstado::somaEstados(R, s23);
     R = opeEstado::somaEstados(R, s33);


    R = opeEstado::multiplyByEscalar(R, delta_t/8);
    
    return opeEstado::somaEstados(Si, R);
}
