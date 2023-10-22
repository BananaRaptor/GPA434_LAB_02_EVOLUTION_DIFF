#pragma once


#include "ProblemToSolve.h"


class OpenBoxProblem : public ProblemToSolve
{
public:
    OpenBoxProblem();
    OpenBoxProblem(OpenBoxProblem const&) = default;
    OpenBoxProblem& operator=(OpenBoxProblem const&) = default;
    ~OpenBoxProblem() = default;

    static double boxWidth();
    static double boxHeight();

private:
    static std::string const smTitle;
    static std::string const smProblemSummary;
    static std::string const smProblemDescription;
    static std::string const smExpectedSolution;
    static double const smBoxWidth;
    static double const smBoxHeight;
};


