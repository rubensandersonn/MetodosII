//
//  NC_F_P2.cpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#include "../headers/gHERMITE_04.hpp"
#include <math.h>

gHERMITE_04::gHERMITE_04(Funcao * f)
{
    m_pIntegrando = f;
}

double gHERMITE_04::integrar()
{
   return gHERMITE_04_integracao();
}

double gHERMITE_04::gHERMITE_04_integracao()
{

    double x1 = -1.65068;
    double x2 = -0.524648;
    double x3 = -x2;
    double x4 = -x1;

    double spi = pow(3.1416, 0.5);

    double w2 = 0.804913;
    double w1 = 0.061313;

    return w1*(m_pIntegrando->f(x1) + m_pIntegrando->f(x4) ) + w2*( m_pIntegrando->f(x2) + m_pIntegrando->f(x3));
}
