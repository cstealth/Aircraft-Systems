#include "Aircraft.h"
#include <Eigen/Dense>
#include <math.h>

/**
 * @brief This function rotates the aircrafts coordinate system by the given Euler Angles. 
 * @param euler_Angles A 3 element column vector of the rotation angles: [Psi, Theta, Phi]
 * 
 */
void Aircraft::rotate(Eigen::Vector3d euler_Angles)
{
    Eigen::Matrix<double, 3, 3> rotation {{cos()},{},{}};
}