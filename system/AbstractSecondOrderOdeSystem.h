//
// Created by di miao on 12/18/16.
//

#ifndef ODE_OO_ABSTRACTSECONDORDERODESYSTEM_H
#define ODE_OO_ABSTRACTSECONDORDERODESYSTEM_H

#include "AbstractOdeSystem.h"
#include "eigen3/Eigen/Sparse"
#include "eigen3/Eigen/Dense"

class AbstractSecondOrderOdeSystem : public AbstractOdeSystem {
    typedef Eigen::Matrix<double, Eigen::Dynamic, 1> VectorXd;
    typedef Eigen::SparseMatrix<double> SpMat;
public:
    AbstractSecondOrderOdeSystem(unsigned int dof);

    virtual ~AbstractSecondOrderOdeSystem();

    virtual void EvaluateF(double time, const VectorXd &d, const VectorXd &v, const VectorXd &a)=0;

    virtual void EvaluateM(double time, const VectorXd &d, const VectorXd &v, const VectorXd &a)=0;

    virtual void EvaluateC(double time, const VectorXd &d, const VectorXd &v, const VectorXd &a)=0;

    virtual void EvaluateK(double time, const VectorXd &d, const VectorXd &v, const VectorXd &a)=0;

    void SetInitialDisplacement(const VectorXd d);

    void SetInitialSpeed(const VectorXd v);

    virtual const VectorXd* const GetLoadVector() const=0;
    virtual const VectorXd* const GetMassMatrix() const=0;
    virtual const VectorXd* const GetDampingMatrix() const=0;
    virtual const VectorXd* const GetStiffnessMatrix() const=0;


private:
    VectorXd _rF;
    SpMat _lM;
    SpMat _lC;
    SpMat _lK;

    VectorXd _initialDisplacement;
    VectorXd _initialVelocity;


};


#endif //ODE_OO_ABSTRACTSECONDORDERODESYSTEM_H
