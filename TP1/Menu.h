/*
* Titre : Menu.h - Travail Pratique #1
* Date : 09 Janvier 2019
* Auteur : David Dratwa
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
	Menu(); 
	/**
	 * @brief Constructeur par défaut de la classe Menu
	 */
	Menu(string fichier, TypeMenu type); 
	/**
	 * @brief constructeur par paramètre de la classe Menu qui prend en paramètre le nom, le prix et le cout
	 * @param nom, le nom du fichier
	 * @param type, le type de menu

	 */

	// destructeur
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
	
	//affichage 
	/**
	 * @brief afficher un menu avec ses plats
	 */
	void afficher() const; 

	//methodes en plus
	/**
	 * @brief retourne un pointeur qui pointe vers le plat cherche
	 * @param nom, le nom du plat cherche
	 * @return pointeur vers un plat cherche
	 */
	Plat* trouverPlat(string& nom) const; 
	/**
	 * @brief ajoute un plat existant à la liste des plats
	 * @param plat, le plat à ajouter

	 */
	void ajouterPlat(Plat & plat); 
	/**
	 * @brief crée un plat et l'ajoute à la liste des plats
	 * @param plat, le plat à ajouter
	 * @param nom, le nom du plat
	 * @param prix, le prix du plat
	 * @param cout, le cout d'un plat

	 */
	void ajouterPlat(string& nom, double montant, double cout); 
	/**
	 * @brief lire les plat à partir d'un fichier en fonction du type du menu
	 * * @param fichier, le nom du fichier
	 */
	bool lireMenu(string& fichier); 
	
private : 
	unsigned int capacite_;
	Plat** listePlats_;  
	unsigned int nbPlats_; 
	TypeMenu type_; 

};

#endif // !MENU_H
