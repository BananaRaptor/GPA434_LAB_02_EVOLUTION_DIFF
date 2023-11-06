#pragma once
#include "Solver.h"
#include "CircleFittingProblem.h"
#include "DESolution.h"
#include <functional>

using real = double;
using FitnessFunction = std::function<real(real)>;
using ObjectiveFunction = std::function<real(DESolution const&)>;
using namespace std::placeholders;


class CircleSolver : public Solver
{
private:
	CircleFittingProblem mCircleProblem;

public:
	std::function<real(DESolution const& solution)> processCall = std::bind(&CircleSolver::process, this, std::placeholders::_1);

	CircleSolver();

	CircleSolver(CircleSolver const& other) = default;
	CircleSolver& operator=(const CircleSolver& other) = default;
	CircleSolver(CircleSolver&& other) noexcept = default;

	~CircleSolver() = default;

	real process(DESolution const& solution);
};

