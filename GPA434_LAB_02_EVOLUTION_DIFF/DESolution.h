#pragma once
#include <string>
#include <vector>
#include <format>
#include "DEDomain.h"
#include "DEDomain.h"

class DESolution
{
private:
	std::vector<double> mData;
	double mObjectiveValue;
	double mFitnessValue;

public:
	DESolution() = default;
	DESolution(size_t size);

	DESolution(DESolution const& other) = default;
	DESolution& operator=(const DESolution& other) = default;
	DESolution(DESolution&& other) noexcept = default;

	~DESolution() = default;

	bool isDefined();
	size_t size();
	double objectiveValue() const;
	double fitnessValue() const;
	size_t& operator[] (size_t index);
	const size_t operator[] (size_t index) const;


	void setZero();
	void setup(DEDomain const& domain);
	void randomize(DEDomain const& domain);
	void evaluate(double (*objectiveFunction)(std::vector<double>), double (*fitnessFunction)(std::vector<double>));
	DESolution operator- (DESolution solution) const;
	DESolution operator+ (DESolution solution) const;
	DESolution operator* (DESolution solution) const;
	std::string toString() const;
};

static std::string smPrefixNotation;
static std::string smSeparatorNotation;
static std::string smSuffixNotation;
static size_t smFixedNotationPrecision;
static size_t fixedNotationPrecision();
static std::string prefixNotation();
static std::string seperatorNotation();
static std::string suffixNotation();
static void setFixedNotationPrecision(size_t precision);
static void setNotationFormat(std::string& prefix, std::string& separator, std::string& suffix);

