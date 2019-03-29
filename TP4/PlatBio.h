/*
* Date : 25 février 2019
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
	/**
	 * @brief constructeur de la classe PlatBio qui prend en paramètre le nom, le prix, le cout et l'ecotaxe
	 * @param nom, le nom du platBio
	 * @param prix, le prix du platBio
	 * @param cout, le cout d'un platBio
	 * @param ecotaxe, l'ecotaxe d un platBio
	 */
    PlatBio(string nom = "inconnu", double prix = 0,
    double cout = 0, double ecotaxe = 0);
    virtual ~PlatBio();
	//getters 
	double getEcoTaxe() const;
	//setters 
	void setEcoTaxe(double ecoTaxe);
	/**
     * @brief afficherPlat Pour afficher un platBio avec son ecotaxe 
     * @param os, le stream de sortie à afficher.
     */
    void afficherPlat(ostream& os) const override;
	/**
	 * @brief getPrixDeRevient pour donner le prix - le coût + l’ecotaxe.
	 * @return  le prix - le coût + l’ecotaxe.
	 */
    double getPrixDeRevient();
	/**
	 * @brief clone pour créer une copie de l'objet courant (une copie alloué dynamiquement)
	 * @ return une copie de l'objet courant.
	 */
    Plat * clone() const override; 
protected:
	double ecoTaxe_;

};

#endif // !PLAT_VERT_H
