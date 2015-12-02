#include "kroghmodel_std2param.h"

Col<double> KroghModel_std2param::funcs(double r) {
    // basis functions
    Col<double> f(2);
    f[0] = 1.0;
    f[1] = r*r - 2 * r_t*r_t * log(r);
    return f;
}

void KroghModel_std2param::set_parameters(Col<double> a) {
    /*
     * Args:
     *  a (Col<double>): model coefficients
     *
     * Sets:
     *  p_cap (double): model parameter
     *  m (double): model parameter
     */
    p_cap = calculate_pcap(a[0], a[1]);
    m = calculate_m(a[1]);
}


double KroghModel_std2param::calculate_pcap(double a0, double a1) {
    /*
     * Args:
     *  a0 (double): model coefficient
     *  a1 (double): model coefficient
     *
     * Returns:
     *  pval (double): p_cap
     */
    double pval = a0 + a1*r_cap*r_cap - 2*a1*r_t*r_t*log(r_cap);
    return pval;
}

double KroghModel_std2param::calculate_m(double a1) {
    /*
     * Args:
     *  a1 (double): model coefficient
     *
     * Return:
     * mval (double): m
     */
    double mval = 4*a1;
    return mval;
}
