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
	ClientOccasionnel(string_view nom, string_view prenom, int tailleGroupe);
    virtual ~ClientOccasionnel();
    int getNbPoints() const override;
    void afficherClient(ostream & os) const override;
    double getReduction(const Restaurant & res, double montant, bool estLivraison) override;
};

#endif
