# fitSVD
Modeling of Data by Use of Singular Value Decomposition (SVD)

Details of the code are given in Chapter 4 of
the Master's degree thesis "Estimation of oxygen consumption from partial pressure
gradients in cortex", by Marte Julie Sætra, May 2016.

## Code Example
You are given a set of experimental data points and want to study it by fitting it to a model of choice.
The model must be given on a form that is linear with respect to its unknowm parameters.

The model is defined by a set of basis functions and given in the `model` class. The basis functions could for
instance look like the following
``` cpp
Col<double> Model::funcs(double x) {
// basis functions
Col<double> f(3) ;
f[0] = 1.0;
f[1] = x ;
f[ 2 ] = x∗x ;
return f ;
}
```

The `Experiment` class takes the name of a datafile as argument, which may look at the following
```
414
2.502999 81.091224 1.262092
7.898756 72.514262 2.010258
   ...       ...      ...
```
First line contains the number of data points. The coloumns contains the value of x, y and measurment errors `sigma`,
respectively. You construct an `Experiment` object in `main.cpp`

When you have defined your model, and have a datafile with values of your data points, all you have to do
to solve the optimization problem is to construct a `Fitsvd` object in `main.cpp`. The constructor of `Fitsvd`
calls the relevant function, which is named `fit`. The construcor takes the model `funcs`, the experimental data
`x`, `y` and `sigma` and a theshold value `thresh` as arguments:
``` cpp
Fitsvd myFit = Fitsvd(&Model::funcs ,myExperiment.x, myExperiment.y ,myExperiment.sigma, thresh);
```

## Testing
[![Build Status](https://travis-ci.org/martejulie/fitSVD.svg)](https://travis-ci.org/martejulie/fitSVD)

