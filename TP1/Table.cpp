#include "Table.h"

Table::Table()
{
	capacite_ = MAXCAP;
	nbPlats_ = 0;
	id_ = -1;
	nbPlaces_ = 1;
	occupee_ = false;
	Plat**commande_ = new Plat*[MAXCAP];
}
Table::Table(int id, int nbPlaces)
{
	capacite_ = MAXCAP;
	id_ = id;
	nbPlaces_ = nbPlaces;
	occupee_ = false;
	nbPlats_ = 0;
	commande_ = new Plat*[MAXCAP];
}
Table::~Table()
{
	for (int i = 0; i < nbPlats_; i++) {
		delete commande_[i];
		commande_[i] = nullptr;
	}
	delete[] commande_;
	commande_ = nullptr;
}
int Table::getId() const
{
	return id_;
}
int Table::getNbPlaces() const
{
	return nbPlaces_;
}
bool Table::estOccupee() const
{
	return occupee_;
}
void Table::libererTable()
{
	delete []commande_;
	occupee_ = false;
	commande_ = nullptr;
	nbPlats_ = 0;
}
void Table::setId(int id)
{
	id_ = id;
}
void Table::placerClient()
{
	occupee_ = true;
}
void Table::commander(Plat* plat)
{
		if (capacite_ < nbPlats_)
		{
			capacite_ *= 2;
			Plat** nouveauPointeur = new Plat*[capacite_];
			for (unsigned int i = 0; i < nbPlats_; i++)
				nouveauPointeur[i] = commande_[i];
			delete[] commande_;
			commande_ = nouveauPointeur;
		}
		commande_[nbPlats_] = plat;
		nbPlats_++;
}
double Table::getChiffreAffaire() const
{
	double somme = 0.0;
	double sommePartielle = 0.0;
	for (int i = 0; i < nbPlats_; i++) {
		sommePartielle = commande_[i]->getPrix() - commande_[i]->getCout();
		somme += sommePartielle;
	}
	return somme;
}
void Table::afficher() const
{
	if (!occupee_) 
		cout << "\t" << "La table numero " << id_ << " est libre.";
	else {
		cout << "\t" << "La table numero " << id_ << " est occupee.";
		if (nbPlats_ == 0)
			cout << " Mais ils n'ont rien commandé pour l'instant." << endl;
		else
			cout << " Voici la commande passee par les clients : " << endl;
	}
	for (int i = 0; i < nbPlats_; i++)
	{
		commande_[i]->afficher();
	}
	cout << endl;
}