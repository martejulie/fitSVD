#include <experiment.h>
#include <iostream>

using namespace std;

int main()
{
    string testfile = "121115_dataSetForTestingPurpose_r_cap_1_rt_150_p_cap_70_M_0_0011_149.dat";
    Experiment my = Experiment(testfile);
    cout << my.countElements("1 2 3") << endl;
    //my.check_sigma("1 2 3 4");

    return 0;
}

