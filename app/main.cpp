#include <iostream>
#include <experiment.h>
#include <fitsvd.h>
#include <standardkroghmodel.h>
#include <typeinfo>

using namespace std;

Col<double> myfunc(double x) {
    Col<double> f(2);
    f[0] = 1.0;
    f[1] = x;
    return f;
}

double StandardKroghModel::r_cap = 1;
double StandardKroghModel::r_t = 100;

int main()
{
    //string testfile = "/home/martejulie/master_project_code/fitSVD/121115_dataSetForTestingPurpose_r_cap_1_rt_150_p_cap_70_M_0_0011_149.dat";
    string testfile = "/home/martejulie/master_project_code/fitSVD/271115_dataSetForTestingPurpose_r_t_100_a0_70_a1_0_001_N_33.dat";
    Experiment myExp = Experiment(testfile);
    Fitsvd myFit = Fitsvd(&StandardKroghModel::funcs, myExp.x, myExp.y, myExp.sigma); //&myfunc
    myFit.fit();
    cout << myFit.a << endl;

//    cout << typeid(myFit.a[0]).name() << endl;
//    cout << typeid(b).name() << endl;

    //double eps = 1e-4;
    //cout << (70.0-eps) << endl;
    //cout << (70.0+eps) << endl;

    cout << "Hello World!" << endl;
    return 0;
}

