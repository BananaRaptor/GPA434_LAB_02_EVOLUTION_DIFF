#pragma once
#include "DEParameters.h"
#include "DEPopulation.h"
#include "DEStatistics.h"
#include "ThreeSamplesWithOneExclusion.h"
#include "Random.h"

class DifferentialEvolution
{
	using real = double;
private:
	DEParameters mParameters;
	size_t mCurrentGeneration;
	DEPopulation mX;
	DEPopulation mM;
	DEPopulation mT;
	DEStatistics mStatistics;
	ThreeSamplesWithOneExclusion mSamplingTool;

	size_t randomR();
	static real randomCR();
	void processFitness(DEPopulation& population);
	void processMutation();
	void processCrossover();
	void processSelection();
	void processStatistics();
	void evolveOne();

public:
	DifferentialEvolution();

	DifferentialEvolution(DifferentialEvolution const& other) = default;
	DifferentialEvolution& operator=(const DifferentialEvolution& other) = default;
	DifferentialEvolution(DifferentialEvolution&& other) noexcept = default;

	~DifferentialEvolution() = default;

	DEParameters parameters() const;
	bool isReadyToEvolve() const;
	size_t currentGeneration() const;
	bool isMaximumGenerationReached() const;
	DESolution bestSolution() const;
	void setup(DEParameters const& parameters);
	void reset();
	bool evolve();
	
};

