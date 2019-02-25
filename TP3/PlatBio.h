/*
* Titre : PlatBio.h - Travail Pratique #2
* Date : 25 Février 2019
* Auteur : Nabil Dabouz(1925256) & Yassine Zarrad(1923579)
*/

#ifndef PLAT_BIO_H
#define PLAT_BIO_H

#include <string>
#include <iostream>
#include "Plat.h"

using namespace std;

class PlatBio : public Plat {
public:
	// constructeurs

	/**
	 * @brief constructeur de la classe PlatBio qui prend en paramètre le nom, le prix, le cout et l'ecotaxe
	 * @param nom, le nom du platBio
	 * @param prix, le prix du platBio
	 * @param cout, le cout d'un platBio
	 * @param ecotaxe, l'ecotaxe d un platBio
	 */
	PlatBio(string nom = "inconnu", double prix = 0, double cout = 0,double ecotaxe = 0);
	
	//getters 
	/**
	 * @brief donner l'ecotaxe d'un plat biologique
	 * @return l'ecotaxe d'un platBiologique
	 */
	double getEcoTaxe() const;

	//setters 
	/**
	 * @brief setEcoTaxe pour donner un ecotaxe à un platBio
	 * * @param ecoTaxe, l'ecotaxe à mettre
	 */
	void setEcoTaxe(double ecoTaxe);




	//methodes en plus 
	/**
	 * @brief operator<< Pour afficher un platBio avec son nom, prix,le cout et l'ecotaxe
	 * @param o, le stream de sortie à afficher.
	 * @param plat, le platBio à afficher
	 */
	friend ostream& operator<<(ostream& os, const PlatBio& plat); 

private:
	double ecoTaxe_;	
};

#endif // !PLAT_BIO_H