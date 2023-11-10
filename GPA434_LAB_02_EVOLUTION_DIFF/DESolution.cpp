#include "DESolution.h"
using real = double;
#include <string>

/// <summary>
/// Assignation des valeurs statique
/// </summary>
size_t DESolution::smFixedNotationPrecision = 2;
std::string DESolution::smPrefixNotation = "Parametres : ";
std::string DESolution::smSeparatorNotation  = " , ";
std::string DESolution::smSuffixNotation = " et une valeur de la fonction objective de : ";

/// <summary>
/// Constructeur avec une taille des parametres
/// </summary>
/// <param name="size">La taille des parametres</param>
DESolution::DESolution(size_t size)
{
	mData.resize(size);
	mFitnessValue = 0;
	mObjectiveValue = 0;
	setZero();
}

/// <summary>
/// Retourne vrai si les parametres ne sont pas de tailles zéro
/// </summary>
/// <returns>si les parametres ne sont pas de tailles zéro</returns>
bool DESolution::isDefined()
{
	return !mData.empty();
}

/// <summary>
/// Retourne le nombre de paramtre
/// </summary>
/// <returns>le nombre de parametre</returns>
size_t DESolution::size()
{
	return mData.size();
}

/// <summary>
/// Retourne la valeur objective
/// </summary>
/// <returns>La valeur objective</returns>
real DESolution::objectiveValue() const
{
	return mObjectiveValue;
}

/// <summary>
/// Retourne la valeur de fitness
/// </summary>
/// <returns>La valeur de fitness</returns>
real DESolution::fitnessValue() const
{
	return mFitnessValue;
}

/// <summary>
/// Retourne le parametre à l'index
/// </summary>
/// <param name="index">L'index du parametre</param>
/// <returns>Le parametre</returns>
real& DESolution::operator[](size_t index)
{
	return mData.at(index);
}


/// <summary>
/// Retourne le parametre à l'index
/// </summary>
/// <param name="index">L'index du parametre</param>
/// <returns>Le parametre</returns>
const real DESolution::operator[](size_t index) const
{
	return mData.at(index);
}
 
/// <summary>
/// Définie tout les parametre à la valeur 0
/// </summary>
void DESolution::setZero()
{
	for (size_t i = 0; i < mData.size(); i++)
	{
		mData[i] = 0;
	}
}

/// <summary>
/// Defini tout les parametre à la valeur la plus basse permis par le domaine
/// </summary>
/// <param name="domain">Le domaine à respecter</param>
void DESolution::setup(DEDomain const& domain)
{
	mData.resize(domain.size());
	for (size_t i = 0; i < mData.size(); i++)
	{
		mData[i] = domain[i].lower();
	}
}

/// <summary>
/// Defini tout les parametre à une valeur aleatoire dans le domaine permis par le domaine
/// </summary>
/// <param name="domain">Le domaine à respecter</param>
void DESolution::randomize(DEDomain const& domain)
{
	for (size_t i = 0; i < mData.size(); i++)
	{
		mData[i] = domain[i].randomValue();
	}
}

/// <summary>
/// Evalue les valeurs objective et de fitness selon les fonctions donnée
/// </summary>
/// <param name="objectiveFunction">La fonction objective</param>
/// <param name="fitnessFunction">La fonction de fitness</param>
void DESolution::evaluate(DESolution::ObjectiveFunction objectiveFunction, DESolution::FitnessFunction fitnessFunction)
{
	double temp = objectiveFunction(*this);
	mObjectiveValue = temp;
	mFitnessValue = fitnessFunction(mObjectiveValue);
}

/// <summary>
/// Effectue l'opération - pour chaque paramètre
/// </summary>
/// <returns>La solution suite à l'opération</returns>
DESolution DESolution::operator-() const
{
	DESolution temp = DESolution(mData.size());

	for (size_t i = 0; i < mData.size(); i++)
	{
		temp[i];
		temp[i] = -mData[i];
	}

	return temp;
}

/// <summary>
/// Effectue l'opération - pour chaque paramètre
/// </summary>
/// <returns>La solution suite à l'opération</returns>
DESolution DESolution::operator-(DESolution solution) const
{
	DESolution temp = DESolution(solution.size());

	for (size_t i = 0; i < mData.size(); i++)
	{
		temp[i];
		temp[i] = mData[i] - solution[i];
	}

	return temp;
}

/// <summary>
/// Effectue l'opération + pour chaque paramètre
/// </summary>
/// <returns>La solution suite à l'opération</returns>
DESolution DESolution::operator+(DESolution solution) const
{
	DESolution temp = DESolution(solution.size());

	for (size_t i = 0; i < mData.size(); i++)
	{
		temp[i];
		temp[i] = mData[i] + solution[i];
	}

	return temp;
}

/// <summary>
/// Effectue l'opération * pour chaque paramètre
/// </summary>
/// <returns>La solution suite à l'opération</returns>
DESolution DESolution::operator*(DESolution solution) const
{
	DESolution temp = DESolution(solution.size());

	for (size_t i = 0; i < mData.size(); i++)
	{
		temp[i];
		temp[i] = mData[i] * solution[i];
	}

	return temp;
}

/// <summary>
/// Formatte la solution pour l'affichage à la console
/// </summary>
/// <returns>La solution formatée</returns>
std::string DESolution::toString() const
{
	std::string test = smPrefixNotation;
	for (real data : mData)
	{
		test += std::to_string(data) + smSeparatorNotation;
	}
	test += smSuffixNotation + std::to_string(objectiveValue()) + "\n";
	return test;
}

/// <summary>
/// Retourne la précision
/// </summary>
/// <returns>la précision</returns>
size_t DESolution::fixedNotationPrecision()
{
	return smFixedNotationPrecision;
}

/// <summary>
/// Retourne la notation du prefix
/// </summary>
/// <returns>le prefix</returns>
std::string DESolution::prefixNotation()
{
	return smPrefixNotation;
}

/// <summary>
/// Retourne la notation du separateur
/// </summary>
/// <returns>le separateur</returns>
std::string DESolution::seperatorNotation()
{
	return smSeparatorNotation;
}

/// <summary>
/// Retourne la notation du suffix
/// </summary>
/// <returns>le suffix</returns>
std::string DESolution::suffixNotation()
{
	return smSuffixNotation;
}

/// <summary>
/// Définie la notation de la précision
/// </summary>
/// <param name="precision">La précision</param>
void DESolution::setFixedNotationPrecision(size_t precision)
{
	smFixedNotationPrecision = precision;
}

/// <summary>
/// Definie le prefix, le separator et le suffix 
/// </summary>
/// <param name="prefix">le prefix</param>
/// <param name="separator">le separator</param>
/// <param name="suffix">le suffix</param>
void DESolution::setNotationFormat(std::string& prefix, std::string& separator, std::string& suffix)
{
	smPrefixNotation = prefix;
	smSeparatorNotation = separator;
	smSuffixNotation = suffix;
}

/// <summary>
/// Effectue l'opération * pour chaque paramètre
/// </summary>
/// <returns>La solution suite à l'opération</returns>
DESolution operator*(real lhs, DESolution const& rhs)
{
	DESolution temp = rhs;
	for (size_t i = 0; i < rhs.mData.size(); i++)
	{
		temp.mData[i] = rhs.mData[i] * lhs;
	}
	return temp;
}

/// <summary>
/// Effectue l'opération << en appellant to string
/// </summary>
/// <returns>La solution suite à l'opération</returns>
std::ostream& operator<<(std::ostream& lhs, DESolution const& rhs)
{
	 lhs << rhs.toString();
	 return lhs;
}

