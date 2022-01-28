#include "ODEsolver.h"
#include <iostream>

namespace ODE{

// Constructor 
ODEsolver::ODEsolver(std::function<Eigen::VectorXd(double, Eigen::VectorXd)> function, Eigen::VectorXd y_0, double t_0, double t_n, double step)
{
    // Save passed parameters to class
    func_ = function; 
    step_ = step;
    t_0_ = t_0;
    t_n_ = t_n;
    step_ = step;
    step_size_ = ((t_n - t_0)/step);
    states_ = y_0.size();

    // Set up variables for our estimation
    Eigen::VectorXd k1;
    Eigen::VectorXd k2;
    Eigen::VectorXd k3;
    Eigen::VectorXd k4; 

    // Save the first state (initial conditions)
    solution_.resize(states_, step_);
    for(int j = 0; j<states_; j++)
    {
        solution_(j,0) = y_0(j);
    }

    // Time helper variable
    double t = t_0_;

    // Runge Kutta 4th order (https://en.wikipeia.org/wiki/Runge-Kutta_methods)
    for(int i = 0; i<step_-1; i++)
    {
        k1 = function(t, solution_.block(0, i, states_, 1));
        k2 = function((t+(step_size_/2.0)), ((solution_.block(0, i, states_, 1)) + step_size_*(k1/2.0)));
        k3 = function((t+(step_size_/2.0)), ((solution_.block(0, i, states_, 1)) + step_size_*(k2/2.0)));
        k4 = function((t+step_size_), ((solution_.block(0, i, states_, 1)) + step_size_*k3));
        solution_.block(0, i+1, states_, 1) = solution_.block(0, i, states_, 1) + (1.0/6.0)*step_size_*(k1 + 2.0*k2 + 2.0*k3 + k4);

        t += step_size_;
    }
}

// Plotter
void ODEsolver::plot()
{
    // Set up (converts Eigen::Matrix to std::vector)
    sciplot::Plot plot; 
    sciplot::Vec t = sciplot::linspace(t_0_, t_n_, step_);  // Vector of all time steps
    solution_vec_.resize(states_);                          // Size the solution vector
    for(int i = 0; i<solution_vec_.size(); i++)             // For loop loads all of the Eigen matrix into a standard matrix (not optimal, but needed for sciplot)
    {
        solution_vec_[i].resize(step_);
        for(int j = 0; j<step_; j++)
        {
            solution_vec_[i][j] = solution_(i,j);
        }
    }

    // Plot
    plot.xlabel("t");   
    plot.ylabel("y");
    plot.xrange(t_0_, t_n_);
    for(int i = 0; i<solution_vec_.size(); i++)             // Plots all of the states 
    {
        std::string name = "state";
        name.append(std::to_string(i));
        plot.drawCurve(t, solution_vec_[i]).label(name);
    }
    
    plot.show();

}
} // namespace ODE