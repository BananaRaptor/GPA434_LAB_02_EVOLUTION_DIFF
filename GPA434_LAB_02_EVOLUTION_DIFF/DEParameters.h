#pragma once
#include "Fitness.h"
#include "DEDomain.h"
#include "DESolution.h"
#include <functional>

class DEParameters
{
public:
	using real = double;
	using FitnessFunction = std::function<real(real)>;
	using ObjectiveFunction = std::function<real(DESolution const&)>;
	DEParameters();
	DEParameters(DEDomain const& domain, size_t populationSize, real kF, real kCR, size_t maximumGenerationCount, ObjectiveFunction objectiveFunction, FitnessFunction fitnessFunction);

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

private :
	static const size_t smMinPopulationSize;
	static constexpr double smMinF{ 0 };
	static constexpr double smMinCR{ 0 };
	static const size_t smMinMaxGenerationCount;
	static const size_t smMaxPopulationSize;
	static constexpr double smMaxF{ 2 };
	static constexpr double smMaxCR{ 1 };
	static const size_t smMaxMaxGenerationCount;
	static const size_t smDefaultPopulationSize;
	static constexpr double smDefaultF{ (smMinF + smMaxF) / 2 };
	static constexpr double smDefaultCR{ (smMinCR + smMaxCR) / 2 };
	static const size_t smDefaultMaxGenerationCount;
	static const FitnessFunction mDefaultFitnessFunction;
	static const ObjectiveFunction mDefaultObjectiveFunction;

	DEDomain mDomain;
	size_t mPopulationSize;
	real mF;
	real mCR;
	size_t mMaxGenerationCount;
	ObjectiveFunction mObjectiveFunction;
	FitnessFunction mFitnessFunction;
};

