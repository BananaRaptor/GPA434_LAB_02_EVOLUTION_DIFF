#include "DEParameters.h"


double defaultFitness(std::vector<real> values) {
	return values[0];
}


static const DEParameters::FitnessFunction mDefaultFitnessFunction{Fitness::identity};
static const DEParameters::ObjectiveFunction mDefaultObjectiveFunction {defaultFitness};

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
	return false;
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
