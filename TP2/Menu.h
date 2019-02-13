/*
* Titre : Menu.h - Travail Pratique #2
* Date : 10 Février 2019
* Auteurs : Nabil Dabouz(1925256) & Yassine Zarrad(1923579)
*/

#ifndef MENU_H
#define MENU_H

#include "Plat.h"
#include <fstream>

enum TypeMenu{Matin, Midi, Soir};
const int MAXPLAT = 5;
class Menu {
public:
	// constructeurs
	/**
	 * @brief Constructeur par défaut de la classe Menu
	 */
	Menu();
	/**
	 * @brief constructeur par paramètre de la classe Menu qui prend en paramètre le nom, le prix et le cout
	 * @param nom, le nom du fichier
	 * @param type, le type de menu
	 */
	Menu(string fichier, TypeMenu type);
	/**
	 * @brief constructeur par copie du restaurant
	 * @param resto,le restaurant à copier.
	 */
	Menu(const Menu& menu);

	//destructeur
	/**
	 * @brief destructeur par défaut de la classe Menu
	 */
	~Menu();

	//getters
	/**
	 * @brief donner le nombre de plats dans le menu
	 * @return le nombre de plats
	 */
	int getNbPlats() const;
	Plat* getPlat(unsigned indice) const;

	//methodes en plus
	/**
	 * @brief retourne un pointeur qui pointe vers le plat cherche
	 * @param nom, le nom du plat cherche
	 * @return pointeur vers un plat cherche
	 */
	Plat* trouverPlat(const string& nom) const;
	Plat * trouverPlatMoinsCher() const; // Utilise les vecteurs (NE PAS MODIFIER)
	/**
	 * @brief lire les plat à partir d'un fichier en fonction du type du menu
	 * * @param fichier, le nom du fichier
	 */
	bool lireMenu(const string& fichier);
	/**
	 * @brief operator<< Pour afficher un menu avec ses plats.
	 * @param o, le stream de sortie à afficher.
	 * @param menu, le menu à afficher
	 */
	friend ostream & operator<<(ostream& o, const Menu& menu);
	/**
	 * @brief operator+= pour ajouter plat au menu
	 * @param plat, le plat à ajouter
	 */
	Menu operator+=(const Plat& plat);
	/**
	 * @brief operator= pour ecraser les attributs d'un menu et les remplacées par les attributs d'un menu passé en paramètre
	 * @param menu, le menu dont on veut copier
	 */
	Menu& operator=(const Menu& menu);

private :
	vector<Plat*> listePlats_;
	TypeMenu type_;
};

#endif // !MENU_H
