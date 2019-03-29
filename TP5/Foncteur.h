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
	FoncteurPlatMoinsCher(pair<string, Plat*> pair1, pair<string, Plat*> pair2) {
		min_ = pair1.second < pair2.second;
	};

	bool operator()(pair<string, Plat*> pair1, pair<string, Plat*> pair2) {
		return pair1.second < pair2.second;
	};
private:
	bool min_;
};

class FoncteurIntervalle
{
   // TODO
};

