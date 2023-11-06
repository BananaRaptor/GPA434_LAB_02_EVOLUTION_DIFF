#pragma once
#include "DifferentialEvolution.h"
#include "DEParameters.h"
#include <string>

class Solver
{
private :
	DifferentialEvolution mDE;
	
protected :
	std::string mProblemPresentation;
	DEParameters mParameters;

public :
	Solver();

	Solver(Solver const& other) = default;
	Solver& operator=(const Solver& other) = default;
	Solver(Solver&& other) noexcept = default;

	~Solver() = default;

	std::string problemPresentation() const;
	DESolution bestSolution() const;
	DESolution secondBestSolution() const;
	void solve();
};

