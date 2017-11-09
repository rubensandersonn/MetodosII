//  
//  estado.cpp - Metodos Numericos II
//  Rubens Anderson de Sousa Silva - 362984 - Comsetação UFC 2017
//
//  

#ifndef estado_hpp
#define estado_hpp

#include <math.h>

class estado
{
public:
    estado(double U1, double U2, double V1, double V2){
        u1 = U1;
        u2 = U2;
        v2 = V2;
        v1 = V1;
    }
    
    double u1;
    double u2;

    double v1;
    double v2;

    
private:
    

};


#endif /* estado_hpp */
