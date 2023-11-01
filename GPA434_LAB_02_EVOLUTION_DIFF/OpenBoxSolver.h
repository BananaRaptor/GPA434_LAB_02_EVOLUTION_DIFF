#pragma once
#include "Solver.h"
#include "OpenBoxProblem.h"
#include "DESolution.h"
#include <functional>

using real = double;
using FitnessFunction = std::function<real(real)>;
using ObjectiveFunction = std::function<real(DESolution const&)>;
using namespace std::placeholders;

class OpenBoxSolver : public Solver
{
private :
	OpenBoxProblem mOpenBoxProblem;

public : 
	std::function<real(DESolution const& solution)> processCall = std::bind(&OpenBoxSolver::process, this, std::placeholders::_1);

	OpenBoxSolver();

	OpenBoxSolver(OpenBoxSolver const& other) = default;
	OpenBoxSolver& operator=(const OpenBoxSolver& other) = default;
	OpenBoxSolver(OpenBoxSolver&& other) noexcept = default;

	~OpenBoxSolver() = default;

	real process(DESolution const& solution);
};

