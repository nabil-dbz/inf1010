#include "ClientRegulier.h"

ClientRegulier::ClientRegulier():
	nbPoints_(0)
{
	statut_ = Fidele;
}

ClientRegulier::ClientRegulier(string nom, string prenom, int tailleGroupe, int nbPoints) :
	Client(nom, prenom, tailleGroupe), nbPoints_(nbPoints)
{
	statut_ = Fidele;
}

int ClientRegulier::getNbPoints() const
{
	return nbPoints_;
}

void ClientRegulier::augmenterNbPoints(int bonus)
{
	nbPoints_ += bonus;
}

ostream & operator<<(ostream & os, const ClientRegulier & client)
{
	Client* clientNormal = new Client(client);
	os << *clientNormal;
	os << " Possede " << client.nbPoints_ << " points." << endl;
	delete clientNormal;
	return os;
}
