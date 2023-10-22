#pragma once


//! \class Fitness
//! 
//! \brief Classe utilitaire offrant différentes fonctions de fitness.
//!
//! \details Cette classe fournit quelques fonctions statiques pour différentes 
//! transformations de fitness couramment utilisées. 
//! 
//! Elle ne peut pas être instanciée ou copiée.
class Fitness
{
public:
	//! \brief Constructeur par défaut supprimé.
	//! \details Empêche la création d'une instance de cette classe.
	Fitness() = delete;
	//! \brief Constructeur de copie supprimé.
	//! \details Empêche la copie d'une instance de cette classe.
	Fitness(Fitness const&) = delete;
	//! \brief Opérateur d'affectation supprimé.
	//! \details Empêche la copie d'une instance de cette classe.
	Fitness& operator=(Fitness const&) = delete;
	//! \brief Destructeur supprimé.
	//! \details Empêche la destruction directe d'une instance.
	~Fitness() = delete;
	//! 
	//! 
	//! \brief Fonction d'identité pour la valeur de fitness.
	//! 
	//! \details Renvoie la valeur de fitness telle quelle.
	//! 
	//! \param value La valeur de fitness à traiter.
	//! 
	//! \returns La même valeur de fitness.
	//! 
	//! \code
	//! FitnessFunction fitness{ Fitness::identity };
	//! double result { fitness(0.5) }; // result = 0.5
	//! \endcode
	static double identity(double value);
	//! 
	//! 
	//! \brief Fonction d'inversion pour la valeur de fitness.
	//! 
	//! \details Renvoie l'inverse de la valeur de fitness.
	//! Si la valeur est 0, retourne 0.
	//! 
	//! \param value La valeur de fitness à inverser.
	//! 
	//! \returns L'inverse de la valeur de fitness.
	//! 
	//! \code
	//! FitnessFunction fitness{ Fitness::inverse };
	//! double result { fitness(2.0) }; // result = 0.5
	//! \endcode
	static double inverse(double value);
	//! 
	//! 
	//! \brief Fonction d'opposition pour la valeur de fitness.
	//! 
	//! \details Renvoie l'opposé de la valeur de fitness.
	//! 
	//! \param value La valeur de fitness à traiter.
	//! 
	//! \returns L'opposé de la valeur de fitness.
	//! 
	//! \code
	//! FitnessFunction fitness{ Fitness::opposite };
	//! double result { fitness(-10.0) }; // result = 10.0
	//! \endcode
	static double opposite(double value);
};