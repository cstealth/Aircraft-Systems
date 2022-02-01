#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <iostream>
#include <fstream>

#include <Eigen/Dense>

#define GET_VARIABLE_NAME(Variable) (#Variable)

namespace help
{

template <typename T>
void writeToFile(T data, std::string file_name)
{
    std::ofstream File;
    if(file_name.find("csv") != std::string::npos)
        File.open(file_name);
    else
        File.open((file_name + ".csv"));
    for(int i = 0; i<data.rows(); i++)
    {
        for(int j = 0; j<data.cols(); j++)
        {
            File << data(i,j);
            File << ',' ;
        }
        File << "\n";
    }
}

template <typename Y>
void writeToFile(Y data)
{
    std::ofstream File;
    std::string file_name = GET_VARIABLE_NAME(data);
    file_name += ".csv";
    File.open(file_name);
    for(int i = 0; i<data.rows(); i++)
    {
        for(int j = 0; j<data.cols(); j++)
        {
            File << data(i,j);
            File << ',' ;
        }
        File << "\n";
    }
}

} // namespace help

#endif // HELPERS_H