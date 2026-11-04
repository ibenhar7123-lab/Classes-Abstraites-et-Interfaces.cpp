#ifndef FORME_H
#define FORME_H

class Forme {
public:
    virtual double aire() const = 0;   // methode virtuelle pure
    virtual ~Forme() {}
};

#endif
