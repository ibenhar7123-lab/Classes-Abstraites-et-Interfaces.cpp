#ifndef PAIEMENTESPECE_H
#define PAIEMENTESPECE_H

#include <iostream>
#include "Paiement.h"

class PaiementEspece : public Paiement {
public:
    void effectuerPaiement(double montant) override {
        std::cout << "Paiement de " << montant << " DH en especes." << std::endl;
    }
};

#endif
