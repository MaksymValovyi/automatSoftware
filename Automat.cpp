#include "Automat.h"
using namespace std;

int Automat::get_geldAnzahl(){
    return geldAnzahl;
}

bool Automat::checkCard(int cardNumber){
    if(erlaubteCardNummer==cardNumber){
        cout << "Code Passt" << endl;
        return true;
    }else{
        cout << "Code Passt NICHT" << endl;
        return false;
    }
}

void Automat::karteAuswerfen(){
    cout << "Karte wird ausgewerft" << endl;
}

void Automat::pinEingabeProcess(int versuche, const Person &person){
    cout << endl << "Geben Sie Ihr Pin" << endl;
    int pin;
    cin >> pin;
    while(pin!=person.get_pin() && versuche <3){
        versuche++;

    }
    if (pin == person.get_pin()){
        cout << "Pin ist correct" << endl;
    }else if(pin!=person.get_pin() && versuche <=3){

    }else{

    }
}