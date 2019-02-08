/*
* Titre : Restaurant.h - Travail Pratique #1
* Date : 09 Janvier 2019
* Auteur : David Dratwa
*/

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Table.h"
const int INTTABLES = 6;
class Restaurant {
public: 
	//constructeurs 
	/**
	 * @brief Constructeur par défaut de la classe Restaurant
	 */
	Restaurant(); 
	/**
	 * @brief constructeur par paramètre de la classe Restaurant qui prend en paramètre le nom, le prix et le cout
	 * @param fichier, le nom du fichier
	 * @param nom, le nom du restaurant
	 * @param type, le type de menu

	 */
	Restaurant(string& fichier, string& nom,  TypeMenu moment); 

	//destructeur
	/**
	 * @brief destructeur par défaut de la classe Restaurant
	 */
	~Restaurant();
	
	//setters 
	/**
	 * @brief mettre le type de menu
	 * @param moment, le type de menu

	 */
	void setMoment(TypeMenu moment); 

	//getters 
	/**
	 * @return le nom du restaurant

	 */
	string getNom() const; 
	/**
	 * @return le moment de la journee (le type de menu)

	 */
	TypeMenu getMoment() const; 

	//Autres methodes 
	/**
	 * @brief lire les information d'une table à partir d'un fichcier texte
	 * @param fichier, le nom du fichier

	 */
	void lireTable(string& fichier); 
	/**
	 * @brief crée un table et l'ajoute au restaurant
	 * @param id , l'id de la table
	 * @param nbPlaces , le nombre de place d'une table
	 */
	void ajouterTable(int id, int nbPlaces);
	/**
	 * @brief libere une table du restaurant
	 * @param id, l'id de la table à liberer

	 */
	void libererTable(int id); 
	/**
	 * @brief commande un plat à une table
	 * @param nom, le nom du plat à commander
	 * @param id, l id de la table
	 */
	void commanderPlat(string& nom, int idTable);
	/**
	 * @brief place un client dans une table d'une facon optimale
	 * @param nbClient, le nombre de personne à placer

	 */
	void placerClients(int nbClients) const; 

	//affichage 
	/**
	 * @brief affiche le chiffre d'affaire,les table et le menu d'un restaurant

	 */
	void afficher() const;

private: 
	string* nom_; 

	double chiffreAffaire_; 
	TypeMenu momentJournee_; 

	//differents menus en fonction du moment de la journee
	Menu* menuMatin_; 
	Menu* menuMidi_; 
	Menu* menuSoir_; 

	//liste des tables 
	unsigned int capaciteTables_;
	Table** tables_; 
	unsigned int nbTables_; 

};
#endif // !RESTAURANT_H
