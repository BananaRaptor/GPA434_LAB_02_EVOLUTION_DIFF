#include "Interval.h"

Interval::Interval() :
	Interval(0.0, 1.0)
{
}

Interval::Interval(double lower, double higher)
{
	set(lower, higher);
}

double Interval::lower() const
{
	return mLower;
}

double Interval::higher() const
{
	return mHigher;
}

bool Interval::contain(double value) const
{
	return mLower <= value && value	<= mHigher;
}

double Interval::randomValue() const
{
	return Random::real(mLower,mHigher);
}

void Interval::setLower(double lower)
{
	set(lower, mHigher);
}

void Interval::setHigher(double higher)
{
	set(mLower, higher);
}

void Interval::set(double lower, double higher)
{
	mLower = std::min(lower, higher);
	mHigher = std::max(lower, higher);
}
