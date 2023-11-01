#include "GPA434Lab2.h"



GPA434Lab2::GPA434Lab2():
	userRequestedOut{0},
	problemSolver{Solver()}
{
	mainLoop();
}
void GPA434Lab2::mainLoop()
{
	printTitle();
	Console::pressAnyKeyToContinue();
	Console::clearScreen();
	while(!userRequestedOut){
		chooseProblem();
		Console::clearScreen();
		solveProblem();
		userRequestedOut = Console::wantToQuit();
		Console::clearScreen();
	}
}

void GPA434Lab2::printTitle()
{
	std::cout << "   ______  _______     _        _    _    ______   _    _    \n";
	std::cout << " .' ___  ||_   __ \\   / \\      | |  | |  / ____ `.| |  | |   \n";
	std::cout << "/ .'   \\_|  | |__) | / _ \\     | |__| |_ `'  __) || |__| |_  \n";
	std::cout << "| |   ____  |  ___/ / ___ \\    |____   _|_  |__ '.|____   _| \n";
	std::cout << "\\ `.___]  |_| |_  _/ /   \\ \\_      _| |_| \\____) |    _| |_  \n";
	std::cout << " `._____.'|_____||____| |____|    |_____|\\______.'   |_____| \n";
	std::cout << "                                                             \n";
	std::cout << "                                                             \n";
	std::cout << "Laboratoire 2 - Evolution Differentiel\n";
}

void GPA434Lab2::chooseProblem()
{
	std::cout << "Selectionner le problme a resoudre\n";
	std::cout << "		-1- Probleme de la boite ouverte\n";
	std::cout << "		-2- Identifier les extremum de la contion peak de matlab\n";
	std::cout << "		-3- Ajustement des donnees par un cercle\n";

	int choice = Console::getUInt09(1,3);

	switch (choice)
	{
	case 1 : 
		problemSolver = OpenBoxSolver();
	default:
		break;
	}
}

void GPA434Lab2::solveProblem()
{
	std::cout << problemSolver.problemPresentation();
	std::cout << " Resolution en cours     ";
	problemSolver.solve();
	std::cout << " Reslution Termine \n ";
	std::cout << problemSolver.bestSolution().toString();
}
