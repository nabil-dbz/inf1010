/********************************************
* Titre: Travail pratique #5 - gestionnairePlats.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include "Plat.h"
#include "Vege.h"
#include "gestionnaireGenerique.h"
#include "Foncteur.h"

#include <utility>
#include <map>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

class GestionnairePlats : public GestionnaireGenerique<pair<string, Plat*>, map<string, Plat*>>
{
public:
	/**
	 * @brief constructeur de la classe GestionnairePlat crée un GestionnairePlats à partir d’un nom de fichier et le type de menu qui sera contenu
	 * @param nomFichier, le nom du fichier de lecture
	 * @param type, le type de menu
	 */
	GestionnairePlats(const string& nomFichier, TypeMenu type); 
	/**
	 * @brief constructeur par copie de la classe GestionnairePlat crée un GestionnairePlats à partir du ponteur vers un autre en ajoutant les plats au nouveau GestionnairePlats.
	 * @param gestionnaire, le gestionnaire à copier
	 */
	GestionnairePlats(GestionnairePlats* gestionnaire);
	/**
	 * @brief destructeur de la classe GestionnairePlats, désalloue les plats de gestionnaire sous-jacent
	 */
	~GestionnairePlats();
	/**
	 * @brief getType retourne le type de menu gérer.
	 * @return type_, le type de menu gérer
	 */
	TypeMenu getType() const; 
	/**
	 * @brief allouerPlat, crée un plat à partir d'un autre
	 * @param Plat, le plat à copier
	 */
	Plat* allouerPlat(Plat*);
	/**
	 * @brief trouverPlatMoinsCher en utilisant l'algorithme min_element et le foncteur FoncteurPlatMoinsCher
	 * @return le plat le moins cher
	 */
	Plat* trouverPlatMoinsCher() const;
	/**
	 * @brief trouverPlatPlusCher en utilisant l'algorithme max_element qui utilise la fonction lamda fonction qui compare des paires de plats afin de trouver le plat le plus cher dans le conteneur du type map
	 * @return le plat le plus cher
	 */
	Plat* trouverPlatPlusCher() const;
	/**
	 * @brief trouverPlat, retourne le plat du conteneur qui porte le nom spécifié.
	 * @param nom, le nom du plat cherché
	 * @return le plat cherché
	 */
	Plat* trouverPlat(const string& nom) const;
	/**
	 * @brief getPlatsEntre, retourne les plats du conteneur qui appartiennent à un intervalle donné selon leurs prix, elle utilise le foncteur FoncteurIntervalle et l'agorithme copy_if qui copie les élément qui repondent au caractère
	 * @param borneInf, la borne inferieure de l'inervalle
	 * @param borneSup, la borne superieure de l'inervalle
	 * @return returnVector, le vecteur qui contient les pairs des plats cherchés.
	 */
	vector<pair<string, Plat*>> getPlatsEntre(double borneInf, double borneSup); 
	void lirePlats(const string& nomFichier, TypeMenu type);
	pair<string, Plat*> lirePlatDe(LectureFichierEnSections& fichier);
	/**
        * @brief afficherPlats Pour afficher un plat
        * @param os, le stream de sortie à afficher.
        */
	void afficherPlats(ostream& os);

private:
	TypeMenu type_;
};
