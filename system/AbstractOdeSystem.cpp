//
// Created by di miao on 12/18/16.
//

#include "AbstractOdeSystem.h"

AbstractOdeSystem::AbstractOdeSystem(unsigned int dof):_numberOfStateVariables(dof)  {
}

AbstractOdeSystem::~AbstractOdeSystem() {
}

unsigned int AbstractOdeSystem::GetNumberOfStateVariables() const {
    return _numberOfStateVariables;
}

