//
// Created by di miao on 12/18/16.
//

#ifndef ODE_OO_ABSTRACTSECONDORDERODESYSTEM_H
#define ODE_OO_ABSTRACTSECONDORDERODESYSTEM_H

#include "AbstractFirstOrderOdeSystem.h"


class AbstractSecondOrderOdeSystem : public AbstractFirstOrderOdeSystem {
    typedef Eigen::Matrix<double, Eigen::Dynamic, 1> VectorXd;
    typedef Eigen::SparseMatrix<double> SpMat;
public:
    AbstractSecondOrderOdeSystem(unsigned int dof);

    virtual ~AbstractSecondOrderOdeSystem();

    virtual void EvaluateF(double time, const VectorXd &d, const VectorXd &v)=0;

    virtual void EvaluateM(double time, const VectorXd &d, const VectorXd &v)=0;

    virtual void EvaluateC(double time, const VectorXd &d, const VectorXd &v)=0;

    virtual void EvaluateK(double time, const VectorXd &d, const VectorXd &v)=0;

    void SetInitialSpeed(const VectorXd v);

    const SpMat *const GetMassMatrix() const { return &_lM; }


private:
    SpMat _lM;
    VectorXd _initialVelocity;
};




#endif //ODE_OO_ABSTRACTSECONDORDERODESYSTEM_H
