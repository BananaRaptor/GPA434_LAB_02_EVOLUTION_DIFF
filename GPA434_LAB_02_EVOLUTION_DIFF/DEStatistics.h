#pragma once
#include <vector>
#include "DESolution.h"

class DEStatistics
{
private:
	std::vector<DESolution> mStatistics;

public:
	DEStatistics() = default;

	DEStatistics(DEStatistics const& other) = default;
	DEStatistics& operator=(const DEStatistics& other) = default;
	DEStatistics(DEStatistics&& other) noexcept = default;

	~DEStatistics() = default;

	size_t size() const;

	DESolution& operator[] (size_t index);
	DESolution bestSolution() const;
	void add(DESolution const& solution);
	void reset();

};

