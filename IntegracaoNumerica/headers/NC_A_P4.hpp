//
//  NC_A_P4.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef NC_A_P4_hpp
#define NC_A_P4_hpp

#include "Integracao.hpp"

class NC_A_P4 : public Integracao
{
public:
    NC_A_P4(Funcao * f, double a, double b, int N, double epsilon);
    
    virtual double integrar();
    
private:
    double  NC_A_P4_integracao(Funcao * f, double a, double b);
    
    Funcao *m_pIntegrando;
    double  m_lInf;
    double  m_lSup;
    double  m_precisao;
    int     m_particao;
};


#endif /* NC_A_P4_hpp */
