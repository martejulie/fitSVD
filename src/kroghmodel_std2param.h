#ifndef KROGHMODEL_STD2PARAM_H
#define KROGHMODEL_STD2PARAM_H

#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

class KroghModel_std2param {
    /* Single-Vessel Transport Model
     * Predicts the radial variation in tissue O2 partial pressure (P)
     *
     * The equation is given by:
     *
     * P(r) = p_cap + m0/(4K)(r^2 - r_cap^2) - (m0*r_t^2)/(2*K)*ln(r/r_cap)
     *
     * where
     *
     * r = radial coordinate
     * r_cap = capillary radius
     * r_t = tissue radius
     * p_cap = capillary P
     * m0 = tissue O2 consumption rate
     * K = The Krogh diffusion coefficient
     *
     * We can rewrite the equation as:
     *
     * P(r) = a0*X0 + a1*X1
     *
     * where the coeffisients a0 and a1 are given by
     *
     * a0 = (p_cap - m*r_cap^2/4 + m*r_t^2*ln(r_cap)/2)
     * a1 = m/4
     *
     * and the basis functions X0 and X1 are given by
     *
     * X0 = 1
     * X1 = (r^2 - r*r_t^2*ln(r))
     *
     * The parameter m is equal to m0/K.
     */

public:
    static double m;
    static double p_cap;

    static Col<double> funcs(double r);
    static void set_parameters(Col<double> a);
    static double calculate_pcap(double a0, double a1);
    static double calculate_m(double a1);

private:
    static double r_cap;
    static double r_t;
};

#endif // KROGHMODEL_STD2PARAM_H
