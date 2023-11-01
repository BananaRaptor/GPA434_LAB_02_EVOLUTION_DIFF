#include "OpenBoxSolver.h"

using real = double;

OpenBoxSolver::OpenBoxSolver():
	mOpenBoxProblem{OpenBoxProblem()}
{
	mProblemPresentation = mOpenBoxProblem.problemPresentation();
	DEDomain domain = DEDomain();
	domain.resize(1);
	domain.setAllIntervals(0, OpenBoxProblem::boxHeight());
	mParameters = DEParameters(domain, 100, 1, 0.40 ,500 , processCall, Fitness::identity);
}


double OpenBoxSolver::process(DESolution const& solution)
{
	return (OpenBoxProblem::boxHeight() - 2 * solution[0]) * (OpenBoxProblem::boxWidth() - 2 * solution[0]) * solution[0];
}
