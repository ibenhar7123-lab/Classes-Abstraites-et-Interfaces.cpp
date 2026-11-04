#ifndef NOEUDFICHIER_H
#define NOEUDFICHIER_H

#include <iostream>
#include <string>

class NoeudFichier {
protected:
    std::string nomNoeud;

public:
    NoeudFichier(const std::string& nom) : nomNoeud(nom) {}
    virtual ~NoeudFichier() {}

    std::string nom() const { return nomNoeud; }

    virtual int taille() const = 0;                  // methode pure (en Ko)
    virtual void afficher(int niveau = 0) const = 0; // affichage de l'arborescence
};

#endif
