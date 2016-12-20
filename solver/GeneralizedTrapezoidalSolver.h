//
// Created by miaodi on 19/12/2016.
//

#ifndef ODE_OO_GENERALIZEDTRAPEZOIDALSOLVER_H
#define ODE_OO_GENERALIZEDTRAPEZOIDALSOLVER_H

#include "AbstractOdeSolver.h"
#include "Solution.h"
#include "../system/AbstractFirstOrderOdeSystem.h"

class GeneralizedTrapezoidalSolver : public AbstractOdeSolver {
public:
    typedef Eigen::Matrix<double, Eigen::Dynamic, 1> VectorXd;
    typedef Eigen::SparseMatrix<double> SpMat;

    GeneralizedTrapezoidalSolver(double sT = 0, double eT = 0, double tI = .1, double a = 0);

    void Initialize(AbstractFirstOrderOdeSystem &OdeSystem, Solution &solution);

    virtual void SolveByOneStep(AbstractFirstOrderOdeSystem &OdeSystem, Solution &solution);
    virtual void Solve(AbstractFirstOrderOdeSystem &OdeSystem, Solution &solution);


private:
    double _alpha;
    bool _firstTimeCall;

};


#endif //ODE_OO_GENERALIZEDTRAPEZOIDALSOLVER_H
