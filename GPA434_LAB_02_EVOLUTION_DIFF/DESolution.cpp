#include "DESolution.h"
using real = double;
#include <string>

size_t DESolution::smFixedNotationPrecision = 2;
std::string DESolution::smPrefixNotation = "Valeur : ";
std::string DESolution::smSeparatorNotation  = " , ";
std::string DESolution::smSuffixNotation = " . ";


DESolution::DESolution(size_t size)
{
	mData.resize(size);
	mFitnessValue = 0;
	mObjectiveValue = 0;
	setZero();
}

bool DESolution::isDefined()
{
	return !mData.empty();
}

size_t DESolution::size()
{
	return mData.size();
}

real DESolution::objectiveValue() const
{
	return mObjectiveValue;
}


real DESolution::fitnessValue() const
{
	return mFitnessValue;
}

real& DESolution::operator[](size_t index)
{
	return mData.at(index);
}



const real DESolution::operator[](size_t index) const
{
	return mData.at(index);
}
 

void DESolution::setZero()
{
	for (size_t i = 0; i < mData.size(); i++)
	{
		mData[i] = 0;
	}
}

void DESolution::setup(DEDomain const& domain)
{
	mData.resize(domain.size());
	for (size_t i = 0; i < mData.size(); i++)
	{
		mData[i] = domain[i].lower();
	}
}

void DESolution::randomize(DEDomain const& domain)
{
	for (size_t i = 0; i < mData.size(); i++)
	{
		mData[i] = domain[i].randomValue();
	}
}

void DESolution::evaluate(DESolution::ObjectiveFunction objectiveFunction, DESolution::FitnessFunction fitnessFunction)
{
	double aaaaa = objectiveFunction(*this);
	mObjectiveValue = aaaaa;
	mFitnessValue = fitnessFunction(mObjectiveValue);
}

DESolution DESolution::operator-() const
{
	DESolution temp = DESolution(mData.size());

	for (size_t i = 0; i < mData.size(); i++)
	{
		temp[i];
		temp[i] = -mData[i];
	}

	return temp;
}

DESolution DESolution::operator-(DESolution solution) const
{
	DESolution temp = DESolution(solution.size());

	for (size_t i = 0; i < mData.size(); i++)
	{
		temp[i];
		temp[i] = mData[i] - solution[i];
	}

	return temp;
}

DESolution DESolution::operator+(DESolution solution) const
{
	DESolution temp = DESolution(solution.size());

	for (size_t i = 0; i < mData.size(); i++)
	{
		temp[i];
		temp[i] = mData[i] + solution[i];
	}

	return temp;
}

DESolution DESolution::operator*(DESolution solution) const
{
	DESolution temp = DESolution(solution.size());

	for (size_t i = 0; i < mData.size(); i++)
	{
		temp[i];
		temp[i] = mData[i] * solution[i];
	}

	return temp;
}

std::string DESolution::toString() const
{
	std::string test = smPrefixNotation;
	for (real data : mData)
	{
		test += std::to_string(data) + smSeparatorNotation;
	}
	return test + smSuffixNotation;
}

size_t DESolution::fixedNotationPrecision()
{
	return smFixedNotationPrecision;
}

std::string DESolution::prefixNotation()
{
	return smPrefixNotation;
}

std::string DESolution::seperatorNotation()
{
	return smSeparatorNotation;
}

std::string DESolution::suffixNotation()
{
	return smSuffixNotation;
}

void DESolution::setFixedNotationPrecision(size_t precision)
{
	smFixedNotationPrecision = precision;
}

void DESolution::setNotationFormat(std::string& prefix, std::string& separator, std::string& suffix)
{
	smPrefixNotation = prefix;
	smSeparatorNotation = separator;
	smSuffixNotation = suffix;
}
DESolution operator*(real lhs, DESolution const& rhs)
{
	DESolution temp = rhs;
	for (size_t i = 0; i < rhs.mData.size(); i++)
	{
		temp.mData[i] = rhs.mData[i] * lhs;
	}
	return temp;
}
std::ostream& operator<<(std::ostream& lhs, DESolution const& rhs)
{
	 lhs << rhs.toString();
	 return lhs;
}

