#ifndef CERCLE_H
#define CERCLE_H

#include "Forme.h"

class Cercle : public Forme {
private:
    double rayon;

public:
    Cercle(double rayon) : rayon(rayon) {}

    double aire() const override {
        const double PI = 3.14159265358979323846;
        return PI * rayon * rayon;
    }
};

#endif
