#include <iostream>
#include "PaiementCarte.h"
#include "PaiementEspece.h"
using namespace std;

int main() {
    const int N = 4;
    Paiement* paiements[N];
    paiements[0] = new PaiementCarte();
    paiements[1] = new PaiementEspece();
    paiements[2] = new PaiementCarte();
    paiements[3] = new PaiementEspece();

    double montants[N] = { 250.0, 99.5, 1200.0, 40.0 };

    // Polymorphisme : le bon effectuerPaiement() est appele a l'execution
    for (int i = 0; i < N; i++)
        paiements[i]->effectuerPaiement(montants[i]);

    for (int i = 0; i < N; i++)
        delete paiements[i];

    return 0;
}
