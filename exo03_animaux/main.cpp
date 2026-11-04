#include <iostream>
#include <vector>
#include "Chien.h"
#include "Chat.h"
#include "Vache.h"
using namespace std;

int main() {
    vector<Animal*> animaux;
    animaux.push_back(new Chien());
    animaux.push_back(new Chat());
    animaux.push_back(new Vache());
    animaux.push_back(new Chien());

    for (size_t i = 0; i < animaux.size(); i++) {
        animaux[i]->info();
        animaux[i]->crier();
        cout << "-----" << endl;
    }

    for (size_t i = 0; i < animaux.size(); i++)
        delete animaux[i];
    animaux.clear();

    return 0;
}
