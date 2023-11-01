#include "DEDomain.h"

bool DEDomain::isDefined() const
{
	return !mInterval.empty();
}

size_t DEDomain::size() const
{
	return mInterval.size();
}

void DEDomain::resize(size_t size)
{
	mInterval.resize(size);
}

void DEDomain::setAllIntervals(double lower, double higher)
{
	for (size_t i = 0; i < mInterval.size() ; i++ )
	{
		mInterval[i].set(lower, higher);
	}
}

Interval& DEDomain::operator[](size_t index)
{
	return mInterval.at(index);
}

const Interval& DEDomain::operator[](size_t index) const
{
	return mInterval.at(index);
}
