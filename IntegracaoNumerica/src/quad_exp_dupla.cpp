//
//  NC_F_P2.cpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#include "../headers/quad_exp_dupla.hpp"
#include "../headers/Funcao_exp_dupla.hpp"
#include "../headers/NC_A_P3.hpp"
#include <math.h>
#include <iostream>

using namespace std;

quad_exp_dupla::quad_exp_dupla(Funcao * f, double a, double b, double epsilon)
{
   F = f;

    b_func = b; a_func = a;
    epsilon_func = epsilon;

}

double quad_exp_dupla::integrar()
{
    double integral = 0.0;

    if (epsilon_func > 0 )
    {
//        cout << "voce escolheu por precisao de " << epsilon_func << endl;

        double oldintegral = 0.0;
        double step = 0.1;
        double linf = 0, lsup = 0;

        integral = 0;

        int i = 0;

        do
        {
            i++;
            oldintegral = integral;

            lsup = i*step;
            linf = - i*step;

            integral = quad_exp_dupla_integracao(linf, lsup);
/*
            cout << "NewIntegral = " << integral << endl;
            cout << "OldIntegral = " << oldintegral << endl;
*/
        } while (fabs(integral - oldintegral) > epsilon_func);

        return integral;
    }

    return 0;
}

double quad_exp_dupla::quad_exp_dupla_integracao(double a, double b)
{

    Funcao_exp_dupla * fe = new Funcao_exp_dupla(F, a_func, b_func);

    Integracao *pintegrObj;

    pintegrObj = new NC_A_P3(fe, a, b, 0, epsilon_func);

    return pintegrObj->integrar();
}
