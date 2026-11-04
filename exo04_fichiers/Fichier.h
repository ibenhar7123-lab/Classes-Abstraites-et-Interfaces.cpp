#ifndef FICHIER_H
#define FICHIER_H

#include "NoeudFichier.h"

class Fichier : public NoeudFichier {
private:
    int tailleKo;

public:
    Fichier(const std::string& nom, int tailleKo) : NoeudFichier(nom), tailleKo(tailleKo) {}

    int taille() const override { return tailleKo; }

    void afficher(int niveau = 0) const override {
        std::cout << std::string(niveau * 2, ' ') << "- " << nomNoeud
                  << " (" << tailleKo << " Ko)" << std::endl;
    }
};

#endif
