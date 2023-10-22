#include "DESolution.h"

DESolution::DESolution(size_t size)
{
	mData.resize(size);
}

bool DESolution::isDefined()
{
	return !mData.empty();
}

size_t DESolution::size()
{
	return mData.size();
}

double DESolution::objectiveValue()
{
	return mObjectiveValue;
}

double DESolution::fitnessValue()
{
	return mFitnessValue;
}

size_t DESolution::operator[](size_t index)
{
	return mData.at(index);
}

const size_t& DESolution::operator[](size_t index) const
{
	return mData.at(index);
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

void DESolution::evaluate(double(*objectiveFunction)(std::vector<double>), double(*fitnessFunction)(std::vector<double>))
{
	mObjectiveValue = objectiveFunction(mData);
	mFitnessValue = fitnessFunction(mData);
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
	//TODO : 
	return smPrefixNotation ;
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
