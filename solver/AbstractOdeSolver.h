//
// Created by di miao on 12/18/16.
//

#ifndef ODE_OO_ABSTRACTODESOLVER_H
#define ODE_OO_ABSTRACTODESOLVER_H

#include "../system/AbstractOdeSystem.h"
#include "Solution.h"

class AbstractOdeSolver {
public:
    AbstractOdeSolver(double sT = 0, double eT = 0, double tI = .1);

    virtual ~AbstractOdeSolver();

    double GetStartTime() const;

    double GetCurrentTime() const;

    double GetEndTime() const;

    double GetTimeStep() const;


protected:
    double _startTime;
    double _endTime;
    double _currentTime;
    double _timeStep;


};


#endif //ODE_OO_ABSTRACTODESOLVER_H
