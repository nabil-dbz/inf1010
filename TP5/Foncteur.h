/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include <algorithm>
#include "Plat.h"

using namespace std;

/**
* @brief Un foncteur prédicat binaire permet de comparer les plats deux à deux du conteneur map.
*/
class FoncteurPlatMoinsCher
{ 
public:
	bool operator()(pair<string, Plat*> pair1, pair<string, Plat*> pair2) {
		return *(pair1.second) < *(pair2.second);
	};
};
/**
* @brief Un foncteur prédicat unaire ayant la borne inférieure et la borne supérieure comme attributs. Ce foncteur prend en entrée un plat unique du conteneur map et vérifie si son prix est compris entre les bornes.
*/
class FoncteurIntervalle
{
public:
	FoncteurIntervalle(double borneInf, double borneSup) :
		borneInf_(borneInf), borneSup_(borneSup) {};
	bool operator()(pair<string, Plat*> pair) {
		return (pair.second->getPrix() < borneSup_) && (pair.second->getPrix() > borneInf_);
	};
private:
	double borneInf_;
	double borneSup_;
};

