/*
* Titre : Table.h - Travail Pratique #2
* Date : 25 F�vrier 2019
* Auteur : Nabil Dabouz(1925256) & Yassine Zarrad(1923579)
*/

#ifndef TABLE_H
#define TABLE_H

#include "Menu.h"
#include "PlatCustom.h"
#include "ClientPrestige.h"
#include <vector>

class Table {
public:
	//constructeurs
	///constructeurs
	/**
	 * @brief Constructeur par d�faut de la classe Table
	 */
	Table();
	/**
	 * @brief constructeur par param�tre de la classe Table qui prend en param�tre l'id et le nombre de places
	 * @param id, l' id de la table
	 * @param nbPlaces, le nombre de places de la table
	 */
	Table(int id, int nbPlaces);

	///destructeur
	/**
	 * @brief destructeur par d�faut de la classe Menu
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
	/**
	 * @brief donner l'etat d'une table
	 * @return l'etat de la table (pleine ou pas)
	 */
	bool estPleine() const; 
	/**
	 * @brief donner l'etat d'une table
	 * @return l'etat de la table (occupee ou libre)
	 */
	int getNbClientsATable() const;
	/**
	 * @brief donner la commande d'une table
	 * @return la liste des plats qui sont dans la commande la table
	 */
	vector<Plat*> getCommande() const;
	/**
	 * @brief donner le client principal d'une table
	 * @return un pointeur vers le client principal
	 */
	Client* getCliengtPrincipal() const; 
	/**
	 * @brief calcule le chiffre d'affaire d'une table
	 * @return le chiffre d'affaire
	 */
	double getChiffreAffaire() const;


	//setters
	/**
	 * @brief effacer l'ancienne commande de la table et la rendre libre
	 * desallouer les pointeurs de commandes
	 */
	void libererTable(); 
	/**
	 * @brief place un client dans une table et la rendre occup�e
	 */
	void placerClients(int nbClients);
	/**
	  * @brief mettre un id � la table
	  * @param id, l'id � mettre
	  */
	void setId(int id);
	/**
	  * @brief assigner un client principal � la table
	  * @param clientPrincipal, le pointeur vers le client principal � mettre
	  */
	void setClientPrincipal(Client* clientPrincipal); 

	//autres methodes
	/**
	 * @brief ajouter un plat � la commande de la table
	 * @param plat, pointeur vers un plat command� par cette table
	 */
	void commander(Plat* plat);

	//affichage
	/**
	 * @brief operator<< Pour afficher une table avec ses caract�ristiques
	 * @param o, le stream de sortie � afficher.
	 * @param table, la table � afficher
	 */
	friend ostream& operator<<(ostream& os, const Table& table); 

private :
	vector<Plat*> commande_;
	int id_;
	int nbPlaces_;
	int nbClientsATable_; 
	Client* clientPrincipal_;
};
#endif // !TABLE_H
