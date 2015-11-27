#include "standardkroghmodel.h"

//StandardKroghModel::StandardKroghModel(double r_cap, double r_t) {
//    this->r_cap = r_cap;
//    this->r_t = r_t;
//}

Col<double> StandardKroghModel::funcs(double r) {
    // basis functions
    Col<double> f(2);
    f[0] = 1.0;
    f[1] = r*r - 2 * r_t*r_t * log(r);
    return f;
}
