#pragma once


#include "ProblemToSolve.h"
#include <array>


class CircleFittingProblem : public ProblemToSolve
{
public:
    CircleFittingProblem();
    CircleFittingProblem(CircleFittingProblem const&) = default;
    CircleFittingProblem& operator=(CircleFittingProblem const&) = default;
    ~CircleFittingProblem() = default;

    static std::array<std::array<double, 2>, 50> const dataPoints;

private:
    static std::string const smTitle;
    static std::string const smProblemSummary;
    static std::string const smProblemDescription;
    static std::string const smExpectedSolution;
};


