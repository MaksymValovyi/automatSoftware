#include "Person.h"
#include "Card.h"

Person::Person(int Pin) 
{
    privateCard = new Card(Pin);
    cartePin = privateCard->get_pin();
}

Person::~Person(){
    delete privateCard;
}

void Person::cardEinfuehren(){
    cout << "---------------------" << endl;
    cout << "Karte ist eingefuehrt" << endl;
    cout << "---------------------" << endl;

}

void Person::cardEntnehmen(){
    cout << "--------------------" << endl;
    cout << "Karte wird entnommen" << endl;
    cout << "--------------------" << endl;
}

/**
 * Adds the specified amount of money to the person's cash balance.
 *
 * @param summe The amount of money to be added.
 */
void Person::geldErhalten(float summe){
    cash+=summe;
}

void Person::amountCash(){
    cout << "Ich habe " << cash  << " Euro" << endl;    
}


