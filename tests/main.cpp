#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <experiment.h>

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

//TEST_CASE( "Random", "[random]" ) {
//    SECTION("trollo") {
//        REQUIRE(2 == 2);
//    }
//}
