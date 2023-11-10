#include "OpenBoxSolver.h"

using real = double;

/// <summary>
/// Contructeur
/// </summary>
OpenBoxSolver::OpenBoxSolver():
	mOpenBoxProblem{OpenBoxProblem()}
{
	mProblemPresentation = mOpenBoxProblem.problemPresentation();
	DEDomain domain = DEDomain();
	domain.resize(1);
	domain.setAllIntervals(0, OpenBoxProblem::boxHeight());
	mParameters = DEParameters(domain, 100, 1, 0.35 ,500 , processCall, Fitness::identity);
}


/// <summary>
/// Fonction objective 
/// </summary>
/// <param name="solution">Solution à évaluer</param>
/// <returns>La valeur objective</returns>
double OpenBoxSolver::process(DESolution const& solution)
{
	return (OpenBoxProblem::boxHeight() - 2 * solution[0]) * (OpenBoxProblem::boxWidth() - 2 * solution[0]) * solution[0];
}
