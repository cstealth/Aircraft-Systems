#ifndef TRANSFORMS_H
#define TRANSFORMS_H

#include <cmath>
#include <Eigen/Dense>
#define PI 3.14159

namespace transforms{

/* Transforms from the wind to body axis */
Eigen::Vector3d Twb(Eigen::Vector3d wind, Eigen::Vector3d angles)
{
    double alpha = angles(0) * (PI/180.0);
    double beta = angles(1) * (PI/180.0);
    double phi = angles(2) * (PI/180.0);

    Eigen::Matrix3d transform{{std::cos(alpha) * std::cos(beta), -1*std::cos(alpha)*std::sin(beta), -1*std::sin(alpha)},{std::sin(alpha)*std::sin(phi)*std::cos(beta)+std::sin(beta)*std::cos(phi), -1*std::sin(beta)*std::sin(alpha)*std::sin(phi)+std::cos(beta)*std::cos(phi), std::sin(phi)*std::cos(alpha)},{std::sin(alpha)*std::cos(phi)*std::cos(beta)-std::sin(beta)*std::sin(phi), -1*std::sin(beta)*std::sin(alpha)*std::cos(phi)-std::cos(beta)*std::sin(phi), std::cos(phi)*std::cos(alpha)}};
    
    return transform*wind;
}

/* Transforms from the wind to body axis */
Eigen::Vector3d Tbw(Eigen::Vector3d body, Eigen::Vector3d angles)
{
    double alpha = angles(0) * (PI/180.0);
    double beta = angles(1) * (PI/180.0);
    double phi = angles(2) * (PI/180.0);

    Eigen::Matrix3d transform{{std::cos(alpha) * std::cos(beta), -1*std::cos(alpha)*std::sin(beta), -1*std::sin(alpha)},{std::sin(alpha)*std::sin(phi)*std::cos(beta)+std::sin(beta)*std::cos(phi), -1*std::sin(beta)*std::sin(alpha)*std::sin(phi)+std::cos(beta)*std::cos(phi), std::sin(phi)*std::cos(alpha)},{std::sin(alpha)*std::cos(phi)*std::cos(beta)-std::sin(beta)*std::sin(phi), -1*std::sin(beta)*std::sin(alpha)*std::cos(phi)-std::cos(beta)*std::sin(phi), std::cos(phi)*std::cos(alpha)}};
    
    return transform.transpose()*body;

}


} // namespace transforms
#endif // TRANSFORMS_H