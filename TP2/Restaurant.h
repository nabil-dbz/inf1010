/*
* Titre : Restaurant.h - Travail Pratique #2
* Date : 10 F�vrier 2019
* Auteur : Nabil Dabouz(1925256) & Yassine Zarrad(1923579)
*/

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Table.h"
#include "Menu.h"
const int INTTABLES = 6;
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
	Restaurant(const Restaurant & resto);

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
	void setNom(string nom);

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
	 * @brief lire les information d'une table � partir d'un fichcier texte
	 * @param fichier, le nom du fichier
	 */
	void lireTable(const string& fichier);
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
	void commanderPlat(const string& nom, int idTable); 
	/**
	* @brief operator+= pour ajouter une table au restaurant
	* @param table, la table � ajouter au restaurant
	*/
	void operator+=(Table* table);
	/**
	 * @brief operator<< Pour afficher un restaurant avec son menu et ses tables.
	 * @param o, le stream de sortie � afficher.
	 * @param resto, le plat � afficher
	 */
	friend ostream & operator<<(ostream & o, const Restaurant& resto);
	/**
	 * @brief operator= pour ecraser les attributs d'un restaurant et les remplac�es par les attributs d'un restaurant pass� en param�tre
	 * @param resto, le reto dont on veut copier
	 */
	Restaurant & operator=(const Restaurant& resto);
	/**
	 * @brief operator< pour comparer le chiffre d'affaires des 2 restaurants
	 *
	 * @param resto, le restaurant dont on veut comparer avec.
	 */
	bool operator<(const Restaurant& resto);
	/**
	 * @brief place un client dans une table d'une facon optimale
	 * @param nbClient, le nombre de personne � placer
	 */
	void placerClients(int nbClients);

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
};
#endif // !RESTAURANT_H
