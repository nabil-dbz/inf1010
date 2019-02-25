/*
* Titre : Client.cpp - Travail Pratique #2
* Date : 25 Février 2019
* Auteur : Nabil Dabouz(1925256) & Yassine Zarrad(1923579)
*/

#include "Client.h"

Client::Client()
{
	nom_ = "inconnu";
	prenom_ = "inconnu";
	statut_ = Occasionnel;
}

Client::Client(string nom, string prenom, int tailleGroupe):
	nom_(nom), prenom_(prenom), tailleGroupe_(tailleGroupe), statut_(Occasionnel)
{
}

Client::~Client()
{
}

StatutClient Client::getStatut() const
{
	return statut_;
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

string Client::convertirStatutString() const
{
	switch (statut_)
	{
	case Occasionnel:
		return "Occasionnel";
	case Fidele: 
		return "Regulier";
	case Prestige:
		return "Prestige";
	default:
		return "Occasionnel";
	}
}

ostream & operator<<(ostream & os, const Client & client)
{
	os << "\t -" << client.prenom_ << " " << client.nom_ << " statut: " << client.convertirStatutString();
	return os;
}
