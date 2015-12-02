#include "kroghmodel_std3param.h"

Col<double> KroghModel_std3param::funcs(double r) {
    // basis functions
    Col<double> f(3);
    f[0] = 1.0;
    f[1] = r*r;
    f[2] = log(r);
    return f;
}

void KroghModel_std3param::set_parameters(Col<double> a) {
    /*
     * Args:
     *  a (Col<double>): model coefficients
     *
     * Sets:
     *  p_cap (double): model parameter
     *  m (double): model parameter
     *  r_t (double): model parameter
     */
    m = calculate_m(a[1]);
    r_t = calculate_rt(a[1], a[2]);
    p_cap = calculate_pcap(a[0], a[1]);
}

double KroghModel_std3param::calculate_pcap(double a0, double a1) {
    /*
     * Args:
     *  a0 (double): model coefficient
     *  a1 (double): model coefficient
     *
     * Returns:
     *  pval (double): p_cap
     */
    double pval = a0 + a1*r_cap*r_cap - 2.0*a1*r_t*r_t;
    return pval;
}

double KroghModel_std3param::calculate_m(double a1) {
    /*
     * Args:
     *  a1 (double): model coefficient
     *
     * Return:
     * mval (double): m
     */
    double mval = 4.0*a1;
    return mval;
}

double KroghModel_std3param::calculate_rt(double a1, double a2) {
    /*
     * Args:
     *  a1 (double): model coefficient
     *  a2 (double): model coefficient
     *
     * Return:
     *  rtval (double): r_t
     */
    double rtval = pow(a2/(2*a1), 0.5);
    return rtval;
}
