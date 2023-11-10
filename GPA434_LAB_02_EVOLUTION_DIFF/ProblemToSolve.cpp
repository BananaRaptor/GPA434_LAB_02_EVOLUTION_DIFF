#include "ProblemToSolve.h"

/// <summary>
/// Constructeur avec des parametres
/// </summary>
/// <param name="title">Le titre du probl�me</param>
/// <param name="problemSummary">Le r�sum� du probl�me</param>
/// <param name="problemDescription">La description du probl�me</param>
/// <param name="expectedSolution">La solution attendu du probl�me</param>
ProblemToSolve::ProblemToSolve(std::string const& title, std::string const& problemSummary, std::string const& problemDescription, std::string const& expectedSolution)
    : mTitle(title)
    , mProblemSummary(problemSummary)
    , mProblemDescription(problemDescription)
    , mExpectedSolution(expectedSolution)
{
}

/// <summary>
/// Retourne le titre
/// </summary>
/// <returns>le titre</returns>
std::string ProblemToSolve::title() const
{
    return mTitle;
}

/// <summary>
/// Retourne le resum� du probl�me
/// </summary>
/// <returns>le resum� du probl�me</returns>
std::string ProblemToSolve::problemSummary() const
{
    return mProblemSummary;
}

/// <summary>
/// Retourne la description du probl�me
/// </summary>
/// <returns>la description du probl�me</returns>
std::string ProblemToSolve::problemDescription() const
{
    return mProblemDescription;
}

/// <summary>
/// Retourne la solution attendu
/// </summary>
/// <returns>la solution attendu</returns>
std::string ProblemToSolve::expectedSolution() const
{
    return mExpectedSolution;
}

/// <summary>
/// Retourne la pr�sentation du probl�me
/// </summary>
/// <returns>la pr�sentation du probl�me</returns>
std::string ProblemToSolve::problemPresentation() const
{
    size_t length{ 100 };
    return  mTitle + separator(length, "Sommaire") +
            mProblemSummary + separator(length, "Description") +
            mProblemDescription + separator(length, "Solution attendue") +
            mExpectedSolution + separator(length);
}

/// <summary>
/// Retourne le texte avec du \n et des ... au besoins
/// </summary>
/// <returns>le texte formatter</returns>
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



