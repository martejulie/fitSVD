#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <experiment.h>
#include <fitsvd.h>
#include <kroghmodel_std2param.h>
#include <kroghmodel_std3param.h>

double KroghModel_std2param::r_cap = 1;
double KroghModel_std2param::r_t = 100;
double KroghModel_std2param::p_cap;
double KroghModel_std2param::m;

double KroghModel_std3param::r_cap = 1;
double KroghModel_std3param::r_t;
double KroghModel_std3param::p_cap;
double KroghModel_std3param::m;

TEST_CASE( "MyExperiment", "[myexperiment]" ) {
    SECTION("Read Data") {        
        string testfile = "271115_dataSetForTestingPurpose_r_t_100_a0_70_a1_0_001_N_33.dat";
        Experiment my = Experiment(testfile);
        REQUIRE(my.countElements("1 2 3") == 3);
        REQUIRE(my.get_n("1") == 1);
        REQUIRE(my.get_n("1 2 3") == 0);
        REQUIRE(my.check_sigma("1 2") == false);
        REQUIRE(my.check_sigma("1 2 3") == true);
    }
}

TEST_CASE( "MyFit2param", "[myfit2param]" ) {
    SECTION("parameters: a") {
        string testfile = "271115_dataSetForTestingPurpose_r_t_100_a0_70_a1_0_001_N_33.dat";
        Experiment myExp = Experiment(testfile);
        Fitsvd myFit = Fitsvd(&KroghModel_std2param::funcs, myExp.x, myExp.y, myExp.sigma, 1e-12);
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
        Fitsvd myFit = Fitsvd(&KroghModel_std2param::funcs, myExp.x, myExp.y, myExp.sigma, 1-12);
        myFit.fit();
        KroghModel_std2param::set_parameters(myFit.a);
        double eps = 1e-10;
        double pcap_below = (70.0-eps);
        double pcap_above = (70.0+eps);
        double m_below = (0.004-eps);
        double m_above = (0.004+eps);
        REQUIRE(KroghModel_std2param::calculate_pcap(myFit.a[0], myFit.a[1]) >= pcap_below);
        REQUIRE(KroghModel_std2param::calculate_pcap(myFit.a[0], myFit.a[1]) <= pcap_above);
        REQUIRE(KroghModel_std2param::calculate_m(myFit.a[1]) >= m_below);
        REQUIRE(KroghModel_std2param::calculate_m(myFit.a[1]) <= m_above);
        REQUIRE(KroghModel_std2param::p_cap >= pcap_below);
        REQUIRE(KroghModel_std2param::p_cap <= pcap_above);
        REQUIRE(KroghModel_std2param::m >= m_below);
        REQUIRE(KroghModel_std2param::m <= m_above);
    }

    SECTION("chisq") {
        string testfile = "271115_dataSetForTestingPurpose_r_cap_1_r_t_100_pcap_70_m_0_004_N_33.dat";
        Experiment myExp = Experiment(testfile);
        Fitsvd myFit = Fitsvd(&KroghModel_std2param::funcs, myExp.x, myExp.y, myExp.sigma, 1e-12);
        myFit.fit();
        double eps = 1e-10;
        double chisq_below = (0.0-eps);
        double chisq_above = (0.0+eps);
        REQUIRE(myFit.chisq >= chisq_below);
        REQUIRE(myFit.chisq <= chisq_above);
    }
}

TEST_CASE( "MyFit3param", "[myfit3param]" ) {
    SECTION("parameters: m, p_cap and r_t") {
        string testfile = "031215_dataSetForTestingPurpose_r_cap_1_r_t_100_a0_69_999_a1_0_001_a2_minus20_N_33.dat";
        Experiment myExp = Experiment(testfile);
        Fitsvd myFit = Fitsvd(&KroghModel_std3param::funcs, myExp.x, myExp.y, myExp.sigma, 1e-12);
        myFit.fit();
        KroghModel_std3param::set_parameters(myFit.a);
        double eps = 1e-10;
        double pcap_below = (70.0-eps);
        double pcap_above = (70.0+eps);
        double m_below = (0.004-eps);
        double m_above = (0.004+eps);
        double rt_below = (100-eps);
        double rt_above = (100.0+eps);
        REQUIRE(KroghModel_std3param::calculate_pcap(myFit.a[0], myFit.a[1]) >= pcap_below);
        REQUIRE(KroghModel_std3param::calculate_pcap(myFit.a[0], myFit.a[1]) <= pcap_above);
        REQUIRE(KroghModel_std3param::calculate_m(myFit.a[1]) >= m_below);
        REQUIRE(KroghModel_std3param::calculate_m(myFit.a[1]) <= m_above);
        REQUIRE(KroghModel_std3param::calculate_rt(myFit.a[1], myFit.a[2]) >= rt_below);
        REQUIRE(KroghModel_std3param::calculate_rt(myFit.a[1], myFit.a[2]) <= rt_above);
        REQUIRE(KroghModel_std3param::p_cap >= pcap_below);
        REQUIRE(KroghModel_std3param::p_cap <= pcap_above);
        REQUIRE(KroghModel_std3param::m >= m_below);
        REQUIRE(KroghModel_std3param::m <= m_above);
        REQUIRE(KroghModel_std3param::r_t >= rt_below);
        REQUIRE(KroghModel_std3param::r_t <= rt_above);
    }

    SECTION("chisq") {
        string testfile = "031215_dataSetForTestingPurpose_r_cap_1_r_t_100_a0_69_999_a1_0_001_a2_minus20_N_33.dat";
        Experiment myExp = Experiment(testfile);
        Fitsvd myFit = Fitsvd(&KroghModel_std3param::funcs, myExp.x, myExp.y, myExp.sigma, 1e-12);
        myFit.fit();
        double eps = 1e-10;
        double chisq_below = (0.0-eps);
        double chisq_above = (0.0+eps);
        REQUIRE(myFit.chisq >= chisq_below);
        REQUIRE(myFit.chisq <= chisq_above);
    }
}
