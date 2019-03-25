/*
* Date : 25 février 2019
* Auteur : AbdeB
*/

#ifndef MENU_H
#define MENU_H 

#include "Plat.h"
#include "PlatBio.h"
#include "PlatBioVege.h"
#include "PlatVege.h"
#include "pointers.h"
#include "def.h"
#include <fstream>
#include <vector>

using std::vector;  //? On ne devrait normalement pas faire de "using" global dans un .h, mais c'est accepté en INF1010.

class Menu {
public: 
	// Constructeurs.
	Menu(); 
	Menu(string fichier, TypeMenu type);
	/**
	 * @brief constructeur par copie du Menu
	 * @param menu,le menu à copier.
	 */
	 
	Menu(const Menu& menu);
	/**
	 * @brief destructeur de la classe menu
	 */

	~Menu();
	// Getters.

	vector<Plat*> getListePlats() const;

	// Autres méthodes.

	Plat* trouverPlat(string_view nom) const;
    Plat* allouerPlat(Plat* plat);
	/**
	 * @brief operator+= pour ajouter plat au menu
	 * @param plat, le plat à ajouter
	 */
	Menu& operator+=(owner<Plat*> plat);  //? Le parametre est indique "owner" pour montrer que cette methode prend possession du pointeur qui lui est passe, mais owner<Plat*> est equivalent à Plat*; voir pointers.h .
	
/**
	 * @brief operator= pour ecraser les attributs d'un menu et les remplacées par les attributs d'un menu passé en paramètre
	 * @param menu, le menu dont on veut copier
	 */

	Menu& operator=(const Menu& menu); 
	void lireMenu(const string& fichier); 
	Plat* trouverPlatMoinsCher() const;
    Plat* lirePlatDe(LectureFichierEnSections& fichier);
	
/**
	 * @brief operator<< Pour afficher un menu avec ses plats.
	 * @param os, le stream de sortie à afficher.
	 * @param menu, le menu à afficher
	 */
	friend ostream& operator<<(ostream& os, const Menu& menu); 

private : 
	vector<owner<Plat*>> listePlats_; //? "owner" est juste un indicateur que la classe est propriétaire des plats (et devra faire un "delete"), mais owner<Plat*> est équivalent à Plat*; voir pointers.h .
	vector<Vege*> listePlatsVege_;

	TypeMenu type_;
};

#endif // !MENU_H
