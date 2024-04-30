#include "Card.h"

#ifndef PERSON_H
#define PERSON_H

class Person
{
private:
    Card *privateCard; 
    int cartePin;
    float cash;
public:
    Person(int);
    ~Person();

    int getCardErlaubteNummer(){
        return privateCard->cardNumber;
    }

    int get_pin(){
        return cartePin;
    }

    int get_pin() const{
        return cartePin;
    }
    void amountCash();
    void cardEinfuehren();
    void cardEntnehmen();
    void geldErhalten(float);
};

#endif
