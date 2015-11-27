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
    static double m;           //
    static double p_cap;       //

    static Col<double> funcs(double r);
    static void set_parameters(Col<double> a);
    static double calculate_pcap(double a0, double a1);
    static double calculate_m(double a1);

private:
    static double r_cap;
    static double r_t;
};

#endif // STANDARDKROGHMODEL_H
