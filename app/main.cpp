#include <experiment.h>
#include <iostream>

using namespace std;

int main()
{
    string testfile = "/home/martejulie/master_project_code/fitSVD/121115_dataSetForTestingPurpose_r_cap_1_rt_150_p_cap_70_M_0_0011_149.dat";
    Experiment my = Experiment(testfile);

    cout << "n: " << my.n << endl;

    cout << "Hello World!" << endl;
    return 0;
}

