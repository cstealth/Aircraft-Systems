#include "ODEsolver.h"

namespace ODE{

// Constructor 
ODEsolver::ODEsolver(std::function<Eigen::VectorXd(Eigen::VectorXd)> function, double y_0, double t_0, double t_n, double step)
{

    func_ = function; 
    step_ = step;
    t_0_ = t_0;
    t_n_ = t_n;
    step_ = step;

    // Runga Kuta Here 


}

} // namespace ODE