#pragma once
#include <vector>
#include "Interval.h"

class DEDomain
{
private:
	std::vector<Interval> mInterval;

public:

	DEDomain() = default;

	DEDomain(DEDomain const& other) = default;
	DEDomain& operator=(const DEDomain& other) = default;
	DEDomain(DEDomain&& other) noexcept = default;

	~DEDomain() = default;

	bool isDefined() const;
	size_t size() const;
	void resize(size_t size);
	void setAllIntervals(double lower, double higher);
	Interval& operator[] (size_t index);
	const Interval& operator[] (size_t index) const;
};

 