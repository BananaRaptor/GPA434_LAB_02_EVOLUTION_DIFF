#include "DEParameters.h"


const size_t DEParameters::smMinPopulationSize = 4;
const size_t DEParameters::smMinMaxGenerationCount = 10;
const size_t DEParameters::smMaxPopulationSize = 500;
const size_t DEParameters::smMaxMaxGenerationCount = 10000;
const size_t DEParameters::smDefaultPopulationSize = 25;
const size_t DEParameters::smDefaultMaxGenerationCount = 250;

double defaultFitness(DESolution const& solution) {
	return solution[0];
}

const DEParameters::FitnessFunction DEParameters::mDefaultFitnessFunction{Fitness::identity};
const DEParameters::ObjectiveFunction DEParameters::mDefaultObjectiveFunction {defaultFitness};

DEParameters::DEParameters():
	DEParameters(DEDomain(), smDefaultPopulationSize, smDefaultF, smDefaultCR, smDefaultMaxGenerationCount, mDefaultObjectiveFunction, mDefaultFitnessFunction)
{
}

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

DEDomain DEParameters::domain() const
{
	return mDomain;
}

size_t DEParameters::populationSize() const
{
	return mPopulationSize;
}

DEParameters::real DEParameters::f() const
{
	return mF;
}

DEParameters::real DEParameters::cR() const
{
	return mCR;
}

size_t DEParameters::maximumGenerationCount() const
{
	return mMaxGenerationCount;
}

DEParameters::ObjectiveFunction DEParameters::objectiveFunction() const
{
	return mObjectiveFunction;
}

DEParameters::FitnessFunction DEParameters::fitnessFunction() const
{
	return mFitnessFunction;
}

void DEParameters::setDomain(DEDomain const& domain)
{
	mDomain = domain;
}

void DEParameters::setPopulationSize(size_t populationSize)
{
	mPopulationSize = populationSize;
}

void DEParameters::setF(real f)
{
	mF = f;
}

void DEParameters::setCr(real cR)
{
	mCR = cR;
}

void DEParameters::setMaximumGeneration(size_t maxGenerationCount)
{
	mMaxGenerationCount = maxGenerationCount;
}

void DEParameters::setObjectiveFunction(ObjectiveFunction objectiveFunction)
{
	mObjectiveFunction = objectiveFunction;
}

void DEParameters::setFitnessFunction(FitnessFunction fitnessFunction)
{
	mFitnessFunction = fitnessFunction;
}
