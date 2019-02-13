/*
* Titre : Table.h - Travail Pratique #2
* Date : 10 Février 2019
* Auteurs : Nabil Dabouz(1925256) & Yassine Zarrad(1923579)
*/

#ifndef TABLE_H
#define TABLE_H

#include "Plat.h"
const  int MAXCAP = 5;
class Table {
public:
	///constructeurs
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

	///destructeur
	/**
	 * @brief destructeur par défaut de la classe Menu
	 */
	~Table();

	///getters
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
	int getnbClientATable() const;
	bool estPleine() const;
	bool estOccupee() const;

	///setters
	/**
	 * @brief effacer l'ancienne commande de la table et la rendre libre
	 * desallouer les pointeurs de commandes
	 */
	void libererTable(); 
	/**
	 * @brief place un client dans une table et la rendre occupée
	 */
	void placerClient(int nbClients);
	/**
	  * @brief mettre un id à la table
	  * @param id, l'id à mettre
	  */
	void setId(int id);

	///autres methodes
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

	///affichage
	/**
	 * @brief operator<< Pour afficher une table avec ses caractéristiques
	 * @param o, le stream de sortie à afficher.
	 * @param table, la table à afficher
	 */
	friend ostream & operator<<(ostream & o,  const Table & Table);

private :
	vector<Plat*> commande_;
	int id_;
	int nbPlaces_;
	int nbClientsATable_;
};
#endif // !TABLE_H
