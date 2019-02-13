/*
* Titre : Restaurant.cpp - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
*/

#include "Restaurant.h"

//constructeurs
Restaurant::Restaurant() {
	nom_ = new string("Inconnu");

	chiffreAffaire_ = 0;

	momentJournee_ = Matin;

	menuMatin_ = new Menu("menu.txt", Matin);
	menuMidi_ = new Menu("menu.txt", Midi);
	menuSoir_ = new Menu("menu.txt",  Soir);

}

Restaurant::Restaurant(const string& fichier,  const string& nom, TypeMenu moment) {
	nom_ = new string(nom);
	chiffreAffaire_ = 0;

	momentJournee_ = moment;

	menuMatin_ = new Menu(fichier, moment);
	menuMidi_ = new Menu(fichier,  Midi);
	menuSoir_ = new Menu(fichier,  Soir);


	lireTable(fichier);
}
Restaurant::Restaurant(const Restaurant & resto):
	chiffreAffaire_(resto.chiffreAffaire_),
	momentJournee_(resto.momentJournee_),
	nom_(new string(*resto.nom_))
{
	menuMatin_ = new Menu(*resto.menuMatin_);
	menuMidi_ = new Menu(*resto.menuMidi_);
	menuSoir_ = new Menu(*resto.menuSoir_);
	tables_.clear();
	for (unsigned i = 0; i < resto.tables_.size(); i++)
		tables_.push_back(new Table(*resto.tables_[i]));
}
//destructeur
Restaurant::~Restaurant() {
	if (*nom_ == "PolyFood") {
		*nom_ = "\0";
		delete menuMatin_;
		delete menuMidi_;
		delete menuSoir_;
	}
	else if (*nom_ == "\0") {
		delete nom_;
		for (unsigned i = 0; i < tables_.size(); i++) {
			delete tables_[i];
		}
	}
	else {
		delete menuMatin_;
		delete menuMidi_;
		delete menuSoir_;
		delete nom_;
		for (unsigned i = 0; i < tables_.size(); i++) {
			delete tables_[i];
		}
	}
}


//setter
void Restaurant::setMoment(TypeMenu moment) {
	momentJournee_ = moment;
}
void Restaurant::setNom(string nom)
{
	nom_ = new string(nom);
}
//getters
string Restaurant::getNom() const {
	return *nom_;
}

TypeMenu Restaurant::getMoment() const {
	return momentJournee_;
}

//autres methodes

void Restaurant::libererTable(int id) {
	for (unsigned i = 0; i < tables_.size(); i++) {
		if (id == tables_[i]->getId()) {
			chiffreAffaire_ += tables_[i]->getChiffreAffaire();
			tables_[i]->libererTable();
		}
	}
}

void Restaurant::commanderPlat(const string& nom, int idTable) {
	Plat* plat = nullptr;
	int index;
	for (unsigned i = 0; i < tables_.size(); i++) {
		if (idTable == tables_[i]->getId()) {
			index = i;
			switch (momentJournee_) {
			case Matin :
				plat = menuMatin_->trouverPlat(nom);
				break;
			case Midi :
				plat = menuMidi_->trouverPlat(nom);
				break;
			case Soir :
				plat = menuSoir_->trouverPlat(nom);
				break;
			}
		}
	}
	if (plat != nullptr && tables_[index]->estOccupee()) {
		tables_[index]->commander(plat);
	}
	else cout << "Erreur : table non occupee ou plat introuvable" << endl;
}

void Restaurant::operator+=(Table * table)
{
	tables_.push_back(table);
}

Restaurant & Restaurant::operator=(const Restaurant & resto)
{
	if (this != &resto) {
		while (tables_.size()>0) {
			delete tables_[tables_.size() - 1]; tables_.pop_back();
		}
		for (unsigned i = 0; i < resto.tables_.size(); i++)
			tables_.push_back(resto.tables_[i]);
		delete nom_;
		nom_ = resto.nom_;
		delete menuMatin_; delete menuMidi_; delete menuSoir_;
		menuMatin_ = resto.menuMatin_;
		menuMidi_ = resto.menuMidi_;
		menuSoir_ = resto.menuSoir_;
		chiffreAffaire_ = resto.chiffreAffaire_;
		momentJournee_ = resto.momentJournee_;
	}
	return *this;
}

bool Restaurant::operator<(const Restaurant & resto)
{
	return (chiffreAffaire_ < resto.chiffreAffaire_);
}

void Restaurant::lireTable(const string& fichier) {
	ifstream file(fichier, ios::in);

	if (file) {
		string ligne;

		string idString;
		int id;

		string nbPersonnesString;
		int nbPersonnes;

		int curseur;
		while (!file.eof()) {
			getline(file, ligne);
			if (ligne == "-TABLES") {
				while (!file.eof()) {
					getline(file, ligne);
					for (unsigned i = 0; i < ligne.size(); i++) {
						if (ligne[i] == ' ') {
							curseur = i;
							break;
						}
						idString += ligne[i];
					}

					id = stoi(idString);

					nbPersonnesString = ligne.substr(curseur + 1);
					nbPersonnes = stoi(nbPersonnesString);
					*this += new Table(id, nbPersonnes);
					nbPersonnesString = "";
					idString = "";
				}
			}
		}
		file.close();
	}
}

void Restaurant::placerClients(int nbClients) {
	int indexTable = -1;
	int minimum = 100;


	for (unsigned i = 0; i < tables_.size(); i++) {
		if (tables_[i]->getNbPlaces() >= nbClients && !tables_[i]->estOccupee() && tables_[i]->getNbPlaces() < minimum) {
			indexTable = i;
			minimum = tables_[i]->getNbPlaces();
		}
	}
	if (indexTable == -1) {
		cout << "Erreur : il n'y a plus/pas de table disponible pour le client. " << endl;
	}else
	tables_[indexTable]->placerClient(nbClients);
}

ostream & operator<<(ostream & o, const Restaurant & resto)
{
	o << "Le restaurant " << *(resto.nom_);
	if (resto.chiffreAffaire_ != 0)
		o << " a fait un chiffre d'affaire de : " << resto.chiffreAffaire_ << "$" << endl;
	else
		o << " n'a pas fait de benefice ou le chiffre n'est pas encore calcule." << endl;
	o << "-Voici les tables : " << endl;
	for (unsigned i = 0; i < resto.tables_.size(); i++) 
		o << "\t" << *resto.tables_[i] << endl;
	o << endl;


	o << "-Voici son menu : " << endl;
	o << "Matin : " << endl << *resto.menuMatin_;
	o << "Midi : " << endl << *resto.menuMidi_;
	o << "Soir : " << endl << *resto.menuSoir_;
	return o;
}
