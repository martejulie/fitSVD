#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include <iostream>
#include <armadillo>
#include <string>
#include <sstream>

using namespace std;
using namespace arma;

class Experiment {
    // Object for reading experimental data from file
    // and write them to arrays.
    // All you need to do is to call the constructor.
    //
    // Args:
    //  filename (string)
    //
    // ****
    // The first line in filename have to contain the number of datapoints.
    // The rest of the file must be organized in two (three) columns,
    // representing x, y and (sigma) respectively.

public:
    int n;              // number of datapoints
    Col<double> x;      // array for storing x-values
    Col<double> y;      // array for storing y-values
    Col<double> sigma;  // array for storing standard error

    int countElements(string line);
    int get_n(string line);
    void set_sizes(int n);
    bool check_sigma(string line);
    void read_file(string filename);


    Experiment();
    Experiment(string);
};

#endif // EXPERIMENT_H
