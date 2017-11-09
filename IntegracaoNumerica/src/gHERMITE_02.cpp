//
//  NC_F_P2.cpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#include "../headers/gHERMITE_02.hpp"
#include <math.h>

gHERMITE_02::gHERMITE_02(Funcao * f)
{
    m_pIntegrando = f;
}

double gHERMITE_02::integrar()
{
   return gHERMITE_02_integracao();
}

double gHERMITE_02::gHERMITE_02_integracao()
{
    double x1 = -0.707106;
    double x2 = -x1;

    double f1 = m_pIntegrando->f(x1);
    double f2 = m_pIntegrando->f(x2) ;

    return 1.772455 *(f1 + f2);
}
