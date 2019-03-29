/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#ifndef PLAT_BIOVEGE_H
#define PLAT_BIOVEGE_H

#include "PlatBio.h"
#include "Vege.h"
#include "def.h"
class PlatBioVege :
	public PlatBio, public Vege
{
public:
	/**
	 * @brief constructeur de la classe PlatBioVege qui prend en paramètre le nom, le prix, le cout, l'ecotaxe, vitamines, proteines et minéraux
	 * @param nom, le nom du platBio
	 * @param prix, le prix du platBio
	 * @param cout, le cout d'un platBio
	 * @param ecotaxe, l'ecotaxe d un platBio
	 * @param vitamines, quantité de vitamines
	 * @param proteines, quantité de proteines
	 * @param minéraux, quantité de minéraux
	 */
	PlatBioVege(string nom = "inconnu", double prix = 0, double cout = 0, double ecotaxe = 0,
                double vitamines = 0, double proteines = 0, double mineraux = 0);
    virtual ~PlatBioVege();
    /**
	 * @brief clone pour créer une copie de l'objet courant (une copie alloué dynamiquement)
	 * @ return une copie de l'objet courant.
	 */
    Plat * clone() const override; 
    /**
     	* @brief afficherPlat Pour afficher un plat avec son nom, prix,cout, ecotaxe , vitamines, proteines et minéraux 
     	* @param os, le stream de sortie à afficher.
     	*/
	 
    void afficherPlat(ostream & os) const override;
    
	/**
	 * @brief calculerApportNutritif qui donne l’apport nutritif qui se calcule comme suit: (vitamines_* proteines_/ mineraux_)*RAPPORT_NUTTRITIF_BIO *AVANTAGE_SANS_PESTICIDE 
	 * @return  l'apport nutritif
	 */
	 
    double calculerApportNutritif() const override;

};
#endif
