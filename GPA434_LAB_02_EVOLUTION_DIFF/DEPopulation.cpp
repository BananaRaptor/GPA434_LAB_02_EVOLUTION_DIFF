#include "DEPopulation.h"

DESolution DEPopulation::bestSolution() const
{
    DESolution tempValue;
    tempValue = DESolution(size());
    for (size_t i = 0; i < mData.size(); i++)
    {
        if (mData.at(i).fitnessValue() > tempValue.fitnessValue()) {
            tempValue = mData.at(i);
        }
    }
    DESolution bestValue = tempValue;
    return bestValue;
}

size_t DEPopulation::size() const
{
    return mData.size();
}

DESolution& DEPopulation::operator[](size_t index)
{
    return mData.at(index);
}

const DESolution DEPopulation::operator[](size_t index) const
{
    return mData.at(index);
}

void DEPopulation::setup(size_t size, DEDomain const& domain)
{
    mData.resize(size);
    for (size_t i = 0; i < mData.size(); i++)
    {
        mData.at(i).setup(domain);
    }
    
}

void DEPopulation::randomize(DEDomain const& domain)
{
    for (size_t i = 0; i < mData.size(); i++)
    {
        mData.at(i).randomize(domain);
    }
}
