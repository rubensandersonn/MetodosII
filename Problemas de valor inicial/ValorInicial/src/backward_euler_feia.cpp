//  
//  backward_euler.cpp - Metodos Numericos II
//  Rubens Anderson de Sousa Silva - 362984 - Computação UFC 2017
//
/*
  a implementar:
        estado.hpp
        opeEstado.hpp
        Funcao_S.hpp
*/

#include "../headers/backward_euler.hpp"


backward_euler::backward_euler(Funcao_S * f, double a, double b, double dt)
{
    funcao_f = f;
    lInf        = min(a,b);
    lSup        = max(a,b);
    delta_t    = dt;
    n    = fabs(b-a) / dt;

}

vector<estado> backward_euler::start(estado s0, matriz A, matriz F) // espero receber a matriz doida de be
{
    vector<estado> r;
    r.push_back(s0);
    int i = 0;

    double ti = lInf;
    do{

        r.push_back(backward_euler::find_next_si(r[i], ti));
        i++;
        ti = lInf + i*delta_t;

    }while(ti < lSup);

    return r;
}

estado backward_euler::find_next_si(estado Si, double ti, matriz A, matriz F)
{
    // isto só funciona para o exempĺo da função dos carrinhos... infelizmente

    

            // fazendo a matriz A...

            double r11 = k1/m1;
            double r21 = k2/m1;
            double r22 = k2/m2;

            double c20 = -dt*(r11 + r21);
            double c21 = dt*(r21);
            double c30 = dt*(r22);
            double c31 = -dt*(r22);

            matriz * A = new matriz(4);

            matriz * I = new matriz(4);

            // começa com identidade, então preciso zerar A

            A->push(0.0,0,0);
            A->push(0.0,1,1);
            A->push(0.0,2,2);
            A->push(0.0,3,3);

            A->push(dt, 0,2);
            A->push(dt, 1,3);

            A->push(c20, 2,0);
            A->push(c21, 2,1);

            A->push(c30, 3,0);
            A->push(c31, 3,1);

            matriz I_A = opeMatriz::menos(*I, *A);

            // fazendo o vetor x resultado...

                // F vetor que relaciona as forças

            matriz * F = new matriz(1);

            F->push(0.0 , 0 ,0);
            F->push(( F1->f(dt + ti) * dt) / m1  , 2 ,0);
            F->push(( F2->f(dt + ti) * dt) / m2  , 3 ,0);

    matriz s = opeEstado::transformaEstadoMatriz(Si);

    matriz x = opeMatriz::mais(s, F);



    vector<matriz> LU = opeMatriz::makeLU(A);

    matriz r = opeMatriz::resolverSLComLU(LU,x);

    estado result = opeEstado::transformaMatrizEstado(r);

    return result;

}
