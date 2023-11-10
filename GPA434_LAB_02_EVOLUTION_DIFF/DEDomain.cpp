#include "DEDomain.h"

/// <summary>
/// Vérification si les intervals sont définies
/// </summary>
/// <returns></returns>
bool DEDomain::isDefined() const
{
	return !mInterval.empty();
}

/// <summary>
/// Retuorne la taille des intervalles
/// </summary>
/// <returns></returns>
size_t DEDomain::size() const
{
	return mInterval.size();
}

/// <summary>
/// Redifine la taille des intervalles
/// </summary>
/// <param name="size"></param>
void DEDomain::resize(size_t size)
{
	mInterval.resize(size);
}

/// <summary>
/// Definie tout les intervalles au valeurs données
/// </summary>
/// <param name="lower">Limite basse</param>
/// <param name="higher">Limite haute</param>
void DEDomain::setAllIntervals(double lower, double higher)
{
	for (size_t i = 0; i < mInterval.size() ; i++ )
	{
		mInterval[i].set(lower, higher);
	}
}

/// <summary>
/// Retourne l'intervalle à l'index donnée
/// </summary>
/// <param name="index">L'index de l'intervale</param>
/// <returns>L'intervale à l'index</returns>
Interval& DEDomain::operator[](size_t index)
{
	return mInterval.at(index);
}

/// <summary>
/// Retourne l'intervalle à l'index donnée
/// </summary>
/// <param name="index">L'index de l'intervale</param>
/// <returns>L'intervale à l'index</returns>
const Interval& DEDomain::operator[](size_t index) const
{
	return mInterval.at(index);
}
