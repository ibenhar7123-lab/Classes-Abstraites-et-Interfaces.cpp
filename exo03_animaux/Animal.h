#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {
public:
    virtual void crier() const = 0;   // methode pure

    void info() const {               // methode non abstraite, heritee telle quelle
        std::cout << "Je suis un animal." << std::endl;
    }

    virtual ~Animal() {}
};

#endif
