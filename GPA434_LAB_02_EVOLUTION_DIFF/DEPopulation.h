#pragma once
#include "DESolution.h"
#include "DEDomain.h"
#include <vector>
#include <string>
#include <iostream>


class DEPopulation
{
private:
	std::vector<DESolution> mData;
		
public : 
	DEPopulation() = default;

	DEPopulation(DEPopulation const& other) = default;
	DEPopulation& operator=(const DEPopulation& other) = default;
	DEPopulation(DEPopulation&& other) = default;

	~DEPopulation() = default;

	DESolution bestSolution() const;
	size_t size() const;

	DESolution& operator[] (size_t index);
	const DESolution operator[] (size_t index) const;

	void setup(size_t size, DEDomain const& domain);
	void randomize(DEDomain const& domain);
};

