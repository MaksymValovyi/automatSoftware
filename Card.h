#include <iostream>
#include <ctime>
using namespace std;

#ifndef CARD_H
#define CARD_H

int erlaubteCardNumber = 4444;

class Card 
{
private:
    int pin;
public:
    Card(int randomPin): pin(randomPin) {};
    ~Card(){
        delete this;
    };

    int cardNumber = erlaubteCardNumber;

    int get_pin();
};

#endif
