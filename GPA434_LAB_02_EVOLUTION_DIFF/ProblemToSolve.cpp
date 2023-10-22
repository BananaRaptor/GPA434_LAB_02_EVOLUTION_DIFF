#include "ProblemToSolve.h"


ProblemToSolve::ProblemToSolve(std::string const& title, std::string const& problemSummary, std::string const& problemDescription, std::string const& expectedSolution)
    : mTitle(title)
    , mProblemSummary(problemSummary)
    , mProblemDescription(problemDescription)
    , mExpectedSolution(expectedSolution)
{
}

std::string ProblemToSolve::title() const
{
    return mTitle;
}

std::string ProblemToSolve::problemSummary() const
{
    return mProblemSummary;
}

std::string ProblemToSolve::problemDescription() const
{
    return mProblemDescription;
}

std::string ProblemToSolve::expectedSolution() const
{
    return mExpectedSolution;
}

std::string ProblemToSolve::problemPresentation() const
{
    size_t length{ 100 };
    return  mTitle + separator(length, "Sommaire") +
            mProblemSummary + separator(length, "Description") +
            mProblemDescription + separator(length, "Solution attendue") +
            mExpectedSolution + separator(length);
}

std::string ProblemToSolve::separator(size_t length, std::string info)
{
    std::string sep;
    if (info.empty()) {
        sep = std::string(length, '-');
    } else {
        if (info.length() > length / 2 - 4) {
            info = info.substr(0, length / 2 - 4) + " ...";
        }
        sep = std::string(length - info.length() - 1, '-') + " " + info;
    }
    return "\n" + sep + "\n";
}



