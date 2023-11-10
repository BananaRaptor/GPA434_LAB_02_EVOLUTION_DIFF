#include "Solver.h"

/// <summary>
/// constructeur
/// </summary>
Solver::Solver()
{
}


/// <summary>
/// Retourne la pr�sentation du probl�me
/// </summary>
/// <returns>la pr�sentation du probl�me</returns>
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
/// Effectue l'�volution diff�rentiel
/// </summary>
void Solver::solve()
{
	mDE.reset();
	mDE.setup(mParameters);
	mDE.evolve();
}
