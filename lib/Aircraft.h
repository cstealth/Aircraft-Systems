#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include<Eigen/Dense>

class Aircraft
{
public:
    Eigen::Vector3d current_Pos;
    Eigen::Vector3d current_Rot;

    void rotate(Eigen::Vector3d);
};

#endif