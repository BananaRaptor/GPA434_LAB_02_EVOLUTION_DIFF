#pragma once


#include <cstdint>


//! \class Console
//! 
//! \brief Classe utilitaire pour interagir avec la console.
//!
//! \details Cette classe fournit plusieurs fonctions utilitaires pour 
//! faciliter l'usage de la console.
//! 
//! Elle ne peut pas être instanciée ou copiée.
class Console
{
public:
    //! \brief Constructeur par défaut supprimé.
    //! \details Empêche la création d'une instance de cette classe.
    Console() = delete;
    //! \brief Constructeur de copie supprimé.
    //! \details Empêche la copie d'une instance de cette classe.
    Console(Console const&) = delete;
    //! \brief Opérateur d'affectation supprimé.
    //! \details Empêche la copie d'une instance de cette classe.
    Console& operator=(Console const&) = delete;
    //! \brief Destructeur supprimé.
    //! \details Empêche la destruction directe d'une instance.
    ~Console() = delete;

    //! 
    //! 
    //! \brief Efface l'écran de la console.
    //! 
    //! \details Cette fonction efface tout le contenu affiché sur la console.
    //! 
    //! \code
    //! Console::clearScreen();
    //! \endcode
    static void clearScreen();
    //! 
    //! 
    //! \brief Invite l'utilisateur à appuyer sur une touche pour continuer.
    //! 
    //! \details Cette fonction met en pause l'exécution du programme jusqu'à 
    //! ce que l'utilisateur appuie sur une touche.
    //! 
    //! \code
    //! Console::pressAnyKeyToContinue();
    //! \endcode
    static void pressAnyKeyToContinue();
    //! 
    //! 
    //! \brief Vérifie si l'utilisateur souhaite quitter.
    //! 
    //! \details Demande à l'utilisateur s'il souhaite quitter ou continuer. 
    //! S'il désire quitter, il n'a qu'à appuyer sur `ESC` pour quitter ou 
    //! toutes autres touches pour poursuivre. Dans les deux cas, 
    //! l'application continue mais retourne l'information souhaitée.
    //! 
    //! \returns Vrai si l'utilisateur souhaite quitter, sinon faux.
    //! \code
    //! bool exit{ Console::wantToQuit() };
    //! \endcode
    static bool wantToQuit();
    //! 
    //! 
    //! \brief Récupère une valeur entière non signée entre min et max.
    //! 
    //! \details Cette fonction gère un nombre entre 0 et 9 (simple chiffre).
    //! 
    //! \param min La valeur minimale acceptable (bornée entre [0, 9]).
    //! \param max La valeur maximale acceptable (bornée entre [0, 9]).
    //! 
    //! \returns Un entier non signé entre min et max.
    //! 
    //! \code
    //! int value = Console::getUInt09(0, 9);
    //! \endcode
    static int getUInt09(uint8_t min, uint8_t max);
    //! 
    //! 
    //! \brief Récupère un booléen à partir de deux caractères proposés.
    //! 
    //! \param trueChar Le caractère correspondant à la valeur vraie.
    //! \param falseChar Le caractère correspondant à la valeur fausse.
    //! 
    //! \returns Vrai si l'utilisateur entre trueChar, faux si l'utilisateur 
    //! entre falseChar.
    //! 
    //! \code
    //! bool result{ Console::getBoolean('y', 'n') };
    //! \endcode
    static bool getBoolean(char trueChar, char falseChar);
};

