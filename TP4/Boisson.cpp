//
//  Boisson.cpp
//  intra
//
//  Created by Martine Bellaiche on 2019-03-10.
//  Copyright © 2019 Martine Bellaiche. All rights reserved.
//

#include "Boisson.h"

Boisson::Boisson (string_view nom, double prix): nom_(nom), prix_(prix), taxe_(0.12)
{
}

string_view Boisson::getNom() const
{ return nom_;}
double Boisson::getPrix()  const
{return prix_;}

void Boisson::setTaxe()
{
	taxe_ = 0.12;
}

double Boisson::getTaxe() const
{
	return taxe_;
}
