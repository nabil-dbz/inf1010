#include "Menu.h"

Menu::Menu()
{
	capacite_ = MAXPLAT;
	listePlats_ = new Plat*[capacite_];
	nbPlats_ = 0;
	type_ = Matin;
}

Menu::Menu(string fichier, TypeMenu type)
{
	type_ = type;
	capacite_ = MAXPLAT; 
	nbPlats_ = 0;
	listePlats_ = new Plat*[capacite_];
	lireMenu(fichier);

}

Menu::~Menu()
{
	for (int i = 0; i < nbPlats_; i++) {
		delete listePlats_[i];
		listePlats_[i] = nullptr;
	}
	delete[] listePlats_;
	listePlats_ = nullptr;
}

int Menu::getNbPlats() const
{
	return nbPlats_;
}

void Menu::afficher() const
{
	for (unsigned int i = 0; i < nbPlats_; i++)
	{
		listePlats_[i]->afficher();
	}
}

Plat* Menu::trouverPlat(string& nom) const
{
	bool trouve = false;
	unsigned int i = 0;
	while (!trouve &&  i<nbPlats_)
	{
		trouve = (*listePlats_[i]).getNom() == nom;
		i++;
	}
	if (trouve) return listePlats_[i - 1];
	else return nullptr;
}

void Menu::ajouterPlat(Plat& plat)
{
	if (capacite_ < nbPlats_)
	{
		capacite_ *= 2;
		Plat** nouveauPointeur = new Plat*[capacite_];
		for (unsigned int i = 0; i < nbPlats_; i++)
			nouveauPointeur[i] = listePlats_[i];
		delete[] listePlats_;
		listePlats_ = nouveauPointeur;
	}
	listePlats_[nbPlats_] = &plat;
	nbPlats_++;
}

void Menu::ajouterPlat(string& nom, double montant, double cout)
{
	Plat* ptrPlat = new Plat(nom, montant, cout);
	ajouterPlat(*ptrPlat);
}

bool Menu::lireMenu(string& fichier)
{
	ifstream entree(fichier);
	bool trouve = false;
	string getString, typeMenu, typeNextMenu;
	switch (type_)
	{
	case Matin:
		typeMenu = "-MATIN";
		typeNextMenu = "-MIDI";
		break;
	case Midi:
		typeMenu = "-MIDI";
		typeNextMenu = "-SOIR";
		break;
	case Soir:
		typeMenu = "-SOIR";
		typeNextMenu = "-TABLES";
		break;
	}
	while ((!trouve)&&(!ws(entree).eof()))
	{
		getline(entree, getString);
		trouve = (getString == typeMenu);
	}
	if (trouve)
	{
		trouve = false;
		while (!trouve)
		{
			string nom; double prix; double coute;
			entree >> nom >> prix >> coute;
			trouve = (nom == typeNextMenu);
			if (!trouve) 
				ajouterPlat(nom, prix, coute);
		}
		return 1;
	}
	else return 0;
}