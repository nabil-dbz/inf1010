/*
* Titre : Plat.cpp - Travail Pratique #2
* Date : 25 Février 2019
* Auteur : Nabil Dabouz(1925256) & Yassine Zarrad(1923579)
*/

#include "Plat.h"

//constructeur 


Plat::Plat(string nom , double prix , double cout){
	nom_ = nom;
	prix_ = prix; 
	cout_ = cout; 
	type_ = Regulier;
}
//getters 

Plat::~Plat()
{
}

string Plat::getNom() const {
	return nom_; 
}

double Plat::getPrix() const {
	return prix_; 
}

double Plat::getCout() const {
	return cout_; 
}
TypePlat Plat::getType() const
{
	return type_;
}
//setters 
void Plat::setNom(string nom) {
	nom_ = nom; 
}

void Plat::setPrix(double prix) {
	prix_ = prix; 
}

bool Plat::operator<(const Plat& plat) const 
{
	return this->prix_ < plat.prix_;
}

//autres methodes

ostream& operator<<(ostream& os, const Plat& plat)
{
	os << plat.nom_ << " - " << plat.prix_ << " $ (" << plat.cout_ << "$ pour le restaurant)" << endl;
	return os;
}