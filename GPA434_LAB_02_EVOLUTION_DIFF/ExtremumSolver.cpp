#include "ExtremumSolver.h"

/// <summary>
/// Contructeur
/// </summary>
ExtremumSolver::ExtremumSolver() :
	mExtremumFunctionProblem{ ExtremumFunctionProblem() }
{
	mProblemPresentation = mExtremumFunctionProblem.problemPresentation();
	DEDomain domain = DEDomain();
	domain.resize(4);
	domain.setAllIntervals(-3, 3);
	mParameters = DEParameters(domain, 2000, 0.5, 0.30, 500, processCall, Fitness::identity);
}

/// <summary>
/// Fonction objective 
/// </summary>
/// <param name="solution">Solution à évaluer</param>
/// <returns>La valeur objective</returns>
real ExtremumSolver::process(DESolution const& solution)
{
	return abs(mExtremumFunctionProblem.peak(solution[0],solution[1]) - mExtremumFunctionProblem.peak(solution[2], solution[3]));
}
