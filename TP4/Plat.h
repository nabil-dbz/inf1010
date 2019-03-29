/*
* Date : 25 février 2019
* Auteur : AbdeB
*/

#ifndef PLAT_H
#define PLAT_H

#include "LectureFichierEnSections.h"
#include <string>
#include <string_view>
#include <iostream>
#include "def.h"
using std::string, std::string_view, std::ostream;  //? On ne devrait normalement pas faire de "using" global dans un .h, mais c'est accepte en INF1010.

class Plat {
public:
	// constructeur
	Plat(string_view nom = "inconnu", double prix = 0, double cout = 0);
    virtual ~Plat();
	//getters 
	string getNom() const;
	double getPrix() const;
	double getCout() const;

	//setters 
	void setNom(string nom);
	void setPrix(double prix);

	//methodes en plus
    double getPrixRevient() const;
	
/**
	 * @brief clone pour créer une copie de l'objet courant (une copie alloué dynamiquement)
	 * @ return une copie de l'objet courant.
	 */
    virtual Plat *  clone () const;
	bool operator < (const Plat& plat) const;
	/**
     * @brief afficherPlat Pour afficher un plat avec son nom, prix et cout
     * @param os, le stream de sortie à afficher.
     */
    virtual void afficherPlat(ostream& os) const; 


protected:
	string nom_;
	double prix_;
	double cout_;
};

#endif // !PLAT_H
