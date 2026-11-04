#include <iostream>
#include "Cercle.h"
#include "Rectangle.h"
using namespace std;

// Lit un nombre strictement positif (redemande tant que la saisie est invalide)
double lirePositif(const string& message) {
    double v;
    cout << message;
    while (!(cin >> v) || v <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Valeur invalide (nombre > 0). " << message;
    }
    return v;
}

int main() {
    int n;
    cout << "Combien de formes ? ";
    while (!(cin >> n) || n <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Nombre invalide (entier > 0). Recommencez : ";
    }

    // Tableau dynamique de pointeurs vers Forme
    Forme** formes = new Forme*[n];

    for (int i = 0; i < n; i++) {
        int type = 0;
        cout << "\nForme " << i + 1 << " : 1 = Cercle, 2 = Rectangle : ";
        while (!(cin >> type) || (type != 1 && type != 2)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Choix invalide. 1 = Cercle, 2 = Rectangle : ";
        }

        if (type == 1) {
            double r = lirePositif("  Rayon : ");
            formes[i] = new Cercle(r);
        } else {
            double L = lirePositif("  Longueur : ");
            double l = lirePositif("  Largeur : ");
            formes[i] = new Rectangle(L, l);
        }
    }

    cout << "\n=== Aires ===" << endl;
    for (int i = 0; i < n; i++)
        cout << "Forme " << i + 1 << " : aire = " << formes[i]->aire() << endl;

    for (int i = 0; i < n; i++)
        delete formes[i];
    delete[] formes;

    return 0;
}
