/*
* Date : 25 f�vrier 2019
* Auteur : AbdeB
*/
#include "ClientOccasionnel.h"

ClientOccasionnel::ClientOccasionnel(string_view nom, string_view prenom, int tailleGroupe):
	Client(nom, prenom, tailleGroupe)
{ 
}
ClientOccasionnel::~ClientOccasionnel(){}

int ClientOccasionnel::getNbPoints() const
{
	return 0;
}

void ClientOccasionnel::afficherClient(ostream & os) const
{
	os << prenom_ << " " << nom_ << ", taille de groupe est " << tailleGroupe_ << endl;
}
double ClientOccasionnel::getReduction(const Restaurant & res, double montant, bool estLivraison) const
{
	return 0.0;
}
