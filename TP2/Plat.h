/*
* Titre : Plat.h - Travail Pratique #2
* Date : 10 Février 2019
* Auteurs : Nabil Dabouz(1925256) & Yassine Zarrad(1923579)
*/

#ifndef PLAT_H
#define PLAT_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Plat {
public:
	/// constructeurs
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

	/**
	 * @brief destructeur par défaut de la classe plat
	 */
	~Plat();
	///getters
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

	///setters
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

	///methodes en plus
	/**
	 * @brief operator<< Pour afficher un plat avec son nom,prix et cout
	 * @param o, le stream de sortie à afficher.
	 * @param plat, le plat à afficher
	 */
	friend ostream & operator<<(ostream& o, const Plat& plat);
	/**
	 * @brief operator< pour comparer le prix de notre plat et un autre plat recu en parametre
	 *
	 * @param plat, le plat dont on veut comparer avec.
	 */
	bool operator < (const Plat& plat) const;

private:
	string nom_;
	double prix_;
	double cout_;

};

#endif // !PLAT_H
