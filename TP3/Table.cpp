/*
* Titre : Table.cpp - Travail Pratique #2
* Date : 25 Février 2019
* Auteur : Nabil Dabouz(1925256) & Yassine Zarrad(1923579)
*/

#include "Table.h"

//constructeurs
Table::Table() {
	id_ = -1;
	nbPlaces_ = 1;
	nbClientsATable_ = 0;
}

Table::Table(int id, int nbPlaces) {
	id_ = id;
	nbPlaces_ = nbPlaces;
	nbClientsATable_ = 0;
	clientPrincipal_ = nullptr;
}

Table::~Table()
{
	commande_.clear();
}

//getters
int Table::getId() const {
	return id_;
}

int Table::getNbPlaces() const {
	return nbPlaces_;
}

bool Table::estOccupee() const
{
	return nbClientsATable_!=0;
}

bool Table::estPleine() const {
	return nbPlaces_ == 0;
}

int Table::getNbClientsATable() const
{
	return nbClientsATable_;
}
vector<Plat*> Table::getCommande() const
{
	return commande_;
}

Client * Table::getCliengtPrincipal() const
{
	return clientPrincipal_;
}


//setters
void Table::setId(int id) {
	id_ = id;
}

void Table::setClientPrincipal(Client * clientPrincipal)
{
	clientPrincipal_ = clientPrincipal;
}


void Table::libererTable() {
	nbPlaces_ += nbClientsATable_;
	nbClientsATable_ = 0;
	commande_.clear();
}

void Table::placerClients(int nbClient) {
	nbPlaces_ -= nbClient;
	nbClientsATable_ = nbClient;
}

//autres methodes
void Table::commander(Plat* plat) {
	commande_.push_back(plat);
}

double Table::getChiffreAffaire() const {
	double chiffre = 0;
	for (unsigned i = 0; i < commande_.size(); ++i) {
		if (commande_[i]->getType() == Bio)
			chiffre += commande_[i]->getPrix() - commande_[i]->getCout() + static_cast<PlatBio*>(commande_[i])->getEcoTaxe();
		else if (commande_[i]->getType() == Custom)
			chiffre += commande_[i]->getPrix() - commande_[i]->getCout() + static_cast<PlatCustom*>(commande_[i])->getSupplement();
		else
			chiffre += commande_[i]->getPrix() - commande_[i]->getCout();
	}
	return chiffre;
}

//affichage

ostream& operator<<(ostream& os, const Table& table)
{
	os << "La table numero " << table.id_;
	if (table.estOccupee())
	{
		os << " est occupee. Le client principal est:" << endl;
		switch (table.clientPrincipal_->getStatut()) {
		case Occasionnel:
			os << *table.clientPrincipal_; break;
		case Fidele:
			os << *(static_cast<ClientRegulier*>(table.clientPrincipal_)); break;
		case Prestige:
			ClientRegulier* clientReg = static_cast<ClientRegulier*>(table.clientPrincipal_);
			os << *(static_cast<ClientPrestige*>(clientReg)); break;
		}
		if (table.commande_.size())
		{
			os << "Voici la commande passee par les clients : " << endl;
			for (unsigned i = 0; i < table.commande_.size(); i++)
			{
				switch (table.commande_[i]->getType()) {
				case Regulier:
					os << "\t" << *table.commande_[i]; break;
				case Bio:
					os << "\t" << *(static_cast<PlatBio*>(table.commande_[i])); break;
				case Custom:
					os << "\t" << *(static_cast<PlatCustom*>(table.commande_[i])); break;
				}
			}
		}
		else
			os << endl << "Mais ils n'ont rien commande pour l'instant. " << endl;
	}
	else
		os << " est vide. " << endl;

	return os;
}
