/********************************************
* Titre: Travail pratique #5 - gestionnaireTables.cpp
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/


#include "GestionnaireTables.h"
#include "LectureFichierEnSections.h"

Table * GestionnaireTables::getTable(int id) const
{
	return *find_if(conteneur_.begin(), conteneur_.end(), [=](Table* it) {return (it->getId() == id); });
}

Table * GestionnaireTables::getMeilleureTable(int tailleGroupe) const
{
	Table* meilleureTable = nullptr;
	for (Table* table : conteneur_) {
		if (!table->estOccupee() && table->getId() != ID_TABLE_LIVRAISON) {
			int placesACetteTable = table->getNbPlaces();
			if (placesACetteTable >= tailleGroupe && (!meilleureTable || placesACetteTable < meilleureTable->getNbPlaces()))
				meilleureTable = table;
		}
	}
	return meilleureTable;
}

void GestionnaireTables::lireTables(const string& nomFichier)
{
	LectureFichierEnSections fichier{ nomFichier };
	fichier.allerASection("-TABLES");
	while (!fichier.estFinSection()) {
		int id, nbPlaces;
		fichier >> id >> nbPlaces;
		Table* t = new Table(id, nbPlaces);
		ajouter(t);
	}
}

void GestionnaireTables::afficherTables(ostream & os) const
{
	for_each(conteneur_.begin(), conteneur_.end(), [&](auto it) { os << *it; });
}

