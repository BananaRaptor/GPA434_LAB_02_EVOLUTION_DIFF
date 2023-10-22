#include "DESolution.h"

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

double DESolution::objectiveValue() const
{
	return mObjectiveValue;
}


double DESolution::fitnessValue() const
{
	return mFitnessValue;
}

size_t& DESolution::operator[](size_t index)
{
	size_t temp = mData.at(index);
	return temp;
}



const size_t DESolution::operator[](size_t index) const
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

size_t fixedNotationPrecision()
{
	return smFixedNotationPrecision;
}

std::string prefixNotation()
{
	return smPrefixNotation;
}

std::string seperatorNotation()
{
	return smSeparatorNotation;
}

std::string suffixNotation()
{
	return smSuffixNotation;
}

void setFixedNotationPrecision(size_t precision)
{
	smFixedNotationPrecision = precision;
}

void setNotationFormat(std::string& prefix, std::string& separator, std::string& suffix)
{
	smPrefixNotation = prefix;
	smSeparatorNotation = separator;
	smSuffixNotation = suffix;
}
