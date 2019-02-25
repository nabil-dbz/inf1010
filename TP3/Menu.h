/*
* Titre : Menu.h - Travail Pratique #2
* Date : 25 Février 2019
* Auteur : Nabil Dabouz(1925256) & Yassine Zarrad(1923579)
*/

#ifndef MENU_H
#define MENU_H 

#include <fstream>
#include <vector>
#include"PlatBio.h"



enum TypeMenu{Matin, Midi, Soir};

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
		  * @brief constructeur par copie du Menu
		  * @param menu,le menu à copier.
		  */
	Menu(const Menu& menu); 


	//getters
	/**
	 * @brief retourne la liste de plats d un menu
	 * @return le vecteur des plats
	 */
	vector<Plat*> getListePlats() const; 
	
	//methodes en plus
	/**
	 * @brief retourne un pointeur qui pointe vers le plat cherche
	 * @param nom, le nom du plat cherche
	 * @return pointeur vers un plat cherche
	 */
	Plat* trouverPlat(const string& nom) const; 
	/**
	 * @brief operator+= pour ajouter plat au menu
	 * @param plat, le plat à ajouter
	 */
	Menu& operator+=(const Plat& plat);
	/**
	 * @brief operator+= pour ajouter platBio au menu
	 * @param plat, le platBio à ajouter
	 */
	Menu& operator+=(const PlatBio& plat); 
	/**
	 * @brief operator= pour ecraser les attributs d'un menu et les remplacées par les attributs d'un menu passé en paramètre
	 * @param menu, le menu dont on veut copier
	 */
	Menu& operator=(const Menu& menu); 
	/**
	* @brief lire les plat à partir d'un fichier en fonction du type du menu
	* @param fichier, le nom du fichier
	*/
	void lireMenu(const string& fichier); 
	/**
	 * @brief retourne un pointeur qui pointe vers le plat le moins cher
	 * @return pointeur vers le plat le moins cher
	 */
	Plat* trouverPlatMoinsCher() const;
	/**
	 * @brief operator<< Pour afficher un menu avec ses plats.
	 * @param o, le stream de sortie à afficher.
	 * @param menu, le menu à afficher
	 */
	friend ostream& operator<<(ostream& os, const Menu& menu); 
	
private : 
	vector<Plat*> listePlats_; 
	TypeMenu type_; 

};

#endif // !MENU_H
