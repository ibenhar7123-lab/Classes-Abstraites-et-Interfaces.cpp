#include <iostream>
#include <string>
#include "Fichier.h"
#include "Dossier.h"
using namespace std;

int main() {
    Dossier racine("racine");   // detruit automatiquement (et ses enfants) a la fin du main

    int choix = -1;
    while (choix != 0) {
        cout << "\n===== SYSTEME DE FICHIERS VIRTUEL =====" << endl;
        cout << "1. Creer un fichier" << endl;
        cout << "2. Creer un dossier" << endl;
        cout << "3. Afficher l'arborescence" << endl;
        cout << "4. Afficher la taille d'un dossier" << endl;
        cout << "0. Quitter" << endl;
        cout << "Choix : ";
        if (!(cin >> choix)) {
            cin.clear();
            cin.ignore(10000, '\n');
            choix = -1;
            cout << "Choix invalide." << endl;
            continue;
        }
        cin.ignore(10000, '\n');

        if (choix == 1 || choix == 2) {
            string parent, nom;
            cout << "Dossier parent (ex : racine) : ";
            getline(cin, parent);
            Dossier* d = racine.chercherDossier(parent);
            if (d == nullptr) {
                cout << "Dossier '" << parent << "' introuvable." << endl;
                continue;
            }
            cout << "Nom : ";
            getline(cin, nom);
            if (nom.empty()) {
                cout << "Nom vide refuse." << endl;
                continue;
            }

            NoeudFichier* nouveau = nullptr;
            if (choix == 1) {
                int taille;
                cout << "Taille (Ko) : ";
                if (!(cin >> taille) || taille < 0) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Taille invalide." << endl;
                    continue;
                }
                cin.ignore(10000, '\n');
                nouveau = new Fichier(nom, taille);
            } else {
                nouveau = new Dossier(nom);
            }

            if (d->ajouter(nouveau))
                cout << "Ajoute dans '" << parent << "'." << endl;
            else
                cout << "Un element nomme '" << nom << "' existe deja dans '" << parent << "'." << endl;
        } else if (choix == 3) {
            racine.afficher();
        } else if (choix == 4) {
            string nom;
            cout << "Nom du dossier : ";
            getline(cin, nom);
            Dossier* d = racine.chercherDossier(nom);
            if (d == nullptr)
                cout << "Dossier '" << nom << "' introuvable." << endl;
            else
                cout << "Taille totale de '" << nom << "' : " << d->taille() << " Ko" << endl;
        } else if (choix != 0) {
            cout << "Choix invalide." << endl;
        }
    }

    return 0;
}
