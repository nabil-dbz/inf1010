#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <string_view>
#include <iostream>
#include "Table.h"
//#include "Restaurant.h"
#include "def.h"
using std::string, std::string_view, std::ostream;  //? On ne devrait normalement pas faire de "using" global dans un .h, mais c'est accepte en INF1010.

class Restaurant;
class Table;
class Client
{
public:
	Client();
	Client(string_view nom, string_view prenom, int tailleGroupe);
	/**
	 * @brief destructeur de la classe client
	 */
    virtual ~Client(){};
	//getters
	int getTailleGroupe() const;
	string getNom() const;
	string getPrenom() const;
    Table * getTable()const;
    // setters
    void setTable(Table * ta);
	//affichage
	/**
	 * @brief getNbPoints est une méthode virtuelle pure
	 */
    virtual int getNbPoints() const = 0;
	/**
     * @brief afficherClient Pour afficher un client avec son nom, prenom et table 
     * @param os, le stream de sortie à afficher.
     */
    virtual void afficherClient(ostream & os) const = 0;
	/**
	 * @brief getReduction est une méthode virtuelle pure
	 */
    virtual double getReduction(const Restaurant & res, double montant, bool estLivraison) const = 0  ;

protected:
	string nom_;
	string prenom_;
	int tailleGroupe_;
    Table * tableOccupee_;
};
#endif

