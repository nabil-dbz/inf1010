/*
* Date : 25 février 2019
* Auteur : AbdeB
*/

#include "Menu.h"
#include "LectureFichierEnSections.h"
#include <cassert>  //? Contient "assert" qui permet de s'assurer qu'une expression est vraie, et terminer le programme avec un message d'erreur en cas contraire.
using namespace std;

// Constructeurs.

Menu::Menu() :
	type_{TypeMenu::Matin}
{
}

Menu::Menu(string fichier, TypeMenu type) :
	type_{type}
{
	lireMenu(fichier); 
}

Menu::~Menu()
{
	for (unsigned int i = 0; i < listePlats_.size(); i++) {
			delete listePlats_[i];
	}
}

Plat* Menu::allouerPlat(Plat* plat) {
    return plat->clone();
}


// Ce constructeur fait une deep copy, mais le shallow copy aurait donné le meme résultat
Menu::Menu(const Menu & menu) : type_(menu.type_)
{
	for (unsigned int i = 0; i < menu.listePlats_.size(); i++) {

		if (dynamic_cast<PlatVege*>(menu.listePlats_[i])) {
			listePlats_.push_back(new PlatVege(*dynamic_cast<PlatVege*>(menu.listePlats_[i])));
			listePlatsVege_.push_back(dynamic_cast<PlatVege*>(listePlats_[i]));
		}
		else if (dynamic_cast<PlatBioVege*>(menu.listePlats_[i])) {
			listePlats_.push_back(new PlatBioVege(*dynamic_cast<PlatBioVege*>(menu.listePlats_[i])));
			listePlatsVege_.push_back(dynamic_cast<PlatBioVege*>(listePlats_[i]));
		}
		else if (dynamic_cast<PlatBio*>(menu.listePlats_[i])) {
			listePlats_.push_back(new PlatBio(*dynamic_cast<PlatBio*>(menu.listePlats_[i])));
		}
		else
			listePlats_.push_back(menu.listePlats_[i]);
	}
}

Menu & Menu::operator=(const Menu & menu)
{
	if (this != &menu) {
		type_ = menu.type_;
		for (unsigned int i = 0; i < listePlats_.size(); i++) {
				delete listePlats_[i];
		}
		listePlats_.clear(); listePlatsVege_.clear();
		for (unsigned int i = 0; i < menu.listePlats_.size(); i++) {

			if (dynamic_cast<PlatVege*>(menu.listePlats_[i])) {
				listePlats_.push_back(new PlatVege(*dynamic_cast<PlatVege*>(menu.listePlats_[i])));
				listePlatsVege_.push_back(dynamic_cast<PlatVege*>(listePlats_[i]));
			}
			else if (dynamic_cast<PlatBioVege*>(menu.listePlats_[i])) {
				listePlats_.push_back(new PlatBioVege(*dynamic_cast<PlatBioVege*>(menu.listePlats_[i])));
				listePlatsVege_.push_back(dynamic_cast<PlatBioVege*>(listePlats_[i]));
			}
			else if (dynamic_cast<PlatBio*>(menu.listePlats_[i])) {
				listePlats_.push_back(new PlatBio(*dynamic_cast<PlatBio*>(menu.listePlats_[i])));
			}
			else
				listePlats_.push_back(menu.listePlats_[i]);
		}
	}
	return *this;
}

// Getters.

vector<Plat*> Menu::getListePlats() const
{
	return listePlats_;
}

// Autres methodes.

Menu& Menu::operator+=(owner<Plat*> plat)
{	
	if (plat != nullptr) {
		listePlats_.push_back(plat);
		PlatVege* ptrPlatVege = dynamic_cast<PlatVege*>(plat);
		PlatBioVege* ptrPlatBioVege = dynamic_cast<PlatBioVege*>(plat);
		if (ptrPlatVege) {
			listePlatsVege_.push_back(ptrPlatVege);
		}
		else if (ptrPlatBioVege) {
			listePlatsVege_.push_back(ptrPlatBioVege);
		}
	}
	return *this;
}

void Menu::lireMenu(const string& nomFichier) {
	LectureFichierEnSections fichier{nomFichier};
	fichier.allerASection(entetesDesTypesDeMenu[static_cast<int>(type_)]);
	while (!fichier.estFinSection()) 
		*this += lirePlatDe(fichier);
}

Plat* Menu::trouverPlatMoinsCher() const
{
	assert(!listePlats_.empty() && "La liste de plats de doit pas etre vide pour trouver le plat le moins cher.");
	Plat* minimum = listePlats_[0];
	for (Plat* plat : listePlats_)
		if (*plat < *minimum)
			minimum = plat;

	return minimum;
}

Plat* Menu::trouverPlat(string_view nom) const
{
	for (Plat* plat : listePlats_)
		if (plat->getNom() == nom)
			return plat; 

	return nullptr; 
}
Plat* Menu::lirePlatDe(LectureFichierEnSections& fichier)
{
    auto lectureLigne = fichier.lecteurDeLigne();
    
    string nom, typeStr;
    TypePlat type;
    double prix, coutDeRevient;
    lectureLigne >> nom >> typeStr >> prix >> coutDeRevient;
    type = TypePlat(stoi(typeStr));
    double ecotaxe, vitamines, proteines, mineraux;
    switch (type) {
        case TypePlat::Bio :
            lectureLigne >> ecotaxe;
            return new PlatBio{ nom, prix, coutDeRevient, ecotaxe };
        case TypePlat::BioVege:
            lectureLigne >> ecotaxe >> vitamines >> proteines >> mineraux;
            return new PlatBioVege(nom, prix, coutDeRevient, ecotaxe, vitamines, proteines, mineraux);
        case TypePlat::Vege:
            lectureLigne >> vitamines >> proteines >> mineraux;
            return new PlatVege(nom, prix, coutDeRevient, vitamines, proteines, mineraux);
        default:
            return new Plat{nom, prix, coutDeRevient};
    }
    
}

// Fonctions globales.

ostream& operator<<(ostream& os, const Menu& menu)
{
	for (unsigned int i = 0; i < menu.listePlats_.size(); i++) {
		if (dynamic_cast<PlatBio*>(menu.listePlats_[i]))
			dynamic_cast<PlatBio*>(menu.listePlats_[i])->afficherPlat(os);
		else if (dynamic_cast<PlatVege*>(menu.listePlats_[i]))
			dynamic_cast<PlatVege*>(menu.listePlats_[i])->afficherPlat(os);
		else if (dynamic_cast<PlatBioVege*>(menu.listePlats_[i]))
			dynamic_cast<PlatBioVege*>(menu.listePlats_[i])->afficherPlat(os);
		else 
			menu.listePlats_[i]->afficherPlat(os);
	}
	os << endl << "MENU ENTIEREMENT VEGETARIEN" << endl;
	for (unsigned int i = 0; i < menu.listePlatsVege_.size(); i++)
		menu.listePlatsVege_[i]->afficherVege(os);
	return os;
}
		
