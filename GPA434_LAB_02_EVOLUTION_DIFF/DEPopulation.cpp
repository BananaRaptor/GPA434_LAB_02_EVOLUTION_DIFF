#include "DEPopulation.h"

/// <summary>
/// Retourne la meilleur solution dans la population
/// </summary>
/// <returns>la meilleur solution</returns>
DESolution DEPopulation::bestSolution() const
{
    DESolution tempValue;
    tempValue = DESolution(size());
    for (size_t i = 0; i < mData.size(); i++)
    {
        if (mData.at(i).fitnessValue() > tempValue.fitnessValue()) {
            tempValue = mData.at(i);
        }
    }
    DESolution bestValue = tempValue;
    return bestValue;
}

/// <summary>
/// Retourne la taille de la population
/// </summary>
/// <returns>la taille de la population</returns>
size_t DEPopulation::size() const
{
    return mData.size();
}

/// <summary>
/// Retourne la solution � l'index donn�e
/// </summary>
/// <param name="index">L'index de la solution</param>
/// <returns>La solution � l'index</returns>
DESolution& DEPopulation::operator[](size_t index)
{
    return mData.at(index);
}

/// <summary>
/// Retourne la solution � l'index donn�e
/// </summary>
/// <param name="index">L'index de la solution</param>
/// <returns>La solution � l'index</returns>
const DESolution DEPopulation::operator[](size_t index) const
{
    return mData.at(index);
}

/// <summary>
/// Definie la population � la taille demand� et applique le domaine pour chaque solution
/// </summary>
/// <param name="size">La taille</param>
/// <param name="domain">Le domaine</param>
void DEPopulation::setup(size_t size, DEDomain const& domain)
{
    mData.resize(size);
    for (size_t i = 0; i < mData.size(); i++)
    {
        mData.at(i).setup(domain);
    }
    
}

/// <summary>
/// Donne une valeur al�atoire pour chaque parametre dans les solutions selon le domaine donn�es
/// </summary>
/// <param name="domain">Le domaine</param>
void DEPopulation::randomize(DEDomain const& domain)
{
    for (size_t i = 0; i < mData.size(); i++)
    {
        mData.at(i).randomize(domain);
    }
}
