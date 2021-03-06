//
//  NC_A_P2.cpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#include "../headers/NC_A_P2.hpp"
#include <math.h>
#include <iostream>

using namespace std;

NC_A_P2::NC_A_P2(Funcao * f, double a, double b, int N, double epsilon)
{
    m_pIntegrando = f;
    m_lInf        = a;
    m_lSup        = b;
    m_precisao    = epsilon;
    m_particao    = N;

}

double NC_A_P2::integrar()
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

            integral += NC_A_P2_integracao(m_pIntegrando, linf, lsup);
        }

        return integral;
    }
    else
    {
        int    N           = 1;
        double oldintegral = 0.0;
        double step;
        double linf, lsup;

        integral = NC_A_P2_integracao(m_pIntegrando, m_lInf, m_lSup);

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

                integral += NC_A_P2_integracao(m_pIntegrando, linf, lsup);
            }

    //        cout << "\nDIFERENCA ENTRE OLD E NEW INTEGRAL: " << fabs(integral - oldintegral) << " com precisao de " << m_precisao << endl;
        } while (fabs(integral - oldintegral) > m_precisao);

        return integral;
    }

}

double NC_A_P2::NC_A_P2_integracao(Funcao * f, double a, double b)
{
    double h = (b - a)/4.0;

  //    cout << " DENTRO DE NC: [" << a << ", " << b << "]" << endl;

    double fa3h = m_pIntegrando->f(a + 3*h);
    double fah = m_pIntegrando->f(a+h);
    double fa2h = m_pIntegrando->f(a+2*h);

/*
    cout << "\nfah = " << fah << endl;
    cout << "fa2h = " << fa2h << endl;
    cout << "fa3h = " << fa3h << endl;
*/
    double resultado = ((4.0*h/3)*(2.0*fah - fa2h + 2.0*fa3h));

    return fabs(resultado);
}
