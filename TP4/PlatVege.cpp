/*
* Date : 25 f�vrier 2019
* Auteur : AbdeB
*/
#include "PlatVege.h"


PlatVege::PlatVege(string nom, double prix, double cout,
                   double vitamines, double proteines, double mineraux):
	Plat(nom, prix, cout), Vege(nom, vitamines, proteines, mineraux), taxe_(0.07)
{
    
}
PlatVege::~ PlatVege(){}

Plat* PlatVege::clone() const
{ 
	return new PlatVege(*this);
}


void PlatVege::afficherPlat(ostream & os) const
{   
	Plat::afficherPlat(os);
	os << "PLAT VEGE " << Plat::nom_ << " ";
	Vege::afficherVege(os);
	os << "(Apport nutritif " << calculerApportNutritif() << "mg)" << endl;
}

double PlatVege::calculerApportNutritif() const
{
	return (vitamines_*proteines_ / mineraux_) * RAPPORT_NUTRITIF;
}

void PlatVege::setTaxe()
{
	taxe_ = 0.07;
}

double PlatVege::getTaxe() const
{
	return taxe_;
}
