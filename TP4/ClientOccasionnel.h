/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#ifndef CLIENT_OCCASIONNEL
#define CLIENT_OCCASIONNEL

#include "Client.h"

class ClientOccasionnel: public Client
{
public:
	/**
	 * @brief constructeur de la classe clientOccassionnel qui prend en paramètre le nom, le prenom et la taille de groupe
	 * @param nom, le nom du client 
	 * @param prenom, le prenom du client 
	 * @param tailleGroupe, la taille du groupe
	 */
	ClientOccasionnel(string_view nom, string_view prenom, int tailleGroupe);
	/**
	 * @brief destructeur de la classe clientOccasionnel
	 */
    virtual ~ClientOccasionnel();
    /**
	 * @brief getNbPoints, donne le nombre de points accumulés par un client
	 * @return 0, le clientOccassionnel n'a pas de points
	 */
    int getNbPoints() const override;
    /**
     * @brief afficherClientnt Pour afficher un clientOccassionnel avec son nom et prenom.
     * @param os, le stream de sortie à afficher.
     */
    void afficherClient(ostream & os) const override;
    /**
	 * @brief getReduction, donne la réduction à appliquer
	 * @return 0, le Client Occasionnel n'a pas de réduction.
	 */
    double getReduction(const Restaurant & res, double montant, bool estLivraison) const override;
};

#endif
