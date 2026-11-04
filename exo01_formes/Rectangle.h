#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Forme.h"

class Rectangle : public Forme {
private:
    double longueur;
    double largeur;

public:
    Rectangle(double longueur, double largeur) : longueur(longueur), largeur(largeur) {}

    double aire() const override {
        return longueur * largeur;
    }
};

#endif
