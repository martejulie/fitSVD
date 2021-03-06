#ifndef FITSVD_H
#define FITSVD_H

#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

typedef Col<double> (*myFuncs)(double);

class Fitsvd {
    /* Object for general linear leastsquare fitting using singular value decomposition.
     * Call constructor to bind data vectors and fitting functions.
     * Then call fit, which sets the output quantitites a, covar, and chisq.
     */

public:
    Col<double> a;              // vector of fitted coefficients
    Mat<double> covar;          // covariance matrix
    double chisq;               // chi square of the fit
    double reduced_chisq;       // chi square divided by the degrees of freedom

    void fit();

    Fitsvd();
    Fitsvd(Col<double> (*f)(double), Col<double>, Col<double>, Col<double>, double);

private:
     myFuncs funcs;
     int ndat;                   // number of data points
     int ma;                     // number of basis functions
     int dof;                    // degrees of freedom
     double thresh;

     // elementes of the SVD
     mat U;
     vec S;
     mat V;

     // experimental values
     Col<double> x;
     Col<double> y;
     Col<double> sigma;

     // helping variables
     Mat<double> aa;       // design matrix
     Col<double> b;

     void solve(Col<double> b, Col<double>& x);

     void calculate_chisq();
     void calculate_covar();
};

#endif // FITSVD_H
