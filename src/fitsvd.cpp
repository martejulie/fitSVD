#include "fitsvd.h"

Fitsvd::Fitsvd(double (*f)(double) ) {
    cout << "hello class" << endl;
    funcs = f;
    //cout << "funcsverdi: " << (*funcs)(1) << endl;
}
