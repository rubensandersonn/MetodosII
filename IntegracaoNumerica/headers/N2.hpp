//
//  N2.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/12/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef N2_imp_hpp
#define N2_imp_hpp

#include "N2.hpp"
#include "IntegralDupla.hpp"
#include <math.h>

class N2 : public Funcao_R2
{
public:
  N2 (){
  }

    double f(double s, double t)
    {

        return (-0.25)*(s + 1)*(t-1);

    }
private:

};


#endif /* N2_imp_hpp */
