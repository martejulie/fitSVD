#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <experiment.h>
#include <fitsvd.h>
#include <standardkroghmodel.h>

double StandardKroghModel::r_cap = 1;
double StandardKroghModel::r_t = 100;
double StandardKroghModel::p_cap;
double StandardKroghModel::m;

TEST_CASE( "MyExperiment", "[myexperiment]" ) {
    SECTION("Read Data") {
        string testfile = "121115_dataSetForTestingPurpose_r_cap_1_rt_150_p_cap_70_M_0_0011_149.dat";
        Experiment my = Experiment(testfile);
        REQUIRE(my.countElements("1 2 3") == 3);
        REQUIRE(my.get_n("1") == 1);
        REQUIRE(my.get_n("1 2 3") == 0);
        REQUIRE(my.check_sigma("1 2") == false);
        REQUIRE(my.check_sigma("1 2 3") == true);
    }
}

TEST_CASE( "MyFit", "[myfit]" ) {
    SECTION("parameters: a") {
        string testfile = "271115_dataSetForTestingPurpose_r_t_100_a0_70_a1_0_001_N_33.dat";
        Experiment myExp = Experiment(testfile);
        Fitsvd myFit = Fitsvd(&StandardKroghModel::funcs, myExp.x, myExp.y, myExp.sigma); //&myfunc
        myFit.fit();
        double eps = 1e-10;
        double a0_below = (70.0-eps);
        double a0_above = (70.0+eps);
        double a1_below = (0.001-eps);
        double a1_above = (0.001+eps);
        REQUIRE(myFit.a[0] >= a0_below);
        REQUIRE(myFit.a[0] <= a0_above);
        REQUIRE(myFit.a[1] >= a1_below);
        REQUIRE(myFit.a[1] <= a1_above);
    }

    SECTION("parameters: m and p_cap") {
        string testfile = "271115_dataSetForTestingPurpose_r_cap_1_r_t_100_pcap_70_m_0_004_N_33.dat";
        Experiment myExp = Experiment(testfile);
        Fitsvd myFit = Fitsvd(&StandardKroghModel::funcs, myExp.x, myExp.y, myExp.sigma); //&myfunc
        myFit.fit();
        StandardKroghModel::set_parameters(myFit.a);
        double eps = 1e-10;
        double pcap_below = (70.0-eps);
        double pcap_above = (70.0+eps);
        double m_below = (0.004-eps);
        double m_above = (0.004+eps);
        REQUIRE(StandardKroghModel::calculate_pcap(myFit.a[0], myFit.a[1]) >= pcap_below);
        REQUIRE(StandardKroghModel::calculate_pcap(myFit.a[0], myFit.a[1]) <= pcap_above);
        REQUIRE(StandardKroghModel::calculate_m(myFit.a[1]) >= m_below);
        REQUIRE(StandardKroghModel::calculate_m(myFit.a[1]) <= m_above);
        REQUIRE(StandardKroghModel::p_cap >= pcap_below);
        REQUIRE(StandardKroghModel::p_cap <= pcap_above);
        REQUIRE(StandardKroghModel::m >= m_below);
        REQUIRE(StandardKroghModel::m <= m_above);
    }

    SECTION("chisq") {
        string testfile = "271115_dataSetForTestingPurpose_r_cap_1_r_t_100_pcap_70_m_0_004_N_33.dat";
        Experiment myExp = Experiment(testfile);
        Fitsvd myFit = Fitsvd(&StandardKroghModel::funcs, myExp.x, myExp.y, myExp.sigma); //&myfunc
        myFit.fit();
        double eps = 1e-10;
        double chisq_below = (0.0-eps);
        double chisq_above = (0.0+eps);
        REQUIRE(myFit.chisq >= chisq_below);
        REQUIRE(myFit.chisq <= chisq_above);
    }
}
