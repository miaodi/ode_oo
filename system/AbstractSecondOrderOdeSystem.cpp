//
// Created by di miao on 12/18/16.
//

#include "AbstractSecondOrderOdeSystem.h"

AbstractSecondOrderOdeSystem::AbstractSecondOrderOdeSystem(unsigned int dof)
        : AbstractFirstOrderOdeSystem(dof) {
    _lM.resize(GetNumberOfStateVariables(), GetNumberOfStateVariables());
}

AbstractSecondOrderOdeSystem::~AbstractSecondOrderOdeSystem() {

}


void AbstractSecondOrderOdeSystem::SetInitialSpeed(const AbstractSecondOrderOdeSystem::VectorXd v) {
    _initialVelocity = v;
}

