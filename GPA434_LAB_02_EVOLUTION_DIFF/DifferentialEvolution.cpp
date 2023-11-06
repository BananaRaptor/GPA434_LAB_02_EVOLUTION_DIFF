#include "DifferentialEvolution.h"

DifferentialEvolution::DifferentialEvolution() :
	mParameters{DEParameters()},
	mCurrentGeneration{0},
	mX{DEPopulation()},
	mM{ DEPopulation() },
	mT{ DEPopulation() },
	mStatistics { DEStatistics()},
	mSamplingTool{ThreeSamplesWithOneExclusion(4)} 
{
}

DEParameters DifferentialEvolution::parameters() const
{
	return mParameters;
}

bool DifferentialEvolution::isReadyToEvolve() const
{
	return mParameters.isReady();
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
	return mStatistics.bestSolution();
}

DESolution DifferentialEvolution::secondBestSolutionWithOppositeValue() const
{
	return mStatistics.secondBestSolutionWithOppositeValue(mStatistics.bestSolution());
}

void DifferentialEvolution::setup(DEParameters const& parameters)
{
	mParameters = parameters;
	mX.setup(mParameters.populationSize(), mParameters.domain());
	mM.setup(mParameters.populationSize(), mParameters.domain());
	mT.setup(mParameters.populationSize(), mParameters.domain());
	mX.randomize(mParameters.domain());
	mSamplingTool = ThreeSamplesWithOneExclusion(mParameters.populationSize());
}

void DifferentialEvolution::reset()
{
	mX.setup(mParameters.populationSize(), mParameters.domain());
	mM.setup(mParameters.populationSize(), mParameters.domain());
	mT.setup(mParameters.populationSize(), mParameters.domain());
}

bool DifferentialEvolution::evolve()
{
	while (mCurrentGeneration < mParameters.maximumGenerationCount())
	{
		evolveOne();
	}
	return true;
}

void DifferentialEvolution::evolveOne()
{
	processMutation();
	processCrossover();
	processSelection();
	processStatistics();
	mCurrentGeneration++;
}

size_t DifferentialEvolution::randomR()
{
	return Random::integer(0, mParameters.domain().size() - 1);
}

DifferentialEvolution::real DifferentialEvolution::randomCR()
{
	return Random::real(0, 1);
}

void DifferentialEvolution::processFitness(DEPopulation& population)
{
	for (size_t i = 0; i < mParameters.populationSize(); i++) {
		mX[i].evaluate(mParameters.objectiveFunction(), mParameters.fitnessFunction());
	}
}

void DifferentialEvolution::processMutation()
{
	mSamplingTool.prepare(mParameters.populationSize());

	for (size_t i = 0; i < mParameters.populationSize() ; i++){
		size_t s1, s2, s3;
		mSamplingTool.select(i, s1, s2, s3);
		for (size_t p = 0; p < mParameters.domain().size(); p++) {
			mM[i][p] = mX[s1][p] + mParameters.f() * (mX[s2][p] - mX[s3][p]);
			if (mM[i][p] > mParameters.domain()[p].higher()) {
				mM[i][p] = mParameters.domain()[p].higher();
			}
			
			if (mM[i][p] < mParameters.domain()[p].lower()) {
				mM[i][p] = mParameters.domain()[p].lower();
			}
		}
	}
}

void DifferentialEvolution::processCrossover()
{
	for (size_t i = 0; i < mParameters.populationSize(); i++) {
		size_t r = randomR();

		for (size_t p = 0; p < mParameters.domain().size(); p++) {
			if (r == i && randomCR() < mParameters.cR())
			{
				mT[i][p] = mM[i][p];
			}
			else
			{
				mT[i][p] = mX[i][p];
			}
		}
	}
}

void DifferentialEvolution::processSelection()
{
	for (size_t i = 0; i < mParameters.populationSize(); i++) {
		mX[i].evaluate(mParameters.objectiveFunction(), mParameters.fitnessFunction());
		mT[i].evaluate(mParameters.objectiveFunction(), mParameters.fitnessFunction());
		if (mT[i].fitnessValue() > mX[i].fitnessValue()) {
			mX[i] = mT[i];
		}
	}
}

void DifferentialEvolution::processStatistics()
{
	mStatistics.reset();
	for (size_t i = 0; i < mParameters.populationSize(); i++) {
		mStatistics.add(mX[i]);
	}

	mStatistics.bestSolution();
}


