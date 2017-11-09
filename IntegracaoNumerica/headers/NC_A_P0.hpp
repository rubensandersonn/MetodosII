//
//  NC_A_P0.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/12/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef NC_A_P0_hpp
#define NC_A_P0_hpp

#include "Integracao.hpp"

class NC_A_P0 : public Integracao
{
public:
    NC_A_P0(Funcao * f, double a, double b, int N, double epsilon);
    
    virtual double integrar();
    
private:
    double  NC_A_P0_integracao(Funcao * f, double a, double b);
    
    Funcao *m_pIntegrando;
    double  m_lInf;
    double  m_lSup;
    double  m_precisao;
    int     m_particao;
};

#endif /* NC_A_P0_hpp */
