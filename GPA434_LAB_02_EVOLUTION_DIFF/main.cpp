#include "DEDomain.h"
#include "DEStatistics.h"
#include "DEPopulation.h"
#include "Console.h"
#include <string>
#include <iostream>
#include <vector>

double objectiveFunction(std::vector<double> value) {
	return value.at(0) + 2 * value.at(1) + 3 * value.at(2);
}

double fitnessFunction(std::vector<double> value) {
	return value[0] / 2;

}

int main() {
	DEDomain domain = DEDomain();

	std::cout << domain.isDefined() << "\n";

	domain.resize(3);

	domain.setAllIntervals(0.2, 1.8);

	domain[2].set(0, 2);

	DEPopulation test;

	test.setup(domain.size(), domain);

	test.randomize(domain);

	for (size_t i = 0; i < test.size(); i++)
	{
		test[i].evaluate(objectiveFunction, fitnessFunction);
	}
	std::cout << test.bestSolution().objectiveValue() << " test done";


}
