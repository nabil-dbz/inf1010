//
//  Boisson.h
//
//  Created by Martine Bellaiche on 2019-03-05.
//  Copyright © 2019 Martine Bellaiche. All rights reserved.
#ifndef BOISSON_h
#define BOISSON_h
#include "Taxable.h"
#include <string>
#include <string_view>
using namespace std;
class Boisson: public Taxable
{
 public:
    Boisson (string_view nom, double prix);
    /**
	 * @brief getNom, donne le nom de boisson
	 * @return le nom_
	 */
    string_view getNom() const;
    
	/**
	 * @brief getPrix, donne le prix de boisson
	 * @return le prix_
	 */
    double getPrix () const;
    	 
/**
	 * @brief setaxe, met le taxe 
	 */
	void setTaxe() override;
	/**
	 * @brief getTaxe, donne le taxe de boisson
	 * @return le taxe,
	 */
	double getTaxe() const override;

protected:
    string nom_;
    double prix_;
    double taxe_;
};


#endif /* Boisson_h */
