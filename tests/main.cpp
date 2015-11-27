#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <experiment.h>
#include <fitsvd.h>
#include <standardkroghmodel.h>

double StandardKroghModel::r_cap = 1;
double StandardKroghModel::r_t = 100;

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
    SECTION("parameters") {
        string testfile = "271115_dataSetForTestingPurpose_r_t_100_a0_70_a1_0_001_N_33.dat";
        Experiment myExp = Experiment(testfile);
        Fitsvd myFit = Fitsvd(&StandardKroghModel::funcs, myExp.x, myExp.y, myExp.sigma); //&myfunc
        myFit.fit();
        double eps = 1e-10;
        double a0_below = (70.0-eps);
        double a0_above = (70.0+eps);
        REQUIRE(myFit.a[0] >= a0_below);
        REQUIRE(myFit.a[0] <= a0_above);
        //REQUIRE(myFit.a[1] == 0.001);
    }
}
