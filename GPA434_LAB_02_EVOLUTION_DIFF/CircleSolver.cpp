#include "CircleSolver.h"

/// <summary>
/// Contructeur
/// </summary>
CircleSolver::CircleSolver():
	mCircleProblem{CircleFittingProblem()}
{
	mProblemPresentation = mCircleProblem.problemPresentation();
	DEDomain domain = DEDomain();
	domain.resize(3);
	domain.setAllIntervals(2, 8);
	mParameters = DEParameters(domain, 1000, 1, 0.20, 500, processCall, Fitness::inverse);
}

/// <summary>
/// Fonction objective 
/// </summary>
/// <param name="solution">Solution à évaluer</param>
/// <returns>La valeur objective</returns>
real CircleSolver::process(DESolution const& solution)
{
	real totalDistance = 0;
	for (std::array<double, 2> point : mCircleProblem.dataPoints)
	{
		totalDistance += abs(sqrt( pow(point[0] - solution[0], 2) + pow(point[1] - solution[1], 2) ) - solution[2]);
	}
	return totalDistance;
}
