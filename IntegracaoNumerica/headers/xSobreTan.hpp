//
//  1sobreTan(x).hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/12/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef xSobreTan_hpp
#define xSobreTan_hpp

#include <math.h>

class xSobreTan : public Funcao
{
public:
	xSobreTan(){
	}

    double f(double x)
    {

		return x/ tan(x);

    }

};


#endif /* xSobreTan_hpp */
