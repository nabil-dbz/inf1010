/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#ifndef PLAT_VEGE_H
#define PLAT_VEGE_H

#include "Vege.h"
#include "Plat.h"
#include "def.h"
class PlatVege :
        public Vege, public Plat, public Taxable
{
public:
	/**
	 * @brief constructeur de la classe PlatBioVege qui prend en paramètre le nom, le prix, le cout vitamines, proteines et minéraux
	 * @param nom, le nom du platBio
	 * @param prix, le prix du platBio
	 * @param cout, le cout d'un platBio
	 * @param vitamines, quantité de vitamines
	 * @param proteines, quantité de proteines
	 * @param minéraux, quantité de minéraux
	 */
	PlatVege(string nom = "inconnu", double prix = 0, double cout = 0, double vitamines = 0,
             double proteines = 0, double mineraux = 0);
     virtual ~PlatVege();
     
	/**
	 * @brief clone pour créer une copie de l'objet courant (une copie alloué dynamiquement)
	 * @ return une copie de l'objet courant.
	 */
     Plat * clone() const override;
     /**
    	 * @brief afficherPlat Pour afficher un platVege avec ses vitamines, proteines et minéraux 
    	 * @param os, le stream de sortie à afficher.
     	*/
     void afficherPlat(ostream & os) const override;
     /**
	 * @brief calculerApportNutritif qui donne l’apport nutritif qui se calcule comme suit:(vitamines_ * proteines_ / mineraux_) * RAPPORT_NUTTRITIF
	 * @return  l'apport nutritif
	 */
     double calculerApportNutritif() const override; 
	 void setTaxe() override;
	 double getTaxe() const override;
protected:
	double taxe_;

};
#endif
