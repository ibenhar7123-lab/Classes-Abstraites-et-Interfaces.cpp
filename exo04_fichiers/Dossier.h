#ifndef DOSSIER_H
#define DOSSIER_H

#include <vector>
#include "NoeudFichier.h"

class Dossier : public NoeudFichier {
private:
    std::vector<NoeudFichier*> enfants;

public:
    Dossier(const std::string& nom) : NoeudFichier(nom) {}

    // Le dossier est proprietaire de ses enfants : il les libere
    ~Dossier() {
        for (size_t i = 0; i < enfants.size(); i++)
            delete enfants[i];
    }

    // Ajoute un enfant (refuse si un enfant porte deja ce nom)
    bool ajouter(NoeudFichier* noeud) {
        for (size_t i = 0; i < enfants.size(); i++) {
            if (enfants[i]->nom() == noeud->nom()) {
                delete noeud;
                return false;
            }
        }
        enfants.push_back(noeud);
        return true;
    }

    // Taille = somme des tailles des enfants (recursif grace au polymorphisme)
    int taille() const override {
        int total = 0;
        for (size_t i = 0; i < enfants.size(); i++)
            total += enfants[i]->taille();
        return total;
    }

    void afficher(int niveau = 0) const override {
        std::cout << std::string(niveau * 2, ' ') << "+ " << nomNoeud
                  << "/ (" << taille() << " Ko)" << std::endl;
        for (size_t i = 0; i < enfants.size(); i++)
            enfants[i]->afficher(niveau + 1);
    }

    // Cherche un dossier par nom (lui-meme ou un sous-dossier, en profondeur)
    Dossier* chercherDossier(const std::string& nom) {
        if (nomNoeud == nom) return this;
        for (size_t i = 0; i < enfants.size(); i++) {
            Dossier* d = dynamic_cast<Dossier*>(enfants[i]);
            if (d != nullptr) {
                Dossier* trouve = d->chercherDossier(nom);
                if (trouve != nullptr) return trouve;
            }
        }
        return nullptr;
    }
};

#endif
