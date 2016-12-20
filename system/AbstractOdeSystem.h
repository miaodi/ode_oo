//
// Created by di miao on 12/18/16.
//

#ifndef ODE_OO_ABSTRACTODESYSTEM_H
#define ODE_OO_ABSTRACTODESYSTEM_H


class AbstractOdeSystem {
public:
    AbstractOdeSystem(unsigned int dof=0);

    virtual ~AbstractOdeSystem();
    unsigned int GetNumberOfStateVariables() const;

protected:
    unsigned int _numberOfStateVariables;
};


#endif //ODE_OO_ABSTRACTODESYSTEM_H
