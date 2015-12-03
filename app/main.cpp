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
double KroghModel_std2param::r_cap = 3;
double KroghModel_std2param::r_t = 120;

double KroghModel_std3param::r_cap = 3;

int main()
{
    // 3 param, 8 mice
    ofstream outFile;
    outFile.open("031215_svd3param_fit_8mice_r_cap_3.dat", ios::out);

    int N = 8;
    vector<string> filename;
    filename.push_back("/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/mouse1_1img_n_r_po2_data_ImgFrom_space_md9_4_adev_PO2_August_30_2010_20100830_Place4_grid_Combined.dat");
    filename.push_back("/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/mouse2_1img_n_r_po2_data_ImgFrom_space_md9_4_adev_PO2_September_04_2010_20100904_Place1_grid_Combined.dat");
    filename.push_back("/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/mouse3_3img_n_r_po2_data_ImgFrom_space_md9_4_adev_PO2_September_07_2010_20100907_Place4_Combined.dat");
    filename.push_back("/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/mouse4_1img_n_r_po2_data_ImgFrom_space_md9_4_adev_PO2_September_07_2010_20100907_Place11_Combined.dat");
    filename.push_back("/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/mouse5_1img_n_r_po2_data_ImgFrom_space_md9_4_adev_PO2_September_07_2010_20100907_Place12_Combined.dat");
    filename.push_back("/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/mouse6_3img_n_r_po2_data_ImgFrom_space_md9_4_adev_PO2_September_07_2010_20100907_Place16_Combined.dat");
    filename.push_back("/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/mouse7_3img_n_r_po2_data_ImgFrom_space_md9_4_adev_PO2_September_08_2010_20100908_Place7_Combined.dat");
    filename.push_back("/home/martejulie/master_project/experimental_data/pO2_student_data/dat_files/mouse8_2img_n_r_po2_data_ImgFrom_space_md9_4_adev_PO2_September_08_2010_20100908_Place15_Combined.dat");

    for (int i = 0; i < N; i++) {
        Experiment myExp = Experiment(filename[i]);
        Fitsvd myFit = Fitsvd(&KroghModel_std3param::funcs, myExp.x, myExp.y, myExp.sigma);
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

    // 2 param
    /*
    ofstream outFile;
    outFile.open("031215_svd2param_fit_r_cap_3_r_t_120.dat", ios::out);

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
        Fitsvd myFit = Fitsvd(&KroghModel_std2param::funcs, myExp.x, myExp.y, myExp.sigma);
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
    */

    // 3 param
    /*
    ofstream outFile;
    outFile.open("031215_svd3param_fit_r_cap_3.dat", ios::out);

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
        Fitsvd myFit = Fitsvd(&KroghModel_std3param::funcs, myExp.x, myExp.y, myExp.sigma);
        myFit.fit();
        KroghModel_std3param::set_parameters(myFit.a);
        outFile << filename[i] << endl;
        outFile << "a0: " << myFit.a[0] << endl;
        outFile << "a1: " << myFit.a[1]<< endl;
        outFile << "a2: " << myFit.a[2]<< endl;
        //outFile << "r_cap: " << StandardKroghModel::r_cap << endl;
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

    cout << "Hello World!" << endl;
    return 0;
}

