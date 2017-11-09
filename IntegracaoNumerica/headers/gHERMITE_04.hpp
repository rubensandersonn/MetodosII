//
//  gHERMITE_04.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef gHERMITE_04_hpp
#define gHERMITE_04_hpp

#include "Integracao.hpp"

class gHERMITE_04 : public Integracao
{
public:
    gHERMITE_04(Funcao * f);

    virtual double integrar();

private:
    double  gHERMITE_04_integracao();

    Funcao *m_pIntegrando;
};


#endif /* gHERMITE_04_hpp */
