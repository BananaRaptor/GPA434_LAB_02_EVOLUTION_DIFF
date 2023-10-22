#pragma once


#include <string>


class ProblemToSolve
{
public:
    ProblemToSolve(std::string const & title, std::string const & problemSummary, std::string const & problemDescription, std::string const& expectedSolution);
    ProblemToSolve(ProblemToSolve const&) = default;
    ProblemToSolve& operator=(ProblemToSolve const&) = default;
    ~ProblemToSolve() = default;

    std::string title() const;
    std::string problemSummary() const;
    std::string problemDescription() const;
    std::string expectedSolution() const;

    std::string problemPresentation() const;

protected:
    std::string mTitle;
    std::string mProblemSummary;
    std::string mProblemDescription;
    std::string mExpectedSolution;

    static std::string separator(size_t length = 100, std::string info = "");
};

