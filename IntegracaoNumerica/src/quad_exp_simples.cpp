//
//  NC_F_P2.cpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#include "../headers/quad_exp_simples.hpp"
#include "../headers/Funcao_exp_simples.hpp"
#include "../headers/NC_A_P2.hpp"
#include <math.h>
#include <iostream>

using namespace std;

quad_exp_simples::quad_exp_simples(Funcao * f, double a, double b, double epsilon)
{
   F = f;

    b_func = b; a_func = a;
    epsilon_func = epsilon;

}

double quad_exp_simples::integrar()
{
    if(epsilon_func > 0){

        double NewIntegral = 0;
        double OldIntegral = 0;

        double inf = 0;
        double sup = 0;

        int i = 0;

        double step = 1.0;

        do{
            i++;
            OldIntegral = NewIntegral;

            inf = -i * step;
            sup = i * step;

            NewIntegral = quad_exp_simples_integracao(inf, sup);

            /*cout << "   NewIntegral = " << NewIntegral << endl;
            cout << "   oldIntegral = " << OldIntegral << endl;*/

        }while(fabs(NewIntegral - OldIntegral) > epsilon_func);

        return NewIntegral;
    }else{
        return 0;
    }
}

double quad_exp_simples::quad_exp_simples_integracao(double a, double b)
{

    Funcao_exp_simples * fe = new Funcao_exp_simples(F, a_func, b_func);

    Integracao *pintegrObj;

    pintegrObj = new NC_A_P2(fe, a, b, 0, epsilon_func);

    return pintegrObj->integrar();
}
