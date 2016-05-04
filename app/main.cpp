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
double KroghModel_std2param::r_cap = 6;
double KroghModel_std2param::r_t = 140;

double KroghModel_std3param::r_cap = 6;

int main()
{
    // 2 param
    ofstream outFile;
    outFile.open("040416_svd2paramFit_rcap-10_rt-140.dat", ios::out);

    int N = 15;
    vector<string> filename;
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset1.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset2.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset3.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset4.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset5.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset6.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset7.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset8.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset9.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset10.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset11.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset12.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset13.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset14.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset15.dat");

    for (int i = 0; i < N; i++) {
        Experiment myExp = Experiment(filename[i]);
        Fitsvd myFit = Fitsvd(&KroghModel_std2param::funcs, myExp.x, myExp.y, myExp.sigma, 1e-12);
        myFit.fit();
        KroghModel_std2param::set_parameters(myFit.a);
        outFile << filename[i] << endl;
        outFile << "a0: " << myFit.a[0] << endl;
        outFile << "a1: " << myFit.a[1]<< endl;
        outFile << "p_cap: " << KroghModel_std2param::p_cap << endl;
        outFile << "M: " << KroghModel_std2param::m << endl;
        outFile << "reduced_chisq: " << myFit.reduced_chisq << endl;
        outFile << "C00: " << myFit.covar(0,0) << endl;
        outFile << "C10: " << myFit.covar(1,0) << endl;
        outFile << "C11: " << myFit.covar(1,1) << endl;
        outFile << endl;
    }
    outFile.close();

    /*
    // 3 param
    ofstream outFile;
    outFile.open("040416_svd3paramFit_rcap-6.dat", ios::out);

    int N = 15;
    vector<string> filename;
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset1.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset2.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset3.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset4.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset5.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset6.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset7.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset8.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset9.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset10.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset11.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset12.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset13.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset14.dat");
    filename.push_back("/home/martejulie/master_project_data/dat_files/n_r_po2_data_from_dataset15.dat");

    outFile << "r_cap: " << KroghModel_std3param::r_cap << endl;
    for (int i = 0; i < N; i++) {
        Experiment myExp = Experiment(filename[i]);
        Fitsvd myFit = Fitsvd(&KroghModel_std3param::funcs, myExp.x, myExp.y, myExp.sigma, 1e-12);
        myFit.fit();
        KroghModel_std3param::set_parameters(myFit.a);
        outFile << filename[i] << endl;
        outFile << "a0: " << myFit.a[0] << endl;
        outFile << "a1: " << myFit.a[1]<< endl;
        outFile << "a2: " << myFit.a[2]<< endl;       
        outFile << "r_t: " << KroghModel_std3param::r_t << endl;
        outFile << "p_cap: " << KroghModel_std3param::p_cap << endl;
        outFile << "M: " << KroghModel_std3param::m << endl;
        outFile << "reduced_chisq: " << myFit.reduced_chisq << endl;
        outFile << "C00: " << myFit.covar(0,0) << endl;
        outFile << "C10: " << myFit.covar(1,0) << endl;
        outFile << "C20: " << myFit.covar(2,0) << endl;
        outFile << "C11: " << myFit.covar(1,1) << endl;
        outFile << "C21: " << myFit.covar(2,1) << endl;
        outFile << "C22: " << myFit.covar(2,2) << endl;
        outFile << endl;
    }
    outFile.close();
    */


    // 2 param, 15 data sets, study the threshold tolerance
    /*
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_August_30_2010_20100830_Place4_grid_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_04_2010_20100904_Place1_grid_Combined.dat";
    string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_07_2010_20100907_Place4_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_07_2010_20100907_Place5_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_07_2010_20100907_Place6_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_07_2010_20100907_Place11_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_07_2010_20100907_Place12_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_07_2010_20100907_Place14_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_07_2010_20100907_Place15_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_07_2010_20100907_Place16_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_08_2010_20100908_Place5_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_08_2010_20100908_Place6_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_08_2010_20100908_Place7_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_08_2010_20100908_Place14_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_08_2010_20100908_Place15_Combined.dat";

    ofstream outFile;
    outFile.open("080116_svd2param_fit_r_cap_3_rt_150_different_thresholds_datasetx.dat", ios::out);

    vector<double> thresh;
    thresh.push_back(1e-16);
    thresh.push_back(1e-14);
    thresh.push_back(1e-12);
    thresh.push_back(1e-11);
    thresh.push_back(1e-10);
    thresh.push_back(1e-9);
    thresh.push_back(1e-8);
    thresh.push_back(1e-7);
    thresh.push_back(1e-6);
    thresh.push_back(1e-5);
    int N = 10;

    outFile << filename << endl << endl;
    for (int i = 0; i < N; i++) {
        Experiment myExp = Experiment(filename);
        Fitsvd myFit = Fitsvd(&KroghModel_std2param::funcs, myExp.x, myExp.y, myExp.sigma, thresh[i]);
        myFit.fit();
        KroghModel_std2param::set_parameters(myFit.a);
        outFile << "thresh: " << thresh[i] << endl;
        outFile << "reduced_chisq: " << myFit.reduced_chisq << endl;
        outFile << "p_cap: " << KroghModel_std2param::p_cap << endl;
        outFile << "M: " << KroghModel_std2param::m << endl;
        outFile << "a0: " << myFit.a[0] << endl;
        outFile << "a1: " << myFit.a[1]<< endl;
        outFile << "C00: " << myFit.covar(0,0) << endl;
        outFile << "C10: " << myFit.covar(1,0) << endl;
        outFile << "C11: " << myFit.covar(1,1) << endl;
        outFile << endl;
    }
    outFile.close();
    */

    /*
    // 3 param, 15 data sets, study the threshold tolerance
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_August_30_2010_20100830_Place4_grid_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_04_2010_20100904_Place1_grid_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_07_2010_20100907_Place4_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_07_2010_20100907_Place5_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_07_2010_20100907_Place6_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_07_2010_20100907_Place11_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_07_2010_20100907_Place12_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_07_2010_20100907_Place14_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_07_2010_20100907_Place15_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_07_2010_20100907_Place16_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_08_2010_20100908_Place5_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_08_2010_20100908_Place6_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_08_2010_20100908_Place7_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_08_2010_20100908_Place14_Combined.dat";
    //string filename = "/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/n_r_po2_data_from_space_md9_4_adev_PO2_September_08_2010_20100908_Place15_Combined.dat";

    ofstream outFile;
    outFile.open("080116_svd3param_fit_r_cap_3_rt_150_different_thresholds_dataset10.dat", ios::out);

    vector<double> thresh;
    thresh.push_back(1e-20);
    thresh.push_back(1e-16);
    thresh.push_back(1e-14);
    thresh.push_back(1e-12);
    thresh.push_back(1e-11);
    thresh.push_back(1e-10);
    thresh.push_back(1e-9);
    thresh.push_back(1e-8);
    thresh.push_back(1e-7);
    thresh.push_back(1e-6);
    thresh.push_back(1e-5);
    thresh.push_back(1e-3);
    int N = 12;

    outFile << filename << endl << endl;
    for (int i = 0; i < N; i++) {
        Experiment myExp = Experiment(filename);
        Fitsvd myFit = Fitsvd(&KroghModel_std3param::funcs, myExp.x, myExp.y, myExp.sigma, thresh[i]);
        //myFit.fit();
        KroghModel_std3param::set_parameters(myFit.a);
        outFile << "thresh: " << thresh[i] << endl;
        outFile << "reduced_chisq: " << myFit.reduced_chisq << endl;
        outFile << "r_t: " << KroghModel_std3param::r_t << endl;
        outFile << "p_cap: " << KroghModel_std3param::p_cap << endl;
        outFile << "M: " << KroghModel_std3param::m << endl;
        outFile << "a0: " << myFit.a[0] << endl;
        outFile << "a1: " << myFit.a[1]<< endl;
        outFile << "a2: " << myFit.a[2]<< endl;
        outFile << "C00: " << myFit.covar(0,0) << endl;
        outFile << "C10: " << myFit.covar(1,0) << endl;
        outFile << "C20: " << myFit.covar(2,0) << endl;
        outFile << "C11: " << myFit.covar(1,1) << endl;
        outFile << "C21: " << myFit.covar(2,1) << endl;
        outFile << "C22: " << myFit.covar(2,2) << endl;
        outFile << endl;
    }
    outFile.close();
    */

    cout << "Hello World!" << endl;
    return 0;
}

