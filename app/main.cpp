#include <experiment.h>
#include <fitsvd.h>
#include <iostream>

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
    Experiment my = Experiment(testfile);

    cout << "n: " << my.n << endl;

    Fitsvd mytest = Fitsvd(myfunc, my.x, my.y, my.sigma); //&myfunc);

    cout << "Hello World!" << endl;
    return 0;
}

