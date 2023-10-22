#include "CircleFittingProblem.h"


std::array<std::array<double, 2>, 50> const CircleFittingProblem::dataPoints(
    { { 11.120987830,  4.522575631 },
      {  2.110487908,  3.153495704 },
      {  7.898746517,  7.153017065 },
      {  7.025974307, -2.812755718 },
      {  5.807858371,  6.755866086 },
      {  3.336228076,  4.652803896 },
      {  4.703049918, -1.858065817 },
      { 11.230043170,  1.408696043 },
      { 11.084102020, -0.914220874 },
      { 11.046858600, -1.605261286 },
      {  5.543042630, -3.510361480 },
      {  6.360960534, -2.209512778 },
      { 10.035663780, -2.376885041 },
      {  9.552853420,  0.679587803 },
      {  2.098116220,  4.252214365 },
      {  4.385924879, -1.402380704 },
      {  8.803466034,  6.216437698 },
      { 11.435577580,  0.581051560 },
      {  2.256083616,  4.120385628 },
      {  2.427641252,  4.335285391 },
      { 10.665713840,  4.255621319 },
      {  7.815548262, -2.890491459 },
      {  6.684003625, -3.536916468 },
      {  6.260136307, -2.257872252 },
      {  5.738771741,  6.335848475 },
      { 12.108172760,  3.304226267 },
      {  3.439160593,  4.587335651 },
      {  2.660732066,  0.410688040 },
      { 11.963179960,  2.371789737 },
      {  9.881120989, -2.772871128 },
      { 12.142877540, -0.082870789 },
      {  3.044194730,  4.575698223 },
      {  2.055372539,  2.770085850 },
      { 11.619015350,  1.442691605 },
      { 11.407975150, -1.327380570 },
      {  1.722699796, -0.277842064 },
      {  1.733489102,  2.523214044 },
      {  1.591123204,  0.934071563 },
      {  9.278084128, -2.757975548 },
      {  6.622775356,  6.697848157 },
      {  5.973383241,  7.645228879 },
      {  4.492354128, -1.698048304 },
      {  6.502141016,  6.820308399 },
      {  7.791174411,  7.375261111 },
      { 11.283306380, -0.102600394 },
      {  9.815075248, -2.140222849 },
      {  2.244317427,  2.052064536 },
      { 10.982269800, -1.467762156 },
      { 11.193820070,  1.013719655 },
      { 11.590109860,  2.815260642 } });


std::string const CircleFittingProblem::smTitle("Probleme de l'ajustement d'un cercle");
std::string const CircleFittingProblem::smProblemSummary(
R".(Adapter une courbe circulaire a un nuage de points disperses.).");
std::string const CircleFittingProblem::smProblemDescription(
R".(Considerant un ensemble de points dans un espace bidimensionnel, le probleme consiste a determiner 
les parametres d'un cercle de telle sorte que ce cercle represente le mieux possible la distribution 
de ces points. 

L'objectif est d'obtenir un cercle dont la distance globale entre lui et l'ensemble des points est 
minimisee, tout en prenant en compte que tous les points ne se situeront pas parfaitement sur le cercle 
en raison de possibles bruits ou erreurs dans les donnees.

Pour ce probleme, vous avez un nuage de 50 points.).");
std::string const CircleFittingProblem::smExpectedSolution(
R".(Le cercle theorique sans bruit est centre en (7.0, 2.0) avec une rayon de 5.0.).");


CircleFittingProblem::CircleFittingProblem()
    : ProblemToSolve(smTitle, smProblemSummary, smProblemDescription, smExpectedSolution)
{
}
