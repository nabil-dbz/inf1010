/*
* Titre : PlatCustom.h - Travail Pratique #2
* Date : 25 Février 2019
* Auteur : Nabil Dabouz(1925256) & Yassine Zarrad(1923579)
*/

#ifndef PLAT_CUSTOM_H
#define PLAT_CUSTOM_H

#include <string>
#include <iostream>
#include "Plat.h"

using namespace std;

const double FRAIS_CUSTOMISATION = 0.75;

class PlatCustom : public Plat {
public:
	// constructeur
	/**
	 * @brief constructeur de la classe PlatCustom qui prend en paramètre le nom, le prix, le cout et le nombre d'ingrédients
	 * @param nom, le nom du platCustom
	 * @param prix, le prix du platCustom
	 * @param cout, le cout d'un platCustom
	 * @param nbIngrédients, le nombre d'ingrédients à ajouter
	 */
	PlatCustom(string nom, double prix , double cout,int nbIngredients );

	//getters 
	/**
	 * @brief donner le nombres d'ingrédients dans le platCustom
	 * @return le nombre d'ingrédient
	 */
	int getNbIngredients() const;
	/**
	 * @brief donner le supplément à ajouter au prix
	 * @return le supplément à ajouter
	 */
	double getSupplement()const;

	//setters 
	/**
	 * @brief setNBIngredients pour mettre le nombre d'ingrédients
	 * * @param nIngredients, le nombre à ajouter
	 */
	void setNbIngredients(int nIngredients);




	//methodes en plus 
	/**
	 * @brief operator<< Pour afficher un platCustom avec son nom, prix,le cout , le nombre d'ingrédients à ajouter et le supplément en $
	 * @param o, le stream de sortie à afficher.
	 * @param plat, le platCustom à afficher
	 */
	friend ostream& operator<<(ostream& os, const PlatCustom& plat); ///

private:
	double supplement_;
	int nbIngredients_;
	/**
	 * @brief calcule le supplément à ajouter au prix
	 * @return la somme à ajouter
	 */
	double calculerSupplement() const;


};

#endif // !PLAT_VERT_H
