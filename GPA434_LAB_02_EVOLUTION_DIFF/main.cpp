#include "DEDomain.h"
#include "Console.h"
#include <string>
#include <iostream>


int main() {
	DEDomain domain = DEDomain();

	std::cout << domain.isDefined() << "\n";

	domain.resize(15);
	std::cout << std::to_string(domain[0].higher()) << "\n";
	domain.setAllIntervals(0.2, 1.8);

	domain[2].set(0, 2);

	std::cout << domain.isDefined() << "\n";

	std::cout << std::to_string(domain[0].higher()) << "\n";
	std::cout << std::to_string(domain[2].higher()) << "\n";


}