/*
* Titre : ClientRegulier.h - Travail Pratique #2
* Date : 25 Février 2019
* Auteur : Nabil Dabouz(1925256) & Yassine Zarrad(1923579)
*/

#ifndef CLIENT_REG
#define CLIENT_REG
#include "Client.h"
#include <vector>

const double TAUX_REDUC_REGULIER = 0.1;
const double TAUX_REDUC_PRESTIGE = 0.2;
const double SEUIL_DEBUT_REDUCTION = 75;
const double SEUIL_LIVRAISON_GRATUITE = 200;
class ClientRegulier : public Client
{
public:
	/**
	 * @brief constructeur par défaut de la classe clientRegulier
	 */
	ClientRegulier();
	/**
	 * @brief constructeur par parametres de la classe clientRegulier qui prend en parametre le nom, le prenom, la taille du groupe et le nombre de points
	 * @param nom, le nom du client
	 * @param prenom, le prenom du client
	 * @param tailleGroupe, la taille du groupe
	 * @param nbPoints, le nombre de points
	 */
	ClientRegulier(string nom , string prenom, int tailleGroupe ,int nbPoints);


	//Accesseurs
	/**
	 * @brief return le nombre du point du client
	 */
	int getNbPoints() const;


	//Autres Méthodes
	/**
	 * @brief augmente le nombre de points en ajoutant le bonus
	 */
	void augmenterNbPoints(int bonus);
	/**
	 * @brief operator<< Pour afficher un clientRegulier avec son nom, prenom, statut et nombre de points
	 * @param o, le stream de sortie à afficher.
	 * @param client, le plat à afficher
	 */
	friend ostream & operator<<(ostream & os, const ClientRegulier& client);
	

protected:
	int nbPoints_;
};
#endif
