#include "ExtremumSolver.h"

ExtremumSolver::ExtremumSolver() :
	mExtremumFunctionProblem{ ExtremumFunctionProblem() }
{
	mProblemPresentation = mExtremumFunctionProblem.problemPresentation();
	DEDomain domain = DEDomain();
	domain.resize(2);
	domain.setAllIntervals(-3, 3);
	mParameters = DEParameters(domain, 2750, 1, 0.45, 500, processCall, Fitness::distance);
}

real ExtremumSolver::process(DESolution const& solution)
{
	return mExtremumFunctionProblem.peak(solution[0],solution[1]);
}
