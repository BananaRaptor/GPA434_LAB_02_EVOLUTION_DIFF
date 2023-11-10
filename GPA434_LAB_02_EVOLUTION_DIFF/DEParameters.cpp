#include "DEParameters.h"

/// <summary>
/// Assignation des valeurs statiques
/// </summary>
const size_t DEParameters::smMinPopulationSize = 4;
const size_t DEParameters::smMinMaxGenerationCount = 10;
const size_t DEParameters::smMaxPopulationSize = 500;
const size_t DEParameters::smMaxMaxGenerationCount = 10000;
const size_t DEParameters::smDefaultPopulationSize = 25;
const size_t DEParameters::smDefaultMaxGenerationCount = 250;

/// <summary>
/// Fonction de fitness par défault
/// </summary>
/// <param name="solution"></param>
/// <returns></returns>
double defaultFitness(DESolution const& solution) {
	return solution[0];
}

const DEParameters::FitnessFunction DEParameters::mDefaultFitnessFunction{Fitness::identity};
const DEParameters::ObjectiveFunction DEParameters::mDefaultObjectiveFunction {defaultFitness};

/// <summary>
/// constructeur de base
/// </summary>
DEParameters::DEParameters():
	DEParameters(DEDomain(), smDefaultPopulationSize, smDefaultF, smDefaultCR, smDefaultMaxGenerationCount, mDefaultObjectiveFunction, mDefaultFitnessFunction)
{
}

/// <summary>
/// constructeur avec valeur
/// </summary>
/// <param name="domain">Domaine</param>
/// <param name="populationSize">Taille de la population</param>
/// <param name="kF">Facteur de mutation</param>
/// <param name="kCR">Facteur de croisement</param>
/// <param name="maximumGenerationCount">Nombre max de génération</param>
/// <param name="objectiveFunction">Fonction Objective Pointeur</param>
/// <param name="fitnessFunction">Fonction Fitness Pointeur</param>
DEParameters::DEParameters(DEDomain const& domain, size_t populationSize, real kF, real kCR, size_t maximumGenerationCount, ObjectiveFunction objectiveFunction, FitnessFunction fitnessFunction):
mDomain { domain },
mPopulationSize{ populationSize },
mF{kF},
mCR{kCR},
mMaxGenerationCount{maximumGenerationCount},
mObjectiveFunction{objectiveFunction},
mFitnessFunction{fitnessFunction}
{
}

/// <summary>
/// Vérifie si les paramètres sont dans les valeurs conformes
/// </summary>
/// <returns></returns>
bool DEParameters::isReady() const
{
	return (mDomain.isDefined()
		&& mPopulationSize		> smMinPopulationSize			&&	mPopulationSize		< smMaxPopulationSize
		&& mF					> smMinF						&&	mF					< smMaxF
		&& mCR					> smMinCR						&&	mCR					< smMaxCR
		&& mMaxGenerationCount  > smMinMaxGenerationCount		&& mMaxGenerationCount	< smMaxMaxGenerationCount
		&& mObjectiveFunction	!= NULL
		&& mFitnessFunction		!= NULL);
}

/// <summary>
/// Retourne le domaine
/// </summary>
/// <returns>Le domaine</returns>
DEDomain DEParameters::domain() const
{
	return mDomain;
}

/// <summary>
/// Retourne la taille de la population
/// </summary>
/// <returns>la taille de la population</returns>
size_t DEParameters::populationSize() const
{
	return mPopulationSize;
}

/// <summary>
/// Retourne le facteur de mutation
/// </summary>
/// <returns>Le facteur de mutation</returns>
DEParameters::real DEParameters::f() const
{
	return mF;
}

/// <summary>
/// Retourne le facteur de croisement
/// </summary>
/// <returns>Le facteur de croisement</returns>
DEParameters::real DEParameters::cR() const
{
	return mCR;
}

/// <summary>
/// Retourne le nombre de generation max
/// </summary>
/// <returns>generation max</returns>
size_t DEParameters::maximumGenerationCount() const
{
	return mMaxGenerationCount;
}

/// <summary>
/// Retourne la fonction objective
/// </summary>
/// <returns>la fonction objective</returns>
DEParameters::ObjectiveFunction DEParameters::objectiveFunction() const
{
	return mObjectiveFunction;
}
/// <summary>
/// Retourne la fonction fitness
/// </summary>
/// <returns>la fonction fitness</returns>
DEParameters::FitnessFunction DEParameters::fitnessFunction() const
{
	return mFitnessFunction;
}

/// <summary>
/// Definie le domaine
/// </summary>
/// <param name="domain">le domaine</param>
void DEParameters::setDomain(DEDomain const& domain)
{
	mDomain = domain;
}

/// <summary>
/// Definie la taille de la population
/// </summary>
/// <param name="populationSize">La taille de la population</param>
void DEParameters::setPopulationSize(size_t populationSize)
{
	mPopulationSize = populationSize;
}

/// <summary>
/// Definie le facteur de mutation
/// </summary>
/// <param name="populationSize">le facteur de mutation</param>
void DEParameters::setF(real f)
{
	mF = f;
}

/// <summary>
/// Definie le facteur de croisement
/// </summary>
/// <param name="populationSize">le facteur de croisement</param>
void DEParameters::setCr(real cR)
{
	mCR = cR;
}

/// <summary>
/// Defini le nombre maximum de generation permise
/// </summary>
/// <param name="maxGenerationCount">le nombre maximum de generation permise</param>
void DEParameters::setMaximumGeneration(size_t maxGenerationCount)
{
	mMaxGenerationCount = maxGenerationCount;
}

/// <summary>
/// Definie la fonction objective
/// </summary>
/// <param name="objectiveFunction">la fonction objective</param>
void DEParameters::setObjectiveFunction(ObjectiveFunction objectiveFunction)
{
	mObjectiveFunction = objectiveFunction;
}

/// <summary>
/// Definie la fonction de fitness
/// </summary>
/// <param name="objectiveFunction">la fonction de fitness</param>
void DEParameters::setFitnessFunction(FitnessFunction fitnessFunction)
{
	mFitnessFunction = fitnessFunction;
}
