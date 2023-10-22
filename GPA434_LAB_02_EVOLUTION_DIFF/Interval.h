#pragma once
#include <algorithm>
#include "Random.h"

class Interval
{
private:
	double mLower;
	double mHigher;

public:
	Interval();
	Interval(double lower, double higher);

	Interval(Interval const& other) = default;
	Interval& operator=(const Interval& other) = default;
	Interval(Interval&& other) noexcept = default;

	~Interval() = default;

	double lower() const;
	double higher() const;
	bool contain(double value) const;

	double randomValue() const;
	void setLower(double lower);
	void setHigher(double higher);
	void set(double lower, double higher);

};

