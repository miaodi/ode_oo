//
// Created by miaodi on 19/12/2016.
//

#ifndef ODE_OO_SOLUTION_H
#define ODE_OO_SOLUTION_H

#include <vector>
#include <iostream>
#include "eigen3/Eigen/Dense"

class Solution {
    typedef Eigen::Matrix<double, Eigen::Dynamic, 1> VectorXd;
public:
    Solution();

    unsigned int GetNumberOfSteps() const;

    double GetTime(unsigned n) const;

    VectorXd GetDisplacement(unsigned n) const;

    VectorXd GetVelocity(unsigned n) const;

    VectorXd GetAcceleration(unsigned n) const;

    const std::vector<VectorXd> &GetVelocities() const;

    const std::vector<VectorXd> &GetDisplacements() const;

    std::vector<double> GetTimes() const;

    void SetTime(double t);

    void SetDisplacements(const VectorXd &d);

    void SetVelocities(const VectorXd &v);

    void SetAccelerations(const VectorXd &a);

private:
    unsigned _NumberOfTimeSteps;
    std::vector<double> _Times;
    std::vector<VectorXd> _Displacements;
    std::vector<VectorXd> _Velocities;
    std::vector<VectorXd> _Accelerations;
};


#endif //ODE_OO_SOLUTION_H
