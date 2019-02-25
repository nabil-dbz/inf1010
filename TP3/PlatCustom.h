/*
* Titre : PlatCustom.h - Travail Pratique #2
* Date : 25 F�vrier 2019
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
	 * @brief constructeur de la classe PlatCustom qui prend en param�tre le nom, le prix, le cout et le nombre d'ingr�dients
	 * @param nom, le nom du platCustom
	 * @param prix, le prix du platCustom
	 * @param cout, le cout d'un platCustom
	 * @param nbIngr�dients, le nombre d'ingr�dients � ajouter
	 */
	PlatCustom(string nom, double prix , double cout,int nbIngredients );

	//getters 
	/**
	 * @brief donner le nombres d'ingr�dients dans le platCustom
	 * @return le nombre d'ingr�dient
	 */
	int getNbIngredients() const;
	/**
	 * @brief donner le suppl�ment � ajouter au prix
	 * @return le suppl�ment � ajouter
	 */
	double getSupplement()const;

	//setters 
	/**
	 * @brief setNBIngredients pour mettre le nombre d'ingr�dients
	 * * @param nIngredients, le nombre � ajouter
	 */
	void setNbIngredients(int nIngredients);




	//methodes en plus 
	/**
	 * @brief operator<< Pour afficher un platCustom avec son nom, prix,le cout , le nombre d'ingr�dients � ajouter et le suppl�ment en $
	 * @param o, le stream de sortie � afficher.
	 * @param plat, le platCustom � afficher
	 */
	friend ostream& operator<<(ostream& os, const PlatCustom& plat); ///

private:
	double supplement_;
	int nbIngredients_;
	/**
	 * @brief calcule le suppl�ment � ajouter au prix
	 * @return la somme � ajouter
	 */
	double calculerSupplement() const;


};

#endif // !PLAT_VERT_H
