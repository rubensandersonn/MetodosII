//
//  NC_A_P1.cpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/23/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#include "../headers/NC_A_P1.hpp"
#include <math.h>
#include <iostream>

using namespace std;



NC_A_P1::NC_A_P1(Funcao * f, double a, double b, int N, double epsilon)
{
    m_pIntegrando = f;
    m_lInf        = a;
    m_lSup        = b;
    m_precisao    = epsilon;
    m_particao    = N;

}

double NC_A_P1::integrar()
{
    double integral = 0.0;

    if (m_particao >= 1)
    {
        double step = (m_lSup - m_lInf)/m_particao;
        double linf, lsup;

        for (int i = 0; i < m_particao; i++)
        {
            linf = m_lInf + i*step;
            lsup = linf   + step;

            integral += NC_A_P1_integracao(m_pIntegrando, linf, lsup);
        }

        return integral;
    }
    else
    {
        int    N           = 1;
        double oldintegral = 0.0;
        double step;
        double linf, lsup;

        integral = NC_A_P1_integracao(m_pIntegrando, m_lInf, m_lSup);

        do
        {
            oldintegral = integral;
            integral    = 0.0;

            N = N*2;

            step = (m_lSup - m_lInf)/N;

            for (int i = 0; i < N; i++)
            {
                linf = m_lInf + i*step;
                lsup = linf   + step;

                integral += NC_A_P1_integracao(m_pIntegrando, linf, lsup);
            }


        } while (fabs(integral - oldintegral) > m_precisao);

        return integral;
    }

}

double NC_A_P1::NC_A_P1_integracao(Funcao * f, double a, double b)
{
    double h = (b - a)/3.0;

    // consertando as merdas que o computador faz!
    double divisor = b-a;
    double dividendo = 2;

    dividendo *= m_pIntegrando->f(a+h) + m_pIntegrando->f(a+2*h);

    cout << "divisor: " << divisor << " , dividendo: " << dividendo << " , resultado: " << divisor / dividendo << endl;

    return divisor / dividendo;
    //return ((b-a)/(2.0*m_pIntegrando->f((a+h)) + m_pIntegrando->f((a+2*h))));
}
