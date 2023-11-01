#include "Solver.h"

Solver::Solver()
{
}


std::string Solver::problemPresentation() const
{
	return mProblemPresentation;
}

DESolution Solver::bestSolution() const
{
	return mDE.bestSolution();
}

void Solver::solve()
{
	mDE.reset();
	mDE.setup(mParameters);
	mDE.evolve();
}
