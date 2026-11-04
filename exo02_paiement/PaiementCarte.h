#ifndef PAIEMENTCARTE_H
#define PAIEMENTCARTE_H

#include <iostream>
#include "Paiement.h"

class PaiementCarte : public Paiement {
public:
    void effectuerPaiement(double montant) override {
        std::cout << "Paiement de " << montant << " DH par carte bancaire." << std::endl;
    }
};

#endif
