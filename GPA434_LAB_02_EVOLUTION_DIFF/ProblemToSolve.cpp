#include "ProblemToSolve.h"

/// <summary>
/// Constructeur avec des parametres
/// </summary>
/// <param name="title">Le titre du problème</param>
/// <param name="problemSummary">Le résumé du problème</param>
/// <param name="problemDescription">La description du problème</param>
/// <param name="expectedSolution">La solution attendu du problème</param>
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
/// Retourne le resumé du problème
/// </summary>
/// <returns>le resumé du problème</returns>
std::string ProblemToSolve::problemSummary() const
{
    return mProblemSummary;
}

/// <summary>
/// Retourne la description du problème
/// </summary>
/// <returns>la description du problème</returns>
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
/// Retourne la présentation du problème
/// </summary>
/// <returns>la présentation du problème</returns>
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



