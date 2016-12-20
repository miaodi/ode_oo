#include <iostream>
#include "solver/Solution.h"
#include "solver/GeneralizedTrapezoidalSolver.h"
#include "system/AbstractFirstOrderOdeSystem.h"
using namespace Eigen;
using namespace std;
typedef Triplet<double> T;

class systemforsolve:public AbstractFirstOrderOdeSystem{
public:

    systemforsolve(unsigned int dof);
    ~systemforsolve();
    virtual void EvaluateC(double t, const VectorXd &d);
    virtual void EvaluateK(double t, const VectorXd &d);
    virtual void EvaluateF(double t, const VectorXd &d);

};

systemforsolve::systemforsolve(unsigned int dof) : AbstractFirstOrderOdeSystem(dof) {

}

systemforsolve::~systemforsolve() {

}

void systemforsolve::EvaluateC(double t, const VectorXd &d) {
    std::vector<T> tripletList;
    tripletList.push_back(T(0,0,1));
    tripletList.push_back(T(1,1,1));
    _lC.setFromTriplets(tripletList.begin(),tripletList.end());
}

void systemforsolve::EvaluateK(double t, const VectorXd &d) {
    std::vector<T> tripletList;
    tripletList.push_back(T(1,0,-3));
    tripletList.push_back(T(1,1,1));
    tripletList.push_back(T(0,0,-4));
    tripletList.push_back(T(0,1,2));
    _lK.setFromTriplets(tripletList.begin(),tripletList.end());
}

void systemforsolve::EvaluateF(double t, const VectorXd &d) {
    _rF<<0,0;
}

int main() {

    systemforsolve sys(2);
    VectorXd initiald(2);
    initiald<<1,2;
    sys.SetInitialDisplacement(initiald);
    sys.EvaluateK(0,initiald);

    Solution sol;
    GeneralizedTrapezoidalSolver Trapezoidal(0.0,1.0,.0001,0);
    Trapezoidal.Initialize(sys,sol);
    Trapezoidal.Solve(sys,sol);

    return 0;
}