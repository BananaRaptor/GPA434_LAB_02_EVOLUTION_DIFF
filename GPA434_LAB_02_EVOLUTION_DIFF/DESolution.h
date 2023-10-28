#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <format>
#include "DEDomain.h"
#include "DEDomain.h"

class DESolution
{
using real = double;
private:
	std::vector<real> mData;
	real mObjectiveValue;
	real mFitnessValue;
	static std::string smPrefixNotation;
	static std::string smSeparatorNotation;
	static std::string smSuffixNotation;
	static size_t smFixedNotationPrecision;

public:
	DESolution() = default;
	DESolution(size_t size);

	DESolution(DESolution const& other) = default;
	DESolution& operator=(const DESolution& other) = default;
	DESolution(DESolution&& other) noexcept = default;

	~DESolution() = default;

	bool isDefined();
	size_t size();
	real objectiveValue() const;
	real fitnessValue() const;
	size_t& operator[] (size_t index);
	const size_t operator[] (size_t index) const;


	void setZero();
	void setup(DEDomain const& domain);
	void randomize(DEDomain const& domain);
	void evaluate(real (*objectiveFunction)(std::vector<real>), real (*fitnessFunction)(std::vector<real>));
	DESolution operator- () const;
	DESolution operator- (DESolution solution) const;
	DESolution operator+ (DESolution solution) const;
	DESolution operator* (DESolution solution) const;
	std::string toString() const;

	static size_t fixedNotationPrecision();
	static std::string prefixNotation();
	static std::string seperatorNotation();
	static std::string suffixNotation();
	static void setFixedNotationPrecision(size_t precision);
	static void setNotationFormat(std::string& prefix, std::string& separator, std::string& suffix);

	friend DESolution operator*(real lhs, DESolution const& rhs);
	friend std::ostream& operator<<(std::ostream& lhs, DESolution const& rhs);
};




