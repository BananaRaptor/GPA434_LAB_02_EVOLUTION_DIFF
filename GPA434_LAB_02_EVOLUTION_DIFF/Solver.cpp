#include "Solver.h"

/// <summary>
/// constructeur
/// </summary>
Solver::Solver()
{
}


/// <summary>
/// Retourne la présentation du problème
/// </summary>
/// <returns>la présentation du problème</returns>
std::string Solver::problemPresentation() const
{
	return mProblemPresentation;
}

/// <summary>
/// Retourne la meilleur solution
/// </summary>
/// <returns>la meilleur solution</returns>
DESolution Solver::bestSolution() const
{
	return mDE.bestSolution(); 
}


/// <summary>
/// Effectue l'évolution différentiel
/// </summary>
void Solver::solve()
{
	mDE.reset();
	mDE.setup(mParameters);
	mDE.evolve();
}
