#pragma once
#ifndef _THREE_SAMPLE_WITH_ONE_EXCLUSION_H_
#define _THREE_SAMPLE_WITH_ONE_EXCLUSION_H_


#include <vector>
#include <random>


//! \class ThreeSamplesWithOneExclusion
//! 
//! \brief Classe pour échantillonner trois indexes distincts avec une 
//! exclusion.
//!
//! \details Cette classe est conçue pour échantillonner trois indexes 
//! distincts d'un ensemble, tout en excluant un index spécifique. Elle 
//! encapsule un algorithme spécifique et n'est pas conçue pour être 
//! générique.
//! 
//! La classe travaille exclusivement avec des indexes (entier) et est 
//! indépendante de la source de données. Elle ne fait pas usage de 
//! pointeurs, de références ou d'itérateurs.
//! 
//! Utilisation typique :
//! \code
//! const size_t populationSize{ 100 };
//! std::vector<DESolution> population(populationSize);
//! ThreeSamplesWithOneExclusion samplingTool;
//!
//! samplingTool.prepare(populationSize);
//!
//! size_t solutionIndex0, solutionIndex1, solutionIndex2;
//! for (int i{}; i < populationSize; ++i) {
//!     samplingTool.select(i, solutionIndex0, solutionIndex1, solutionIndex2);
//!		// les variables solutionIndex0, solutionIndex1, solutionIndex2 ont été 
//!		// modifiées et sont maintenant utilisables.
//!     // Vous pouvez les utiliser ainsi par exemple :
//!		//    population[solutionIndex0]...
//!		//    population[solutionIndex1]...
//!		//    population[solutionIndex2]...
//! }
//! \endcode
class ThreeSamplesWithOneExclusion
{
public:
	//!
	//! \brief Constructeur par défaut.
	ThreeSamplesWithOneExclusion() = default;			
	//!
	//! \brief Constructeur avec taille de source.
	//! \details Prépare l'engin d'échantillonnage.
	//! \param sourceSize La taille du vecteur à échantillonner.
	ThreeSamplesWithOneExclusion(size_t sourceSize);
	//!
	//! \brief Constructeur de copie.// default constructor
	ThreeSamplesWithOneExclusion(ThreeSamplesWithOneExclusion const &) = default;
	//!
	//! \brief Opérateur d'affectation par copie.
	ThreeSamplesWithOneExclusion& operator=(ThreeSamplesWithOneExclusion const &) = default;
	//!
	//! \brief Destructeur.
	~ThreeSamplesWithOneExclusion() = default;
	//! 
	//! 
	//! \brief Prépare l'outil d'échantillonnage.
	//! 
	//! \details Doit obligatoirement être appelé au moins une fois avant 
	//! d'utiliser la fonction select.
	//! 
	//! \param sourceSize La taille du vecteur à échantillonner.
	//! 
	//! \returns Vrai si la préparation a réussi, sinon faux.
	bool prepare(size_t sourceSize);
	//! 
	//! 
	//! \brief Sélectionne trois échantillons distincts.
	//! 
	//! \details Renvoie trois indexes différents les uns des autres et 
	//! différents de l'index exclu.
	//! 
	//! La fonction prepare doit absolument avoir été exécutée une fois avant la 
	//! fonction select.
	//! 
	//! \param excludedIndex L'index à exclure.
	//! \param sample0 Référence vers l'index du premier échantillon.
	//! \param sample1 Référence vers l'index du deuxième échantillon.
	//! \param sample2 Référence vers l'index du troisième échantillon.
	//! 
	//! \returns Vrai si la sélection a réussi, sinon faux.
	bool select(size_t exludedIndex, size_t & sample0, size_t & sample1, size_t & sample2);

private:
	std::default_random_engine mEngine; //!< Moteur pour la génération aléatoire.
	std::vector<size_t> mSource; //!< Source d'indexes pour l'échantillonnage.
};


#endif // _THREE_SAMPLE_WITH_ONE_EXCLUSION_H_
