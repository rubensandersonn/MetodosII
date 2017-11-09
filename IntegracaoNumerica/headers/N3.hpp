//
//  N3.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/12/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef N3_imp_hpp
#define N3_imp_hpp

#include "N3.hpp"
#include "IntegralDupla.hpp"
#include <math.h>

class N3 : public Funcao_R2
{
public:
  N3 (){
  }

    double f(double s, double t)
    {

        return (0.25)*(s + 1)*(t+1);

    }
private:

};


#endif /* N3_imp_hpp */
