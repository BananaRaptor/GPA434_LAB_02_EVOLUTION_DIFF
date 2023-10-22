#include "OpenBoxProblem.h"



std::string const OpenBoxProblem::smTitle("Probleme de la boite ouverte");
std::string const OpenBoxProblem::smProblemSummary(
R".(Trouver les dimensions de la decoupe qui maximisent le volume d'une boite ouverte formee
a partir d'une feuille de carton rectangulaire.).");
std::string const OpenBoxProblem::smProblemDescription(
R".(Le probleme de la boite ouverte concerne une feuille de carton rectangulaire, a partir de 
laquelle on decoupe des carres identiques à chaque coin.

En pliant ensuite le carton le long des bords des decoupes, on forme une boite sans couvercle. 
L'objectif est de determiner la taille de la decoupe qui permettra d'obtenir le volume maximal
pour cette boîte ouverte.

Pour ce probleme, on suppose que feuille de carton a une dimension de 100 x 50.).");
std::string const OpenBoxProblem::smExpectedSolution(
R".(La taille de la coupe optimale est 10.5662432702594...).");

double const OpenBoxProblem::smBoxWidth{ 100.0 };
double const OpenBoxProblem::smBoxHeight{ 50.0 };

OpenBoxProblem::OpenBoxProblem()
    : ProblemToSolve(smTitle, smProblemSummary, smProblemDescription, smExpectedSolution)
{
}

double OpenBoxProblem::boxWidth()
{
    return smBoxWidth;
}

double OpenBoxProblem::boxHeight()
{
    return smBoxHeight;
}
