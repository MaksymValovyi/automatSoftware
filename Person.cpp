#include "Person.h"
#include "Card.h"

Person::Person(int Pin) 

{
    privateCard = new Card(Pin);
    cartePin = privateCard->get_pin();
}

Person::~Person(){
    delete privateCard;
    delete this;
}

int Person::get_pin(){
    return cartePin;
}
int Person::get_pin() const{
    return cartePin;
}

int Person::getCardErlaubteNummer(){
    return privateCard->cardNumber;
}
void Person::cardEinfuehren(){
    cout << "Karte ist eingefuehrt" << endl;

}

void Person::cardEntnehmen(){
    cout << "Karte wird entnommen" << endl;
}


