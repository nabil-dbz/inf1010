/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#ifndef CLIENT_PRESTIGE
#define CLIENT_PRESTIGE

#include "ClientRegulier.h"

#include "def.h"
class ClientPrestige : public ClientRegulier
{
public:
	ClientPrestige();
	/**
	 * @brief constructeur de la classe clientPrestige qui prend en paramètre le nom, le prenom, la taille de groupe, le nombre de point et la zone d'habitation
	 * @param nom, le nom du client 
	 * @param prenom, le prenom du client 
	 * @param tailleGroupe, la taille du groupe
	 * @param nbPoints, le nombre de points
         * @param zoneHabitation, l'adresse de client 	 
	 */
	ClientPrestige(string_view nom, string_view prenom, int tailleGroupe,
		           int nbPoints, ZoneHabitation adresse);
    virtual ~ClientPrestige(){};
	//Accesseur 
	ZoneHabitation getAdresseCode() const;

	//Autres Fonctions
		 
/**
     * @brief afficherClient Pour afficher un clientPrestige avec son nom et prenom.
     * @param os, le stream de sortie à afficher.
     */
	 
    void afficherClient(ostream & os) const override;
	string getAdressCodeString() const;
	/**
	 * @brief getReduction, calcule la réduction en fonction du TAUX_REDUC_PRESTIGE et vérifie si le nombre de points < SEUIL_LIVRAISON_GRATUITE alors les frais de livraison sont ajoutés à la livraison.
	 * @return la reduction à appliquer, 
	 */
    double getReduction(const Restaurant & res, double montant, bool estLivraison) const override;

private:
	ZoneHabitation adresse_;

};

#endif

