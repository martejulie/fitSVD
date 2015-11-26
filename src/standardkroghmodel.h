#ifndef STANDARDKROGHMODEL_H
#define STANDARDKROGHMODEL_H

#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

class StandardKroghModel {
    /*
     *
     */

public:
    //double m;           //
    //double p_cap;       //

    Col<double> funcs(double r);

    StandardKroghModel();
    StandardKroghModel(double r_cap, double r_t);

private:
    double r_cap;
    double r_t;
};

#endif // STANDARDKROGHMODEL_H
