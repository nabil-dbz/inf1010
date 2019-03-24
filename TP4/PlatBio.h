/*
* Date : 25 f�vrier 2019
* Auteur : AbdeB
*/

#ifndef PLAT_BIO_H
#define PLAT_BIO_H

#include <string>
#include <iostream>
#include "Plat.h"

using namespace std;

class PlatBio: public Plat {
public:
	// constructeurs
    PlatBio(string nom = "inconnu", double prix = 0,
    double cout = 0, double ecotaxe = 0);
    virtual ~PlatBio();
	//getters 
	double getEcoTaxe() const;
	//setters 
	void setEcoTaxe(double ecoTaxe);
    void afficherPlat(ostream& os) const override;
    double getPrixDeRevient();
    Plat * clone() const override; 
protected:
	double ecoTaxe_;

};

#endif // !PLAT_VERT_H
