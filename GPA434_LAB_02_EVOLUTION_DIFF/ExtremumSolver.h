#pragma once
#include "Solver.h"
#include "ExtremumFunctionProblem.h"
#include "DESolution.h"
#include <functional>

using real = double;
using FitnessFunction = std::function<real(real)>;
using ObjectiveFunction = std::function<real(DESolution const&)>;
using namespace std::placeholders;


class ExtremumSolver : public Solver
{
private:
	ExtremumFunctionProblem mExtremumFunctionProblem;

public:
	std::function<real(DESolution const& solution)> processCall = std::bind(&ExtremumSolver::process, this, std::placeholders::_1);

	ExtremumSolver();

	ExtremumSolver(ExtremumSolver const& other) = default;
	ExtremumSolver& operator=(const ExtremumSolver& other) = default;
	ExtremumSolver(ExtremumSolver&& other) noexcept = default;

	~ExtremumSolver() = default;

	real process(DESolution const& solution);
};

