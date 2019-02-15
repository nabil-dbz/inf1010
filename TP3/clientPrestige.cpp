#include "ClientPrestige.h"

ClientPrestige::ClientPrestige():
	addresse_(Zone3)
{
	statut_ = Prestige;
}

ClientPrestige::ClientPrestige(string nom, string prenom, int tailleGroupe, int nbPoints, AddressCode addresse):
	ClientRegulier(nom, prenom, tailleGroupe, nbPoints), addresse_(addresse)
{
	statut_ = Prestige;
}

AddressCode ClientPrestige::getAddresseCode() const
{
	return addresse_;
}

string ClientPrestige::getAddressCodeString()
{
	switch (addresse_)
	{
	case Zone1:
		return "Zone 1";
	case Zone2:
		return "Zone 2";
	case Zone3:
		return "Zone 3";
	}
}

ostream & operator<<(ostream & os, ClientPrestige client)
{
	os << client;
	os << "\t Habite dans la " << client.getAddressCodeString() << endl;
}
