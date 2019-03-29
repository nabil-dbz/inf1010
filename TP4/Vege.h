/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#ifndef VEGE_H
#define VEGE_H
#include <iostream>
#include <string_view>
#include <string>
#include"Taxable.h"
using namespace std;
class Vege
{
public:
	/**
     	* @brief le constructeur par parametre de la classe vege
     	* @param nom, le nom du plat
	* @param vitamines, la quantite de vitamines
	* @param proteines, la quantite de proteines
	* @param mineraux, la quantite de mineraux
     	*/
	Vege(string nom, double vitamines, double proteines, double mineraux);
	/**
     	* @brief getVitamines, pour savoir la quantite de vitamines
     	* @return vitamines_, la quantité cherchée
     	*/
	double getVitamines() const;
	/**
     	* @brief getProteines, pour savoir la quantite de proteines
     	* @return proteines_, la quantité cherchée
     	*/
	double getProteines() const;
	/**
     	* @brief getMineraux, pour savoir la quantite de mineraux
     	* @return mineraux_, la quantité cherchée
     	*/
	double getMineraux() const;
	/**
     	* @brief setVitamines, pour mettre à jour les vitamines
     	* @param vitamines, la quantité à mettre
     	*/
	void setVitamines(double vitamines);
	/**
     	* @brief setProteines, pour mettre à jour les proteines
     	* @param proteines, la quantité à mettre
     	*/
	void setProteines(double proteines);
	/**
     	* @brief setMineraux, pour mettre à jour les mineraux
     	* @param mineraux, la quantité à mettre
     	*/
	void setMineraux(double mineraux);
      	/**
     	* @brief operator<< Pour afficher les caractéristiques (vitamine, proteines, minéraux)
     	* @param os, le stream de sortie à afficher.
     	*/
    	void afficherVege(ostream & os)const;
    virtual double calculerApportNutritif() const = 0;

protected: 
	double vitamines_;
	double proteines_;
	double mineraux_;
    
    string nom_;
};
#endif
