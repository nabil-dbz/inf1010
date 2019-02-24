#include "PlatBio.h"

PlatBio::PlatBio(string nom, double prix, double cout, double ecotaxe):
	Plat(nom, prix, cout)
{
	ecoTaxe_ = ecotaxe;
	type_ = Bio;
}

double PlatBio::getEcoTaxe() const
{
	return ecoTaxe_;
}

void PlatBio::setEcoTaxe(double ecoTaxe)
{
	ecoTaxe_ = ecoTaxe;
}

ostream & operator<<(ostream & os, const PlatBio & plat)
{
	Plat* platNormal = new Plat(plat);
	os << *platNormal;
	os << "\t \t comprend une Taxe ecologique de :" << plat.ecoTaxe_ << "$" << endl;
	delete platNormal;
	return os;
}
