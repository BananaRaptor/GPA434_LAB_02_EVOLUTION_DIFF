#include "DEStatistics.h"

size_t DEStatistics::size() const
{
    return mStatistics.size();
}

DESolution& DEStatistics::operator[](size_t index)
{
    return mStatistics.at(index);
}

DESolution DEStatistics::bestSolution() const
{
    DESolution bestValue = DESolution();

    for (size_t i = 0; i < mStatistics.size(); i++)
    {
        if (mStatistics.at(i).fitnessValue() > bestValue.fitnessValue()) {
            bestValue = mStatistics.at(i);
        }
    }

    return bestValue;
}

DESolution DEStatistics::secondBestSolutionWithOppositeValue(DESolution bestSolution) const
{
    DESolution bestValue = DESolution();

    for (size_t i = 0; i < mStatistics.size(); i++)
    {
        if (mStatistics.at(i).fitnessValue() > bestValue.fitnessValue() && (bestSolution.objectiveValue() < 0) != (mStatistics.at(i).objectiveValue() < 0)) {
            bestValue = mStatistics.at(i);
        }
    }

    return bestValue;
}

void DEStatistics::add(DESolution const& solution)
{
   mStatistics.push_back(solution);
}

void DEStatistics::reset()
{
    mStatistics.clear();
}
