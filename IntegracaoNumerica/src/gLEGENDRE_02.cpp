//
//  NC_F_P2.cpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#include "../headers/gLEGENDRE_02.hpp"
#include <math.h>
#include <iostream>

using namespace std;

gLEGENDRE_02::gLEGENDRE_02(Funcao * f, double a, double b, int N, double epsilon)
{
    m_pIntegrando = f;
    m_lInf        = a;
    m_lSup        = b;
    m_precisao    = epsilon;
    m_particao    = N;

}

double gLEGENDRE_02::integrar()
{
    double integral = 0.0;

    if (m_particao >= 1) // se for por PARTIÇÃO
    {
        cout << "voce escolheu por particao de " << m_particao << endl;
        double step = (m_lSup - m_lInf)/m_particao;
        double linf, lsup;

        return gLEGENDRE_02_integracao(m_pIntegrando, m_lSup, m_lInf);

        for (int i = 0; i < m_particao; i++)
        {
            linf = m_lInf + i*step;
            lsup = linf   + step;

            integral += gLEGENDRE_02_integracao(m_pIntegrando, linf, lsup);
        }

        return integral;
    }
    else // SE FOR POR PRECISÃO
    {
        cout << "voce escolheu por precisao de " << m_precisao << endl;
        int    N           = 1;
        double oldintegral = 0.0;
        double step;
        double linf, lsup;

        integral = gLEGENDRE_02_integracao(m_pIntegrando, m_lInf, m_lSup);

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

                integral += gLEGENDRE_02_integracao(m_pIntegrando, linf, lsup);
            }


        } while (fabs(integral - oldintegral) > m_precisao);

        return integral;
    }

}

double gLEGENDRE_02::gLEGENDRE_02_integracao(Funcao * f, double a, double b)
{

    double x1 = - 0.57735;
    double x2 = -x1;

    double s1 = ((b+a) / 2) + ((b-a)/2)*x1;
    double s2 = ((b+a) / 2) + ((b-a)/2)*x2;

    double f1 = m_pIntegrando->f(s1);
    double f2 = m_pIntegrando->f(s2);

    double w1 = 1;
    double w2 = 1;

    cout << " raizes de _02 " << s1 << ", " << s2 << endl;
    cout << " f1 e f2 de_02 " << f1 << ", " << f2 << endl;

    return fabs(((b-a)/2)*(f1 + f2));
}
