//
//  NC_F_P2.cpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#include "../headers/NC_F_P3.hpp"
#include <math.h>

NC_F_P3::NC_F_P3(Funcao * f, double a, double b, int N, double epsilon)
{
    m_pIntegrando = f;
    m_lInf        = a;
    m_lSup        = b;
    m_precisao    = epsilon;
    m_particao    = N;

}

double NC_F_P2::integrar()
{
    double integral = 0.0;

    if (m_particao >= 1) // se for por PARTIÇÃO
    {
        double step = (m_lSup - m_lInf)/m_particao;
        double linf, lsup;

        for (int i = 0; i < m_particao; i++)
        {
            linf = m_lInf + i*step;
            lsup = linf   + step;

            integral += NC_F_P3_integracao(m_pIntegrando, linf, lsup);
        }

        return integral;
    }
    else // SE FOR POR PRECISÃO
    {
        int    N           = 1;
        double oldintegral = 0.0;
        double step;
        double linf, lsup;

        integral = NC_F_P3_integracao(m_pIntegrando, m_lInf, m_lSup);

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

                integral += NC_F_P3_integracao(m_pIntegrando, linf, lsup);
            }


        } while (fabs(integral - oldintegral) > m_precisao);

        return integral;
    }

}

double gLEGENDRE_01::gLEGENDRE_01_integracao(Funcao * f, double a, double b)
{
    double h = (b - a)/3;
    return (3*h/8)*(m_pIntegrando->f(a) + 3.0*m_pIntegrando->f(a+h) + 3.0 * m_pIntegrando->f(a + 2*h) + m_pIntegrando->f(a + 3*h));
}
