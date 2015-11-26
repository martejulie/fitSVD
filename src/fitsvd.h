#ifndef FITSVD_H
#define FITSVD_H

#include <iostream>
#include <armadillo>
//#include <nr3.h>
//#define SQR(x) ((x)*(x))
//#include <math.h>

using namespace std;
using namespace arma;

typedef double (*myFuncs)(double);

class Fitsvd {
    /*
     *
    */

public:
//    Col<double> (*funcs)(double);

    Fitsvd();
    Fitsvd(double (*f)(double));

private:
     myFuncs funcs;

};


//Fitsvd(Col<double> (*funcs)(double)

#endif // FITSVD_H
