//
// Created by miaodi on 19/12/2016.
//

#include "GeneralizedTrapezoidalSolver.h"

GeneralizedTrapezoidalSolver::GeneralizedTrapezoidalSolver(double sT, double eT, double tI, double a)
        : AbstractOdeSolver(sT, eT, tI), _alpha(a), _firstTimeCall(true) {
}


void GeneralizedTrapezoidalSolver::Initialize(AbstractFirstOrderOdeSystem &OdeSystem, Solution &solution) {
    OdeSystem.EvaluateF(GetStartTime(), *OdeSystem.GetInitialDisplacement());
    OdeSystem.EvaluateC(GetStartTime(), *OdeSystem.GetInitialDisplacement());
    OdeSystem.EvaluateK(GetStartTime(), *OdeSystem.GetInitialDisplacement());
    const SpMat &M = *OdeSystem.GetDampingMatrix();
    const SpMat &K = *OdeSystem.GetStiffnessMatrix();
    const VectorXd &F = *OdeSystem.GetLoadVector();
    const VectorXd &d = *OdeSystem.GetInitialDisplacement();
    Eigen::ConjugateGradient<SpMat, Eigen::Lower | Eigen::Upper> cg;
    cg.compute(M);
    const VectorXd v0 = cg.solve(F - K * d);
    solution.SetTime(GetStartTime());
    solution.SetDisplacements(d);
    solution.SetVelocities(v0);
    VectorXd c=solution.GetDisplacement(0);

}

void GeneralizedTrapezoidalSolver::SolveByOneStep(AbstractFirstOrderOdeSystem &OdeSystem, Solution &solution) {
    if (_firstTimeCall == true) {
        _firstTimeCall = false;
    } else {
        OdeSystem.EvaluateF(GetStartTime(), *OdeSystem.GetInitialDisplacement());
        OdeSystem.EvaluateC(GetStartTime(), *OdeSystem.GetInitialDisplacement());
        OdeSystem.EvaluateK(GetStartTime(), *OdeSystem.GetInitialDisplacement());
    }
    const SpMat &M = *OdeSystem.GetDampingMatrix();
    const SpMat &K = *OdeSystem.GetStiffnessMatrix();
    const VectorXd &F = *OdeSystem.GetLoadVector();
    const VectorXd &d = solution.GetDisplacements().back();

    double t_current = solution.GetTimes().back();

    const Eigen::Vector2d d_pred = d + (1 - _alpha) * GetTimeStep() * solution.GetVelocities().back();
    Eigen::ConjugateGradient<SpMat, Eigen::Lower | Eigen::Upper> cg;
    cg.compute(M + _alpha * GetTimeStep() * K);
    const Eigen::Vector2d v_next = cg.solve(F - K * d_pred);
    const Eigen::Vector2d d_next = d_pred + _alpha * GetTimeStep() * v_next;
    _currentTime = t_current + GetTimeStep();
    solution.SetTime(_currentTime);
    solution.SetDisplacements(d_next);
    solution.SetVelocities(v_next);

}

void GeneralizedTrapezoidalSolver::Solve(AbstractFirstOrderOdeSystem &OdeSystem, Solution &solution) {
    while (_currentTime < _endTime)
        SolveByOneStep(OdeSystem, solution);
}
