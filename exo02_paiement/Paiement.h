#ifndef PAIEMENT_H
#define PAIEMENT_H

class Paiement {
public:
    virtual void effectuerPaiement(double montant) = 0;
    virtual ~Paiement() {}
};

#endif
