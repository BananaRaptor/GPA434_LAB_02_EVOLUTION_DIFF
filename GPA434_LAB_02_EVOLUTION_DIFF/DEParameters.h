#pragma once
#include "Fitness.h"
#include "DEDomain.h"
#include <functional>

class DEParameters
{
	using real = double;
	using FitnessFunction = std::function<real(real)>;
	using ObjectiveFunction = std::function<real(std::vector<real>)>;
private :
	static const size_t smMinPopulationSize{ 4 };
	static constexpr double smMinF{ 0 };
	static constexpr double smMinCR{ 0 };
	static const size_t smMinMaxGenerationCount{ 10 };
	static const size_t smMaxPopulationSize{ 500 };
	static constexpr double smMaxF{ 2 };
	static constexpr double smMaxCR{ 1 };
	static const size_t smMaxMaxGenerationCount{ 10000 };
	static const size_t smDefaultPopulationSize{ 25 };
	static constexpr double smDefaultF{ (smMinF + smMaxF) / 2 };
	static constexpr double smDefaultCR{ (smMinCR + smMaxCR) / 2 };
	static const size_t smDefaultMaxGenerationCount { 250 };
	static const FitnessFunction mDefaultFitnessFunction;
	static const ObjectiveFunction mDefaultObjectiveFunction;

	DEDomain mDomain;
	size_t mPopulationSize;
	real mF;
	real mCR;
	size_t mMaxGenerationCount;
	ObjectiveFunction mObjectiveFunction;
	FitnessFunction mFitnessFunction;

public :
	DEParameters();
	DEParameters(DEDomain const & domain, size_t populationSize, real kF, real kCR, size_t maximumGenerationCount, ObjectiveFunction objectiveFunction, FitnessFunction fitnessFunction);

	DEParameters(DEParameters const& other) = default;
	DEParameters& operator=(const DEParameters& other) = default;
	DEParameters(DEParameters&& other) noexcept = default;

	~DEParameters() = default;

	bool isReady() const;
	DEDomain domain() const;
	size_t populationSize() const;
	real f() const;
	real cR() const;
	size_t maximumGenerationCount() const;
	ObjectiveFunction objectiveFunction() const;
	FitnessFunction fitnessFunction() const;
	void setDomain(DEDomain const& domain);
	void setPopulationSize(size_t populationSize);
	void setF(real f);
	void setCr(real cR);
	void setMaximumGeneration(size_t maxGenerationCount);
	void setObjectiveFunction(ObjectiveFunction objectiveFunction);
	void setFitnessFunction(FitnessFunction fitnessFunction);



	
};

