#pragma once


#include "ProblemToSolve.h"


class ExtremumFunctionProblem : public ProblemToSolve
{
public:
    ExtremumFunctionProblem();
    ExtremumFunctionProblem(ExtremumFunctionProblem const&) = default;
    ExtremumFunctionProblem& operator=(ExtremumFunctionProblem const&) = default;
    ~ExtremumFunctionProblem() = default;

    static double peak(double x, double y);

private:
    static std::string const smTitle;
    static std::string const smProblemSummary;
    static std::string const smProblemDescription;
    static std::string const smExpectedSolution;
};

