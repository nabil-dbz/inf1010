/*
* Titre : ClientPrestige.h - Travail Pratique #2
* Date : 25 Février 2019
* Auteur : Nabil Dabouz(1925256) & Yassine Zarrad(1923579)
*/

#ifndef CLIENT_PRESTIGE
#define CLIENT_PRESTIGE

#include "ClientRegulier.h"
enum AddressCode{Zone1,Zone2,Zone3};
class ClientPrestige : public ClientRegulier
{
public:
	/**
	 * @brief constructeur par défaut de la classe clientPrestige
	 */
	ClientPrestige();
	/**
	 * @brief constructeur par parametres de la classe clientPrestige qui prend en parametre le nom, le prenom, la taille du groupe , le nombre de points et l adresse
	 * @param nom, le nom du client
	 * @param prenom, le prenom du client
	 * @param tailleGroupe, la taille du groupe
	 * @param nbPoints, le nombre de points
	 * @param adresse, l'adresse du client
	 */
	ClientPrestige(string nom, string prenom, int tailleGroupe, int nbPoints,AddressCode addresse);

	//Accesseur 
	/**
	 * @brief donner le code adresse du client
	 * @return le code adresse du client
	 */
	AddressCode getAddresseCode() const;

	//Autres Fonctions??
	/**
	 * @brief operator<< Pour afficher un clientPrestige avec son nom, prenom, statut ,nombre de points et adresse
	 * @param o, le stream de sortie à afficher.
	 * @param client, le plat à afficher
	 */
	friend ostream & operator<<(ostream & os, ClientPrestige client);
	/**
	 * @brief transformer l adresse en stirng
	 */
	string getAddressCodeString();


private: 
	AddressCode addresse_;


};

#endif;

