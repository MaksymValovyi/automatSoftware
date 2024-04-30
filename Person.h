#include "Card.h"

#ifndef PERSON_H
#define PERSON_H

class Person
{
private:
    Card *privateCard; 
    int cartePin;
public:
    Person(int);
    ~Person();

    int getCardErlaubteNummer();
    int get_pin();
    int get_pin() const;
    void cardEinfuehren();
    void cardEntnehmen();
};

#endif
