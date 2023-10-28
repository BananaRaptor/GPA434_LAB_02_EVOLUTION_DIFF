#include "DifferentialEvolution.h"

DifferentialEvolution::DifferentialEvolution()
{
}

DEParameters DifferentialEvolution::parameters() const
{
	return mParameters;
}

bool DifferentialEvolution::isReadyToEvolve() const
{
	return false;
}

size_t DifferentialEvolution::currentGeneration() const
{
	return mCurrentGeneration;
}

bool DifferentialEvolution::isMaximumGenerationReached() const
{
	return mCurrentGeneration >= mParameters.maximumGenerationCount();
}

DESolution DifferentialEvolution::bestSolution() const
{
	return mT.bestSolution();
}

void DifferentialEvolution::setup(DEParameters const& parameters)
{
	mParameters = parameters;
	mX.setup(mParameters.populationSize(), mParameters.domain());
	mM.setup(mParameters.populationSize(), mParameters.domain());
	mT.setup(mParameters.populationSize(), mParameters.domain());
}

void DifferentialEvolution::reset()
{
	mX.setup(mParameters.populationSize(), mParameters.domain());
	mM.setup(mParameters.populationSize(), mParameters.domain());
	mT.setup(mParameters.populationSize(), mParameters.domain());
}

bool DifferentialEvolution::evolve()
{
	return false;
}

size_t DifferentialEvolution::randomR()
{
	return size_t();
}

DifferentialEvolution::real DifferentialEvolution::randomCR()
{
	return real();
}

void DifferentialEvolution::processFitness(DEPopulation& population)
{
}

void DifferentialEvolution::processMutation()
{
}

void DifferentialEvolution::processCrossover()
{
}

void DifferentialEvolution::processSelection()
{
}

void DifferentialEvolution::processStatistics()
{
}

void DifferentialEvolution::evolveOne()
{
}
