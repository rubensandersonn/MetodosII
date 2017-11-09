//
//  NC_F_P2.cpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#include "../headers/gHERMITE_03.hpp"
#include <math.h>

gHERMITE_03::gHERMITE_03(Funcao * f)
{
    m_pIntegrando = f;
}

double gHERMITE_03::integrar()
{
   return gHERMITE_03_integracao();
}

double gHERMITE_03::gHERMITE_03_integracao()
{

    double x1 = -1.22447;
    double x2 = 0;
    double x3 = -x1;

    double pi = 3.1416;

    double w1 =0.295409;
    double w2 = 1.181637;

    return w1*(m_pIntegrando->f(x1) + m_pIntegrando->f(x3) ) + w2* m_pIntegrando->f(x2);
}
