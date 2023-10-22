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
        if (mStatistics.at(i).objectiveValue() > bestValue.objectiveValue()) {
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
