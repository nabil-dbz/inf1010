/*
* Date : 25 f�vrier 2019
* Auteur : AbdeB
*/

#include "Client.h"

Client::Client()
{ tableOccupee_ = nullptr;
}

Client::Client(string_view nom, string_view prenom, int tailleGroupe) :
	nom_(nom), prenom_(prenom), tailleGroupe_(tailleGroupe)
{
    tableOccupee_ = nullptr;
}

int Client::getTailleGroupe() const
{
	return tailleGroupe_;
}

string Client::getNom() const
{
	return nom_;
}

string Client::getPrenom() const
{
	return prenom_;
}
void Client:: setTable(Table * ta)
{ tableOccupee_ = ta;}

Table * Client:: getTable() const
{ return tableOccupee_;}

void Client::afficherClient(ostream & os) const
{ 
	os << prenom_ << " " << nom_ << " " << ", taille de groupe est " << tailleGroupe_ << endl;
}

