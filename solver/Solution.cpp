//
// Created by miaodi on 19/12/2016.
//

#include "Solution.h"

Solution::Solution() : _NumberOfTimeSteps(0u) {

}

unsigned int Solution::GetNumberOfSteps() const {
    return _NumberOfTimeSteps;
}

Solution::VectorXd Solution::GetDisplacement(unsigned n) const {
    if (n < _NumberOfTimeSteps) {
        return _Displacements[n];
    } else {
        std::cout << "Out of range." << std::endl;
        exit(1);
    }
}

Solution::VectorXd Solution::GetVelocity(unsigned n) const {
    if (n < _NumberOfTimeSteps) {
        return _Velocities[n];
    } else {
        std::cout << "Out of range." << std::endl;
        exit(1);
    }
}

double Solution::GetTime(unsigned n) const {
    if (n < _NumberOfTimeSteps) {
        return _Times[n];
    } else {
        std::cout << "Out of range." << std::endl;
        exit(1);
    }
}

Solution::VectorXd Solution::GetAcceleration(unsigned n) const {
    if (_Accelerations.size() != _NumberOfTimeSteps) {
        std::cout << "No acceleration recorded" << std::endl;
        exit(2);
    } else {
        if (n < _NumberOfTimeSteps) {
            return _Accelerations[n];
        } else {
            std::cout << "Out of range." << std::endl;
            exit(1);
        }
    }
}

void Solution::SetTime(double t) {
    _Times.push_back(t);
    _NumberOfTimeSteps++;
}

void Solution::SetDisplacements(const Solution::VectorXd &d) {
    _Displacements.push_back(d);
}

void Solution::SetVelocities(const Solution::VectorXd &v) {
    _Velocities.push_back(v);
}

void Solution::SetAccelerations(const Solution::VectorXd &a) {
    _Accelerations.push_back(a);
}

const std::vector<Solution::VectorXd>& Solution::GetVelocities() const {
    return _Velocities;
}

const std::vector<Solution::VectorXd>& Solution::GetDisplacements() const {
    return _Displacements;
}

std::vector<double> Solution::GetTimes() const {
    return _Times;
}
