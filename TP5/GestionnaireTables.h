/********************************************
* Titre: Travail pratique #5 - gestionnaireTables.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include "Table.h"
#include "Foncteur.h"
#include "GestionnaireGenerique.h"
#include <functional>

#include <set>

class GestionnaireTables : public GestionnaireGenerique<Table*, set<Table*>>
{
public:
	GestionnaireTables() = default;
	/**
	 * @brief getTable, retourne la table dans le conteneur (qui est de type set) qui porte le id donné en utilisant l'algorithme find_if et une fonction lamda qui compare les id
	 * @param id, le id de la table cherché
	 * @return la table cherchée
	 */
	Table* getTable(int id) const; 
	/**
	 * @brief getMeilleureTable, retourne la meilleure la table qui peut contenir un groupe
	 * @param tailleGroupe, la taille du groupe
	 * @return la table cherchée si elle existe
	 */
	Table* getMeilleureTable(int tailleGroupe) const;
	void lireTables(const string& nomFichier);
	/**
   	* @brief afficherTAbles Pour afficher les tables du conteneur
     	* @param os, le stream de sortie à afficher.
     	*/
	void afficherTables(ostream& os) const;
};
