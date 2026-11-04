#ifndef VACHE_H
#define VACHE_H

#include "Animal.h"

class Vache : public Animal {
public:
    void crier() const override { std::cout << "Meuh !" << std::endl; }
};

#endif
