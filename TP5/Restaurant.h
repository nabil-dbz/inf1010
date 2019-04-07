
/*
* Titre : Restaurant.h - Travail Pratique #1
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
*/

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Table.h"
#include "Client.h"
#include "ClientPrestige.h"
#include "pointers.h"
#include "GestionnaireTables.h"
#include "GestionnairePlats.h"
#include "def.h"

#include <string_view>
#include <iostream>
using namespace std;
class Client;
class Table;
class Restaurant {
public:
	// Constructeurs.

	Restaurant();
	Restaurant(const string& nomFichier, string_view nom, TypeMenu moment);
	Restaurant(const Restaurant& autre) = delete;  //? Le programme ne fait jamais de copie de restaurant,
                                                   //donc cette methode n"est jamais cree par defaut par le compilateur
    
	// Destructeur.
	~Restaurant();

	// Setters.
	/**
	 * @brief mettre le type de menu
	 * @param moment, le type de menu
	 */
	void setMoment(TypeMenu moment);
	/**
	 * @brief mettre le nom du restaurant
	 * @param nom, le nom à assigner
	 */
	void setNom(string_view nom); 
	/**
	 * @brief mettre le chiffre d'affaires du restaurant
	 * @param chiffre, le chiffre à assigner
	 */
    void setChiffreAffaire( double chiffre);
	// Getters.
	/**
	 * @return le nom du restaurant
	 */
	string getNom() const;
	/**
	 * @return le moment de la journee (le type de menu)
	 */
	TypeMenu getMoment() const;
	/**
	 * @return le chiffre d'affaires
	 */
    double getChiffreAffaire();
	/**
	 * @brief getTables, retourne le gestionnaire de tables
	 */
	GestionnaireTables* getTables() const;
	/**
	 * @brief getTables, retourne le gestionnaire de plats
	 */
	GestionnairePlats* getMenu(TypeMenu typeMenu) const; 
	double getFraisLivraison(ZoneHabitation zone) const;
	string getNomTypeMenu(TypeMenu typeMenu) const;

	// Autres methodes.
	void lireAdresses(const string& fichier);
	void libererTable(int id);

	//void lireTables(const string& fichier); // TODO : À retirer, déplcer dans GestionnaitreTables.
	//Restaurant& operator+=(owner<Table*> table); // TODO : À retirer, deplacer dans GestionnaireTables //? Le param�tre est indiqu� "owner" pour montrer que cette m�thode prend possession du pointeur qui lui est pass�, mais owner<Table*> est �quivalent � Table*; voir pointers.h .
	/**
	 * @brief commande un plat à une table
	 * @param nom, le nom du plat à commander
	 * @param idTable, l id de la table
	 */
	void commanderPlat(const string& nom, int idTable);
	/**
	 * @brief operator< pour comparer le chiffre d'affaires des 2 restaurants
	 *
	 * @param restau, le restaurant dont on veut comparer avec.
	 */
	bool operator <(const Restaurant& restau) const ;
	Restaurant& operator=(const Restaurant& autre) = delete;  //? Le programme ne fait jamais de copie de restaurant, donc cette fonction n'�tait pas test�e et par cons�quent probablement �rron�e.
	/**
	 * @brief place un client dans une table d'une facon optimale
	 * @param client, pointeur vers le client principal de la table
	 * @return true si le cilent est placé sinon false
	 */
	bool placerClients(Client* client);
	/**
	 * @brief livre la commande d'un client en le placant dans la table de livraison
	 * @param client, pointeur vers le client 
	 * @param nomPlats, la liste des plats que le client a commandé 
	 */
	bool livrerClient(Client* client, const vector<string>& nomPlats);
	/**
	 * @brief calculer la réduction pour un client
	 * @param client, pointeur vers le client principal de la table
	 * @param montant, facture de la commande
	 * @param livraison, booléen à 1 si une livraison est faite pour le client
	 */
	double calculerReduction(Client* client, double montant, bool livraison);
	friend ostream& operator<<(ostream& os, const Restaurant& restau);
	
	friend ostream& operator<<(ostream& os, const Restaurant& restaurent);

private:
	GestionnairePlats* menuActuel() const;
	//Table* getTable(int id) const; // TODO : À retirer, utiliser GestionnaireTables

	string nom_;
	TypeMenu momentJournee_;
	double chiffreAffaire_;

	// Differents menus en fonction du moment de la journ�e.
	GestionnairePlats* menuMatin_; 
	GestionnairePlats* menuMidi_;
	GestionnairePlats* menuSoir_;
	
	// Liste des tables.
	GestionnaireTables* tables_;

	// Tarif des trois zones de livraison.
	double fraisLivraison_[NB_ZONES_LIVR]; 
};


#endif // !RESTAURANT_H
