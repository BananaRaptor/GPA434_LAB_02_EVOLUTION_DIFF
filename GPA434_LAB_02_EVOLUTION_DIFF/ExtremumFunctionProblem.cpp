#include "ExtremumFunctionProblem.h"


std::string const ExtremumFunctionProblem::smTitle("Probleme des extremums");
std::string const ExtremumFunctionProblem::smProblemSummary(
R".(Identifier les extremums de la fonction peak de Matlab.).");
std::string const ExtremumFunctionProblem::smProblemDescription(
R".(On cherche a determiner les deux endroits ou la fonction peak de Matlab atteint ses valeurs
minimum et maximum.

Pour ce probleme, on considerant exclusivement l'intervalle [-3, 3][-3, 3], ).");
std::string const ExtremumFunctionProblem::smExpectedSolution(
R".(Les coordonnees attendues sont approximativement :
 - minimum : ( 0.2350..., -1.6200..., -6.5511...)
 - maximum : (-0.0050...,  1.5850...,  8.1062...)).");

ExtremumFunctionProblem::ExtremumFunctionProblem()
    : ProblemToSolve(smTitle, smProblemSummary, smProblemDescription, smExpectedSolution)
{
}

double ExtremumFunctionProblem::peak(double x, double y)
{
    // from : https://www.mathworks.com/help/matlab/ref/peaks.html
    // 
    // The peaks function is useful for demonstrating graphics functions, 
    // such as contour, mesh, pcolor, and surf. It is obtained by 
    // translating and scaling Gaussian distributions and is defined as :
    // 
    // z = 3 * (1 - x). ^ 2. * exp(-(x. ^ 2) - (y + 1). ^ 2) ...
    //     - 10 * (x / 5 - x. ^ 3 - y. ^ 5).*exp(-x. ^ 2 - y. ^ 2) ...
    //     - 1 / 3 * exp(-(x + 1). ^ 2 - y. ^ 2)
    //
    return 3.0 * pow(1.0 - x, 2.0) * exp(-(x * x) - pow(y + 1.0, 2.0))
        - 10.0 * (x / 5.0 - pow(x, 3.0) - pow(y, 5.0)) * exp(-(x * x) - (y * y))
        - 1.0 / 3.0 * exp(-pow(x + 1.0, 2.0) - (y * y));
}

