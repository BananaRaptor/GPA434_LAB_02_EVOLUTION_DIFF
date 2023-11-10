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
/// Retourne la solution à l'index donnée
/// </summary>
/// <param name="index">L'index de la solution</param>
/// <returns>La solution à l'index</returns>
DESolution& DEPopulation::operator[](size_t index)
{
    return mData.at(index);
}

/// <summary>
/// Retourne la solution à l'index donnée
/// </summary>
/// <param name="index">L'index de la solution</param>
/// <returns>La solution à l'index</returns>
const DESolution DEPopulation::operator[](size_t index) const
{
    return mData.at(index);
}

/// <summary>
/// Definie la population à la taille demandé et applique le domaine pour chaque solution
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
/// Donne une valeur aléatoire pour chaque parametre dans les solutions selon le domaine données
/// </summary>
/// <param name="domain">Le domaine</param>
void DEPopulation::randomize(DEDomain const& domain)
{
    for (size_t i = 0; i < mData.size(); i++)
    {
        mData.at(i).randomize(domain);
    }
}
