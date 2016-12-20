//
// Created by miaodi on 19/12/2016.
//

#include "GeneralizedTrapezoidalSolver.h"

GeneralizedTrapezoidalSolver::GeneralizedTrapezoidalSolver(double sT, double eT, double tI, double a)
        : AbstractOdeSolver(sT, eT, tI), alpha(a) {
}

void GeneralizedTrapezoidalSolver::SolveByOneStep(AbstractFirstOrderOdeSystem &OdeSystem, Solution &solution) {

}

void GeneralizedTrapezoidalSolver::Initialize(AbstractFirstOrderOdeSystem &OdeSystem, Solution &solution) {
    OdeSystem.EvaluateF(GetStartTime(),*OdeSystem.GetInitialDisplacement());
    OdeSystem.EvaluateC(GetStartTime(),*OdeSystem.GetInitialDisplacement());
    OdeSystem.EvaluateK(GetStartTime(),*OdeSystem.GetInitialDisplacement());
    const SpMat *M=OdeSystem.GetDampingMatrix();
    const SpMat *K=OdeSystem.GetStiffnessMatrix();
    Eigen::ConjugateGradient<SpMat, Eigen::Lower|Eigen::Upper> cg;
    cg.compute(*M);
    VectorXd v0 = cg.solve(*OdeSystem.GetLoadVector()-*K*(*OdeSystem.GetInitialDisplacement()));
}
