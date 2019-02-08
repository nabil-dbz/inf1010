/*
* Titre : Plat.h - Travail Pratique #1
* Date : 09 Janvier 2019
* Auteur : David Dratwa
*/

#ifndef PLAT_H
#define PLAT_H

#include <string>
#include <iostream>

using namespace std; 

class Plat {
public: 
	// constructeurs
	/**
	 * @brief Constructeur par défaut de la classe plat
	 */
	Plat(); 
	/**
	 * @brief constructeur par paramètre de la classe Plat qui prend en paramètre le nom, le prix et le cout
	 * @param nom, le nom du plat
	 * @param prix, le prix du plat
	 * @param cout, le cout d'un plat

	 */
	Plat(string nom, double prix, double cout);

	// destructeur
	/**
	 * @brief destructeur par défaut de la classe plat
	 */
	~Plat();

	//getters 
	/**
	 * @brief donner le nom du plat
	 * @return le nom d'un plat
	 */
	string getNom() const; 
	/**
	 * @brief donner le prix du plat
	 * @return le prix d'un plat
	 */
	double getPrix() const; 
	/**
	* @brief donner le cout du plat
	* @return le cout d'un plat
	*/
	double getCout() const; 

	//setters 
	/**
	 * @brief setNom pour donner un nom à un plat
	 * * @param nom, le nom à mettre
	 */
	void setNom(string nom); 
	/**
	 * @brief setPrix pour donner le prix du plat
	 * @param prix, le prix à mettre
	 */
	void setPrix(double prix); 
	
	//affichage
	/**
	 * @brief afficher un plat
	 */
	void afficher(); 

private: 
	string nom_; 
	double prix_; 
	double cout_; 

};

#endif // !PLAT_H
