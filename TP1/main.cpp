/**
* Ce programme permet de faire la gestion d'un restaurant.
* \file CodeDemande.cpp
* \author Nabil Dabouz(1925256) & Yassine Zarrad(1923579)
* \date 03 février 2019
**/

#include "Restaurant.h"

using namespace std; 

int main() {

	//creation du restaurant - avec le fichier donne - le nom : PolyFood - moment de la journee : soir. 
	string nomFichier = "polyFood.txt";
	string nomResto = "PolyFood";
	Restaurant poly(nomFichier, nomResto, Soir);
	//creer plusieurs clients -- des entiers 
	int client1 = 1; 
	int client2 = 5; 
	int client3 = 15; 
	int client4 = 3; 
	int client5 = 2; 
	//placer les clients 
	poly.placerClients(client1);
	poly.placerClients(client2);
	poly.placerClients(client3);
	poly.placerClients(client4);
	poly.placerClients(client5);
	// commander des plats
	//Poisson - Table 1
	string nomPlat = "Poisson";
	poly.commanderPlat(nomPlat, 1);
	//Poulet - Table 2 
	nomPlat = "Poulet";
	poly.commanderPlat(nomPlat, 2);
	//Pizza - Table 2 
	nomPlat = "Pizza";
	poly.commanderPlat(nomPlat, 2);
	//Poulet - Table 4
	nomPlat = "Poulet";
	poly.commanderPlat(nomPlat, 4);
	//Muffin - Table 4 
	nomPlat = "Muffin";
	poly.commanderPlat(nomPlat, 4);
	//Oeud - Table 4 
	nomPlat = "Oeud";
	poly.commanderPlat(nomPlat, 4);
	

	//afficher le restaurant
	poly.afficher(); 

	cout << "-------------------------------------------------" << endl; 
	//liberer les tables 
	poly.libererTable(1);
	poly.libererTable(2);
	poly.libererTable(3);
	poly.libererTable(4);
	//afficher le restaurant 
	poly.afficher(); 
	return 0;

}