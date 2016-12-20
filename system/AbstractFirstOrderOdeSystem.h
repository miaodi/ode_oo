//
// Created by di miao on 12/19/16.
//

#ifndef ODE_OO_ABSTRACTFIRSTORDERODESYSTEM_H
#define ODE_OO_ABSTRACTFIRSTORDERODESYSTEM_H

#include "AbstractOdeSystem.h"
#include "eigen3/Eigen/Sparse"
#include "eigen3/Eigen/Dense"

class AbstractFirstOrderOdeSystem : public AbstractOdeSystem {
    typedef Eigen::Matrix<double, Eigen::Dynamic, 1> VectorXd;
    typedef Eigen::SparseMatrix<double> SpMat;
public:
    AbstractFirstOrderOdeSystem(unsigned int dof);

    virtual ~AbstractFirstOrderOdeSystem();

    virtual void EvaluateC(double time, const VectorXd &d)=0;

    virtual void EvaluateK(double time, const VectorXd &d)=0;

    virtual void EvaluateF(double time, const VectorXd &d)=0;

    void SetInitialDisplacement(const VectorXd &d);

    const SpMat *const GetDampingMatrix() { return &_lC; }

    const SpMat *const GetStiffnessMatrix() const { return &_lK; }

    const VectorXd *const GetLoadVector() const { return &_rF; }

    const VectorXd *const GetInitialDisplacement() const { return &_initialDisplacement; }

private:
    VectorXd _rF;
    SpMat _lC;
    SpMat _lK;

    VectorXd _initialDisplacement;

};


#endif //ODE_OO_ABSTRACTFIRSTORDERODESYSTEM_H
