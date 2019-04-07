/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include <algorithm>
#include "Foncteur.h"

using namespace  std;

//              T   = pair<string, Plat*> ou Table*; 
//              C   = map<string, Plat*> ou set<Table*>; 
template<typename T, typename C>
class GestionnaireGenerique
{
public:
	/**
     * @brief getConteneur qui retourne une copie du conteneur conteneur_ qui peut etre de type map<string, Plat*> ou set<Table*>
     */
	C getConteneur() const {
		return conteneur_;
	};
	/**
     * @brief ajouter qui permet d'ajouter un élément du type T = pair<string, Plat*> ou Table* au conteneur conteneur_
     * @param T, l'élément à ajouter.
     */
	void ajouter(T t) {
		conteneur_.insert(t);
	};
	/**
     * @brief getNombreElements retourne la taille de conteneur conteneur_
     */
	int getNombreElements() const {
		return conteneur_.size();
	};

protected:
	C conteneur_;
};
