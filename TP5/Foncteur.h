/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include <algorithm>
#include "Plat.h"

using namespace std;


class FoncteurPlatMoinsCher
{ 
public:
	bool operator()(pair<string, Plat*> pair1, pair<string, Plat*> pair2) {
		return *(pair1.second) < *(pair2.second);
	};
};

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

