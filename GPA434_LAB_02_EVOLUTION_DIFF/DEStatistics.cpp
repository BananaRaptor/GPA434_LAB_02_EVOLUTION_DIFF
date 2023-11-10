#include "DEStatistics.h"

/// <summary>
/// Retourne la taille de la population
/// </summary>
/// <returns>la taille de la population</returns>
size_t DEStatistics::size() const
{
    return mStatistics.size();
}

/// <summary>
/// Retourne la solution à l'index
/// </summary>
/// <returns>la solution à l'index</returns>
DESolution& DEStatistics::operator[](size_t index)
{
    return mStatistics.at(index);
}

/// <summary>
/// Retourne la meilleur solution selon la fitness value
/// </summary>
/// <returns>la meilleur solution</returns>
DESolution DEStatistics::bestSolution() const
{
    DESolution bestValue = DESolution();

    for (size_t i = 0; i < mStatistics.size(); i++)
    {
        if (mStatistics.at(i).fitnessValue() > bestValue.fitnessValue()) {
            bestValue = mStatistics.at(i);
        }
    }

    return bestValue;
}


/// <summary>
/// Ajoute une solution à la liste de solution
/// </summary>
/// <param name="solution">La solution à ajouté</param>
void DEStatistics::add(DESolution const& solution)
{
   mStatistics.push_back(solution);
}

/// <summary>
/// Efface la liste de solution
/// </summary>
void DEStatistics::reset()
{
    mStatistics.clear();
}
