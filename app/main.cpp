#include <iostream>
#include <experiment.h>
#include <fitsvd.h>
#include <kroghmodel_std2param.h>
#include <kroghmodel_std3param.h>

using namespace std;

double KroghModel_std2param::p_cap;
double KroghModel_std2param::m;

double KroghModel_std3param::r_t;
double KroghModel_std3param::p_cap;
double KroghModel_std3param::m;

// !set variables!
double KroghModel_std2param::r_cap = 1;
double KroghModel_std2param::r_t = 150;

double KroghModel_std3param::r_cap = 1;

int main()
{
    string filename = "/home/martejulie/master_project_code/fitSVD/271115_dataSetForTestingPurpose_r_cap_1_r_t_100_pcap_70_m_0_004_N_33.dat";
    Experiment myExp = Experiment(filename);
    Fitsvd myFit = Fitsvd(&KroghModel_std3param::funcs, myExp.x, myExp.y, myExp.sigma);
    myFit.fit();
    KroghModel_std3param::set_parameters(myFit.a);
    cout << myFit.a << endl;
    cout << "r_t: " << KroghModel_std3param::r_t << endl;

    /*
    ofstream outFile;
    outFile.open("021215_svd_fit_r_cap_1_r_t_150.dat", ios::out);

    int N = 15;
    vector<string> filename;
    filename.push_back("/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_August_30_2010_20100830_Place4_grid_Combined.dat");
    filename.push_back("/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_04_2010_20100904_Place1_grid_Combined.dat");
    filename.push_back("/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_07_2010_20100907_Place4_Combined.dat");
    filename.push_back("/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_07_2010_20100907_Place5_Combined.dat");
    filename.push_back("/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_07_2010_20100907_Place6_Combined.dat");
    filename.push_back("/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_07_2010_20100907_Place11_Combined.dat");
    filename.push_back("/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_07_2010_20100907_Place12_Combined.dat");
    filename.push_back("/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_07_2010_20100907_Place14_Combined.dat");
    filename.push_back("/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_07_2010_20100907_Place15_Combined.dat");
    filename.push_back("/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_07_2010_20100907_Place16_Combined.dat");
    filename.push_back("/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_08_2010_20100908_Place5_Combined.dat");
    filename.push_back("/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_08_2010_20100908_Place6_Combined.dat");
    filename.push_back("/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_08_2010_20100908_Place7_Combined.dat");
    filename.push_back("/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_08_2010_20100908_Place14_Combined.dat");
    filename.push_back("/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_08_2010_20100908_Place15_Combined.dat");

    for (int i = 0; i < N; i++) {
        Experiment myExp = Experiment(filename[i]);
        Fitsvd myFit = Fitsvd(&StandardKroghModel::funcs, myExp.x, myExp.y, myExp.sigma);
        myFit.fit();
        StandardKroghModel::set_parameters(myFit.a);
        outFile << filename[i] << endl;
        outFile << "a0: " << myFit.a[0] << endl;
        outFile << "a1: " << myFit.a[1]<< endl;
        //outFile << "r_cap: " << StandardKroghModel::r_cap << endl;
        //outFile << "r_t: " << StandardKroghModel::r_t << endl;
        outFile << "p_cap: " << StandardKroghModel::p_cap << endl;
        outFile << "M: " << StandardKroghModel::m << endl;
        outFile << "reduced_chisq: " << myFit.reduced_chisq << endl;
        outFile << "C00: " << myFit.covar(0,0) << endl;
        outFile << "C01: " << myFit.covar(0,1) << endl;
        outFile << "C11: " << myFit.covar(1,1) << endl;
        outFile << endl;
    }
    outFile.close();
    */

    cout << "Hello World!" << endl;
    return 0;
}

