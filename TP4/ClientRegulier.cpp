/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "ClientRegulier.h"

ClientRegulier::ClientRegulier()
{
	nbPoints_ = 0;
}

ClientRegulier::ClientRegulier(string_view nom, string_view prenom, int tailleGroupe, int nbPoints) :
	Client(nom, prenom, tailleGroupe), nbPoints_(nbPoints)
{ 
}
ClientRegulier::~ClientRegulier() {}

int ClientRegulier::getNbPoints() const
{
	return nbPoints_;
}


void ClientRegulier::augmenterNbPoints(int bonus)
{
	nbPoints_ += bonus;
}


void ClientRegulier::afficherClient(ostream & os) const
{
	os << prenom_ << nom_ << endl;
}

double ClientRegulier::getReduction(const Restaurant & res, double montant, bool estLivraison) const
{
	return (nbPoints_ > SEUIL_DEBUT_REDUCTION)*(-montant * TAUX_REDUC_REGULIER);
}
