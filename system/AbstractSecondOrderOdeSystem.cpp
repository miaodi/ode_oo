//
// Created by di miao on 12/18/16.
//

#include "AbstractSecondOrderOdeSystem.h"

AbstractSecondOrderOdeSystem::AbstractSecondOrderOdeSystem(unsigned int dof)
        : AbstractOdeSystem(dof) {
    _rF.resize(GetNumberOfStateVariables(), 1);
    _lM.resize(GetNumberOfStateVariables(), GetNumberOfStateVariables());
    _lC.resize(GetNumberOfStateVariables(), GetNumberOfStateVariables());
    _lK.resize(GetNumberOfStateVariables(), GetNumberOfStateVariables());
}

AbstractSecondOrderOdeSystem::~AbstractSecondOrderOdeSystem() {

}

void AbstractSecondOrderOdeSystem::SetInitialDisplacement(const AbstractSecondOrderOdeSystem::VectorXd d) {
    //Need to add assert
    _initialDisplacement = d;
}

void AbstractSecondOrderOdeSystem::SetInitialSpeed(const AbstractSecondOrderOdeSystem::VectorXd v) {
    _initialVelocity = v;
}

