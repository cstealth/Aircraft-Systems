#include<iostream>
#include<Eigen/Dense>

#include "ODEsolver.h"

Eigen::VectorXd ode(double t, Eigen::VectorXd y)
{
    Eigen::VectorXd c(1);
    c(0) = 1;
    return y+c*t;
}
int main()
{
    Eigen::VectorXd s(1);
    s(0) = 1;
    ODE::ODEsolver test(ode, s, 0.0, 10.0, 100.0);
    test.plot();
}