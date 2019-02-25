/*
* Titre : Restaurant.h - Travail Pratique #2
* Date : 25 F�vrier 2019
* Auteur : Nabil Dabouz(1925256) & Yassine Zarrad(1923579)
*/

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Table.h"
#include "ClientPrestige.h"

const int NB_ZONES_LIVR = 3;
const int INDEX_TABLE_LIVRAISON = 4;


class Restaurant {
public:
	//constructeurs
	/**
	 * @brief Constructeur par d�faut de la classe Restaurant
	 */
	Restaurant();
	/**
	 * @brief constructeur par param�tre de la classe Restaurant qui prend en param�tre le nom, le prix et le cout
	 * @param fichier, le nom du fichier
	 * @param nom, le nom du restaurant
	 * @param type, le type de menu
	 */
	Restaurant(const string& fichier, const string& nom,  TypeMenu moment);
	/**
	 * @brief constructeur par copie du restaurant
	 * @param resto,le restaurant � copier.
	 */
	Restaurant(const Restaurant& restau); 

	//destructeur
	/**
	 * @brief destructeur par d�faut de la classe Restaurant
	 */
	~Restaurant();

	//setters
	/**
	 * @brief mettre le type de menu
	 * @param moment, le type de menu
	 */
	void setMoment(TypeMenu moment);
	/**
	 * @brief mettre le nom du restaurant
	 * @param nom, le nom � assigner
	 */
	void setNom(const string& nom); 

	//getters
	/**
	 * @return le nom du restaurant
	 */
	string getNom() const;
	/**
	 * @return le moment de la journee (le type de menu)
	 */
	TypeMenu getMoment() const;
	/**
	 * @param index, la zone dans laquelle le client habite
	 * @return les frais de transports d'une livraison
	 */
	double getFraisTransports(int index) const;

	//Autres methodes
	/**
	 * @brief lire les information d'une table � partir d'un fichcier texte
	 * @param fichier, le nom du fichier
	 */
	void lireTable(const string& fichier);
	/**
	 * @brief lire les adresses des clients � partir d'un fichier 
	 * @param fichier, le nom du fichier
	 */
	void lireAdresses(const string& fichier);
	/**
	* @brief operator+= pour ajouter une table au restaurant
	* @param table, la table � ajouter au restaurant
	*/
	Restaurant& operator+=(Table* table); 
	/**
	 * @brief libere une table du restaurant
	 * @param id, l'id de la table � liberer
	 */
	void libererTable(int id);
	/**
	 * @brief commande un plat � une table
	 * @param nom, le nom du plat � commander
	 * @param id, l id de la table
	 */
	void commanderPlat(const string& nom, int idTable, TypePlat type= Regulier,int nbIngredients = 0);
	/**
	 * @brief operator< pour comparer le chiffre d'affaires des 2 restaurants
	 *
	 * @param resto, le restaurant dont on veut comparer avec.
	 */
	bool operator < (const Restaurant& restau) const ;
	/**
	 * @brief operator= pour ecraser les attributs d'un restaurant et les remplac�es par les attributs d'un restaurant pass� en param�tre
	 * @param restau, le reto dont on veut copier
	 */
	Restaurant& operator = (const Restaurant& restau); 
	/**
	 * @brief place un client dans une table d'une facon optimale
	 * @param client, pointeur vers le client principal de la table
	 */
	void placerClients(Client* client);
	/**
	 * @brief livre la commande vers un client (prestige)
	 * @param client, pointeur vers le client 
	 * @param nomPlats, la liste des plats que le client a command� 
	 */
	void livrerClient(Client * client, vector<string>nomPlats);
	/**
	 * @brief calculer la r�duction pour un client
	 * @param client, pointeur vers le client principal de la table
	 * @param montant, facture de la commande
	 * @param livraison, bool�en � 1 si une livraison est faite pour le client
	 */
	double calculerReduction(Client* client, double montant, bool livraison);
	/**
	 * @brief operator<< Pour afficher un restaurant avec son menu et ses tables.
	 * @param os, le stream de sortie � afficher.
	 * @param restau, le plat � afficher
	 */
	friend ostream& operator<<(ostream& os, const Restaurant& restau); 




private:
	string* nom_;

	double chiffreAffaire_;
	TypeMenu momentJournee_;

	//differents menus en fonction du moment de la journee
	Menu* menuMatin_;
	Menu* menuMidi_;
	Menu* menuSoir_;

	//liste des tables
	vector<Table*> tables_;

	//Tarif des trois zones de livraison nouvel attribut
	double fraisTransport_[NB_ZONES_LIVR]; 


};
#endif // !RESTAURANT_H
