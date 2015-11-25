#include "experiment.h"

Experiment::Experiment(string filename) {
    this->read_file(filename);
}

int Experiment::countElements(string line) {
    /*
     * Args:
     *  line (string)
     *
     * Returns:
     *  iElements (int): number of words in line
    */
    int iSpaces = 0;
    for (unsigned int i = 0; i < line.length(); i++) {
        if (line[i] == ' ') {
            iSpaces++;
        }
    }
    int iElements = iSpaces+1;
    return iElements;
}

int Experiment::get_n(string line) {
    /*
     * Args:
     *  line (string)
     *
     * Returns:
     *  0 (int) if 'line' contains more than one element
     *  this->n = line if 'line' contains one element only
    */
    stringstream n_stream;
    n_stream << line;
    int elem = 0;
    while (n_stream >> this->n) {
        elem += 1;
    }
    if (elem > 1) {
        return 0;
    }
    else {
        return this->n;
    }
}

void Experiment::set_size(int n) {
    this->x.resize(n);
    this->y.resize(n);
    this->sigma.resize(n);
}

bool Experiment::check_sigma(string line) {
    cout << "hello world" << endl;
    return false;
}

void Experiment::read_file(string filename) {
    /* Read data from file and write it to arrays.
     * Args:
     *  filename (string)
     *
     * Sets:
     *  n (int)
     *  x (Col<double>)
     *  y (Col<double>)
     *  sigma (Col<double>)
    */
    string line;
    ifstream infile;
    infile.open(filename.c_str());

    getline(infile, line);
    int N = this->get_n(line);
    if (N == 0) {
        cout << "The first line in your input file must contain \n the number of experimental data points, n." << endl;
        exit(1);
    }

    set_size(this->n);

    getline(infile, line);
    bool boolSigma = check_sigma(line);

    /*
    // r, p, sigma
    getline(infile, line);
    stringstream stream;
    stream << line;
    bool sigma;
    if (this->countElements(line) == 2)
    {
        cout << "Sigma is set to 1.0." << endl << endl;
        sigma = false;
        stream >> this->rr[0];
        stream >> this->pp[0];
        this->ssig[0] = 1.0;
    }
    else {
        cout << "Sigma is read from file." << endl << endl;
        sigma = true;
        stream >> this->rr[0];
        stream >> this->pp[0];
        stream >> this->ssig[0];
    }

    if (sigma) {
        for (int i = 1; i < this->n; i++) {
            infile >> this->rr[i];
            infile >> this->pp[i];
            infile >> this->ssig[i];
        }
    }
    else {
        for (int i = 1; i < this->n; i++) {
            infile >> this->rr[i];
            infile >> this->pp[i];
            this->ssig[i] = 1.0;
        }
    }
    */
    infile.close();
}





