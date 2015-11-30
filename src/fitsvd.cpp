#include "fitsvd.h"

Fitsvd::Fitsvd(Col<double> (*f)(double), Col<double> x, Col<double> y, Col<double> sigma) {
    /* Binds references to the data arrays x, y, and sigma, and to user-supplied function funcs(x)
     * that returns a Col<double> containing ma basis functions evaluated at x = x.
     */
    funcs = f;
    this->x = x;
    this->y = y;
    this->sigma = sigma;
    this->ndat = y.size();
}

void Fitsvd::fit() {
    /* Solve by singluar value decomposition the chisq minimization that fits for the coefficients
     * a[0..ma-1] of a function that depends linarly on a, y = sum_i(a_i * funcs_i(r).
     * Set answer values for a[0..ma-1], chisq, and the covariance matrix covar[0..ma-1][0..ma-1].
     */

    int i, j;
    double tmp;
    this->ma = funcs((this->x)[0]).size();       // number of basis functions
    this->dof = this->ndat - this->ma;           // degrees of freedom
    this->a.resize(this->ma);                    // model coefficients
    this->aa.resize(this->ndat, this->ma);       // design matrix
    this->b.resize(this->ndat);
    Col<double> afunc(this->ma);                 // basis functions

    for (i = 0; i < this->ndat; i++) {           // accumulate coefficients of the design matrix
        afunc = funcs((this->x)[i]);
        tmp = 1.0 / this->sigma[i];
        for (j = 0; j < this->ma; j++) aa(i,j) = afunc[j]*tmp;
        b[i] = this->y[i]*tmp;
    }

    svd(this->U, this->S, this->V, aa);         // singular value decomposition
    this->solve(b, this->a);            // solve for the coefficients
    this->calculate_chisq();
    this->calculate_covar();
}

void Fitsvd::solve(Col<double> b, Col<double> &x) {
    /* Solve A x = b for a vector x using the pseudoinverse of A as obtained by SVD.
     * If positive, thresh is the threshold value below which singular values are considered as zero.
     * If thresh is negative, a default based on expected roundoff error is used.
     */
    int i, j, jj;
    double s;

    Col<double> tmp(this->ma);
    double tsh = 1.e-12*this->S[0];
    for (j = 0; j < this->ma; j++) {
        s = 0.0;
        if (this->S[j] > tsh) {
            for (i = 0; i < this->ndat; i++) s += this->U(i,j)*b[i];
            s /= this->S[j];
        }
        tmp[j] = s;
    }
    for (j = 0; j < this->ma; j++) {
        s = 0.0;
        for (jj = 0; jj < this->ma; jj++) s += this->V(j,jj)*tmp[jj];
        x[j] = s;
    }
}

void Fitsvd::calculate_chisq() {
    /* Evaluate chi squared and reduced chi squared
     * chi^2 = |A*a - b|^2
     * reduced chi^2 = chi^2 / dof
     */
    int i, j;
    double sum;
    this->chisq = 0.0;
    for (i = 0; i < this->ndat; i++) {
        sum = 0.0;
        for (j = 0; j < this->ma; j++) sum += this->aa(i,j) * this->a[j];
        this->chisq += (sum - this->b[i])*(sum - this->b[i]);
    }
    this->reduced_chisq = this->chisq / this->dof;
}

void Fitsvd::calculate_covar() {
    // Evaluate the covariance matrix
    int i, j, k;
    double sum;
    this->covar.resize(this->ma, this->ma);
    double tsh = 1.e-12*this->S[0];
    for (i = 0; i < this->ma; i++) {
        for (j = 0; j < i+1; j++) {
            sum = 0.0;
            for (k = 0; k < this->ma; k++) if (this->S[k] > tsh)
                sum += this->V(i,k) * this->V(j,k) / (this->S[k]*this->S[k]);
            this->covar(j,i) = this->covar(i,j) = sum;
        }
    }
}
