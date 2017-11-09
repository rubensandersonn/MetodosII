//
//  NC_F_P2.cpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#include "../headers/gCHEBSHEV.hpp"
#include <math.h>

gCHEBSHEV::gCHEBSHEV(Funcao * f, double a, double b, int N)
{
    m_pIntegrando = f;
    m_lInf        = a;
    m_lSup        = b;
    m_particao    = N;

}

double gCHEBSHEV::integrar()
{
    double integral = 0.0;
    double pi = 3.1416;
    double s = 0.0;

    if (m_particao >= 1)
    {
        for (int i = 1; i <= m_particao; i++)
        {
            s = (m_lSup + m_lInf)/2 + ( (m_lSup - m_lInf) / 2 )*cos(pi*(i - 0.5) / m_particao);

            integral = integral + m_pIntegrando->f(s);
        }

        return (pi / m_particao) * integral;
    }
    else // entrou errado: retorne 0
    {
        return 0;
    }

}
