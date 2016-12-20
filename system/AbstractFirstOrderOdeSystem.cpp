//
// Created by di miao on 12/19/16.
//

#include "AbstractFirstOrderOdeSystem.h"

AbstractFirstOrderOdeSystem::AbstractFirstOrderOdeSystem(unsigned int dof) : AbstractOdeSystem(dof){
    _rF.resize(GetNumberOfStateVariables(), 1);
    _lC.resize(GetNumberOfStateVariables(), GetNumberOfStateVariables());
    _lK.resize(GetNumberOfStateVariables(), GetNumberOfStateVariables());

}

AbstractFirstOrderOdeSystem::~AbstractFirstOrderOdeSystem() {

}

void AbstractFirstOrderOdeSystem::SetInitialDisplacement(const AbstractFirstOrderOdeSystem::VectorXd &d) {
    //Need to add assert
    _initialDisplacement = d;
}
