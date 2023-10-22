#include "DEDomain.h"
#include "DEStatistics.h"
#include "Console.h"
#include <string>
#include <iostream>
#include <vector>

int main() {
	DEDomain domain = DEDomain();

	std::cout << domain.isDefined() << "\n";

	domain.resize(3);

	domain.setAllIntervals(0.2, 1.8);

	domain[2].set(0, 2);



}

double objectiveFunction(std::vector<double> value ) {
	return value[0] + 2 * value[1] + 3 * value[3];
}

double fitnessFunction(std::vector<double> value) {
	return value[0] / 2;

}