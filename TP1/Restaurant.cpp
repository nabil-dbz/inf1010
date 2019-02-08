#include "Restaurant.h"

Restaurant::Restaurant() {
	nom_ = new string("inconnu");
	chiffreAffaire_ = 0.0;
	momentJournee_ = Matin;
	menuMatin_ = nullptr;
	menuMidi_ = nullptr;
	menuSoir_ = nullptr;
	capaciteTables_ = INTTABLES;
	nbTables_ = 0;
	tables_ = new Table*[capaciteTables_];
}

Restaurant::Restaurant(string& fichier, string& nom, TypeMenu moment) {
	nom_ = new string(nom);
	momentJournee_ = moment;
	menuMatin_ = new Menu(fichier, Matin);
	menuMidi_ = new Menu(fichier, Midi);
	menuSoir_ = new Menu(fichier, Soir);
	capaciteTables_ = INTTABLES;
	nbTables_ = 0;
	tables_ = new Table*[INTTABLES];
	lireTable(fichier);
	chiffreAffaire_ = 0;
}

Restaurant::~Restaurant()
{
	delete nom_;
	delete menuMatin_;
	delete menuMidi_;
	delete menuSoir_;
	for (int i = 0; i < nbTables_; i++) {
		delete tables_[i];
		tables_[i] = nullptr;
	}
	delete[] tables_;
	tables_ = nullptr;
}

void Restaurant::setMoment(TypeMenu moment) {
	momentJournee_ = moment;
}

string Restaurant::getNom() const {
	return *nom_;
}

TypeMenu Restaurant::getMoment() const {
	return momentJournee_;
}

void Restaurant::lireTable(string& fichier) {
	ifstream entree(fichier);
	bool trouve = false;
	string getString;
	while (!trouve && (!ws(entree).eof()))
	{
		getline(entree, getString);
		trouve = (getString == "-TABLES");
	}
	int id = 0;
	int nbPlaces = 0;
	while (!ws(entree).eof())
	{
		entree >> id >> nbPlaces;
		ajouterTable(id, nbPlaces);
	}
}

void Restaurant::ajouterTable(int id, int nbPlaces) {
	Table* ptrNvTable = new Table(id, nbPlaces);
	if (capaciteTables_ < nbTables_)
	{
		capaciteTables_ *= 2;
		Table** nouveauPointeur = new Table*[capaciteTables_];
		for (unsigned int i = 0; i < nbTables_; i++)
			nouveauPointeur[i] = tables_[i];
		delete[] tables_;
		tables_ = nouveauPointeur;
	}
	tables_[nbTables_] = ptrNvTable;
	nbTables_++;
}

void Restaurant::libererTable(int id) {
	int i = 0;
	bool trouve = false;
	while ((i < nbTables_) && (!trouve))
	{
		trouve = tables_[i]->getId() == id;
		i++;
	}
	chiffreAffaire_ += tables_[i - 1]->getChiffreAffaire();
	tables_[i - 1]->libererTable();
}

void Restaurant::commanderPlat(string & nom, int idTable) {
	Menu* menu = nullptr;
	switch (momentJournee_) {
		case Matin:
			menu = menuMatin_;
			break;
		case Midi:
			menu = menuMidi_;
			break;
		case Soir:
			menu = menuSoir_;
			break;
	}
	Plat* plat = menu->trouverPlat(nom);
	int i = 0;
	bool trouve = false;
	while ((i < nbTables_) && (!trouve))
	{
		trouve = tables_[i]->getId() == idTable;
		i++;
	}
	if (plat != nullptr) {
		tables_[i - 1]->commander(plat);
	}
	if (plat == nullptr || !trouve)
		cout << "Erreur : Table non occupee ou plat introuvable" << endl;
}

void Restaurant::placerClients(int nbClients) const {
	int minDiff = 100;
	int minIndice = nbTables_;
	bool aConsidere;
	for (int i = 0; i < nbTables_; i++)
	{
		aConsidere = (!tables_[i]->estOccupee()) && (minDiff > tables_[i]->getNbPlaces() - nbClients) &&
			(tables_[i]->getNbPlaces() - nbClients > 0);
		if (aConsidere) {
			minDiff = tables_[i]->getNbPlaces() - nbClients;
			minIndice = i;
		}
	}
	if ((minIndice < nbTables_ - 1) || (aConsidere))
		tables_[minIndice]->placerClient();
	else
		cout << "Erreur : il n'y a plus/pas de table disponible pour le client." << endl;
}

void Restaurant::afficher() const {
	if (chiffreAffaire_ != 0)
		cout << "Le restaurant " << *nom_ << " a fait un chiffre d'affaire de : " << chiffreAffaire_ << "$\n";
	else
		cout << "Le restaurant " << *nom_ << " n'a pas fait de benifices ou le chiffre n'est pas encore calcule" << endl;
	cout << "-Voici les tables :" << endl;
	for (int i = 0; i < nbTables_; i++)
		tables_[i]->afficher();
	cout << "-Voici son menu :" << endl;
	cout << "Matin :" << endl;
	menuMatin_->afficher();
	cout << "Midi :" << endl;
	menuMidi_->afficher();
	cout << "Soir :" << endl;
	menuSoir_->afficher();
}

