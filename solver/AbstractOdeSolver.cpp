//
// Created by di miao on 12/18/16.
//

#include "AbstractOdeSolver.h"

AbstractOdeSolver::~AbstractOdeSolver() {

}

AbstractOdeSolver::AbstractOdeSolver(double sT, double eT, double tI) : _startTime(sT), _endTime(eT), _timeStep(tI) {
    _currentTime = _startTime;
}

double AbstractOdeSolver::GetStartTime() const {
    return _startTime;
}

double AbstractOdeSolver::GetCurrentTime() const {
    return _currentTime;
}

double AbstractOdeSolver::GetEndTime() const {
    return _endTime;
}


double AbstractOdeSolver::GetTimeStep() const {
    return _timeStep;
}

