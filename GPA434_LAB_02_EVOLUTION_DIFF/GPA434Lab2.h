#pragma once
#include <String>
#include <iostream>
#include "Console.h"
#include "Solver.h"
#include "OpenBoxSolver.h"
#include "ExtremumSolver.h"
#include "CircleSolver.h"
#include "ProblemToSolve.h"
#include "Fitness.h"

class GPA434Lab2
{
private:
	bool userRequestedOut;
	Solver problemSolver;


	void mainLoop();
	void printTitle();
	void chooseProblem();
	void solveProblem();


public :
	GPA434Lab2();
	~GPA434Lab2() = default;
};

