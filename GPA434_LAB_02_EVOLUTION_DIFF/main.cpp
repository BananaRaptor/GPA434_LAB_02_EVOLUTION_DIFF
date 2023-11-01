#include "DEDomain.h"
#include "DEStatistics.h"
#include "DEPopulation.h"
#include "DEParameters.h"
#include "DifferentialEvolution.h"
#include "DESolution.h"
#include "Console.h"
#include <string>
#include <iostream>
#include <vector>

using real = double;
using FitnessFunction = std::function<real(real)>;
using ObjectiveFunction = std::function<real(DESolution const&)>;


double objectiveFunction(DESolution const& solution) {
	double test = solution[0] + (double)2.0 * solution[1] + (double)3.0 * solution[2];
	return test;
}

double fitnessFunction(double value) {
	double test =value * (double)150.000;
	return test;
}
std::string convertToString(char* a)
{
	std::string  s(a);
	return s;
}

int main() {

	DEDomain domain = DEDomain();

	domain.resize(3);

	domain.setAllIntervals(0.2, 1.8);

	domain[2].set(0, 2);

	DEParameters parameter = DEParameters(domain,100, 1,0.40, 50,  objectiveFunction, fitnessFunction);

	DifferentialEvolution de = DifferentialEvolution();
	de.setup(parameter);
	
	if (de.isReadyToEvolve()) {
		de.evolve();
	}
	std::string prefix = "La meilleure valeur est : ";
	std::string separator = " , ";
	std::string suffix = ". FINI !!!!";

	DESolution::setNotationFormat(prefix, separator, suffix);
	DESolution::setFixedNotationPrecision(3);

	std::cout << de.bestSolution().toString();

}
