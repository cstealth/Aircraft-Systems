#ifndef ODESOLVER_H
#define ODESOLVER_H

#include <functional>
#include <cmath>
#include <stdexcept>

#include <Eigen/Dense>

namespace ODE {

class ODEsolver
{
public:
    ODEsolver(std::function<Eigen::VectorXd(Eigen::VectorXd)> function, double y_0, double t_0, double t_n, double step); // Constructor (does most of the work)
    Eigen::MatrixXd operator () (double t) // Operator overload, returns the state at a specified time
    {
        if(std::trunc(((t - t_0_)/step_)) == ((t - t_0_)/step_)) // If this gives an integer, the time state exists (as in, we have it saved), else, we will interpolate (not yet implemented)
            return solution_.block(0, ((t - t_0_)/step_), states_, 1);
        else
            throw std::runtime_error("Time index does not exis, Interpolation is comming");
    } 

protected:
    std::function<Eigen::VectorXd(Eigen::VectorXd)> func_; // The function being integrated
    Eigen::MatrixXd solution_; // The returned solution
    int states_; // The amount of states
    double t_0_; // Starting time
    double t_n_; // Ending time
    double step_; // Time step
};

} // namespace ODE
#endif // ODE_H