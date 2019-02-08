/*
* Titre : Table.h - Travail Pratique #1
* Date : 09 Janvier 2019
* Auteur : David Dratwa
*/

#ifndef TABLE_H
#define TABLE_H

#include "Menu.h"
const  int MAXCAP = 5;
class Table {
public: 
	//constructeurs 
	/**
	 * @brief Constructeur par défaut de la classe Table
	 */
	Table(); 
	/**
	 * @brief constructeur par paramètre de la classe Table qui prend en paramètre l'id et le nombre de places
	 * @param id, l' id de la table
	 * @param nbPlaces, le nombre de places de la table

	 */
	Table(int id, int nbPlaces);

	//destructeurs
	/**
	 * @brief destructeur par défaut de la classe Menu
	 */
	~Table();
	
	//getters 
	/**
	 * @brief donner l' id de la table
	 * @return l'id
	 */
	int getId() const; 
	/**
	 * @brief donner le nombre de places
	 * @return le nombre de places
	 */
	int getNbPlaces() const; 
	/**
	 * @brief donner l'etat d'une table
	 * @return l'etat de la table (occupee ou libre)
	 */
	bool estOccupee() const; 

	//setters 
	/**
	 * @brief effacer l'ancienne commande de la table et la rendre libre
	 * desallouer les pointeurs de commandes
	 */
	void libererTable(); 
	/**
	 * @brief place un client dans une table et la rendre occupée
	 */
	void placerClient(); 
	 /**
	  * @brief mettre un id à la table
	  * @param id, l'id à mettre
	  */
	void setId(int id); 

	//autres methodes 
	/**
	 * @brief ajouter un plat à la commande de la table
	 * @param plat, pointeur vers un plat commandé par cette table
	 */
	void commander(Plat* plat); 
	/**
	 * @brief calcule le chiffre d'affaire d'une table
	 * @return le chiffre d'affaire
	 */
	double getChiffreAffaire() const; 

	//affichage
	/**
	 * @brief affiche l'etat d'une table avec son id et sa commande
	 */
	void afficher() const; 
private : 
	Plat** commande_; 
	unsigned int capacite_; 
	unsigned int nbPlats_; 

	int id_; 
	unsigned int nbPlaces_; 
	bool occupee_; 
};
#endif // !TABLE_H
