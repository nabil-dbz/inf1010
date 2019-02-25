/*
* Titre : Client.h - Travail Pratique #2
* Date : 25 Février 2019
* Auteur : Nabil Dabouz(1925256) & Yassine Zarrad(1923579)
*/

#ifndef CLIENT
#define CLIENT

#include <string>
#include <iostream>
using namespace std;

enum StatutClient { Occasionnel, Fidele, Prestige };

class Client{
public:
	/**
	 * @brief constructeur par défaut de la classe client
	 */
	Client();
	/**
	 * @brief constructeur par parametres de la classe client qui prend en parametre le nom, le prenom et la taille du groupe
	 * @param nom, le nom du client
	 * @param prenom, le prenom du client
	 * @param tailleGroupe, la taille du groupe
	 */
	Client(string nom,string prenom,int tailleGroupe);
	/**
	* @brief destructeur par défaut de la classe Client
	*/
	~Client();

// Accesseurs
	/**
	 * @brief donner le statut du client
	 * @return le statut de client
	 */
	StatutClient getStatut() const;
	/**
	 * @brief donner la taille du groupe
	 * @return la taille du groupe
	 */
	int getTailleGroupe() const;
	/**
	 * @brief donner le nom du client
	 * @return le nom du client
	 */
	string getNom() const;
	/**
	 * @brief donner le prenom du client
	 * @return le prenom du client
	 */
	string getPrenom() const;
	
//Autes méthodes
	/**
	 * @brief operator<< Pour afficher un client avec son nom, prenom et statut
	 * @param o, le stream de sortie à afficher.
	 * @param client, le plat à afficher
	 */
	friend ostream & operator<<(ostream & os, const Client& client);
private:
	/**
	 * @brief convertir le statut du clien en string
	 * @return le statut du client en string
	 */
	string convertirStatutString() const;

protected:
	string nom_;
	string prenom_;
	int tailleGroupe_;
	StatutClient statut_;
};

#endif

