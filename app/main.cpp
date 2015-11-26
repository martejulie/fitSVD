#include <iostream>
#include <experiment.h>
#include <fitsvd.h>
#include <standardkroghmodel.h>

using namespace std;

Col<double> myfunc(double x) {
    Col<double> f(2);
    f[0] = 1.0;
    f[1] = x;
    return f;
}

int main()
{
    string testfile = "/home/martejulie/master_project_code/fitSVD/121115_dataSetForTestingPurpose_r_cap_1_rt_150_p_cap_70_M_0_0011_149.dat";
    Experiment myExp = Experiment(testfile);
    StandardKroghModel myModel = StandardKroghModel(1, 150);

    Fitsvd myFit = Fitsvd(&myfunc, myExp.x, myExp.y, myExp.sigma); //&myfunc
    mytest.fit();

    cout << "Hello World!" << endl;
    return 0;
}

