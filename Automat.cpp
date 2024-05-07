#include "Automat.h"
using namespace std;

void Automat::increaseAnzahlKarten(){
    anzahlGesperrteKarten++;
    cout << endl << "-----------Admin Message-----------" << endl;
    cout << "Anzahl von gesperrten Karten = " << anzahlGesperrteKarten << endl;
    cout << "---------End Admin Message---------" << endl << endl;
}

bool Automat::checkCard(int cardNumber){
    if(erlaubteCardNummer==cardNumber){
        cout << "----------" << endl;
        cout << "Code Passt" << endl;
        cout << "----------" << endl;
        return true;
    }else{
        cout << "----------------" << endl;
        cout << "Code Passt NICHT" << endl;
        cout << "----------------" << endl;
        return false;
    }
}

void Automat::karteAuswerfen(){
    cout << "Karte wird ausgewerft" << endl;
    //Person::cardEntnehmen();
}

void Automat::pinEingabeProcess(int versuche, Person &person){
    cout << endl << "Options: " << endl;
    cout << "1. Pin eingeben" << endl;
    cout << "2. Abbruch" << endl;
    int option;
    cin >> option;
    switch (option)
    {
    case 1:
    {
        cout << endl << "Geben Sie Ihr Pin" << endl;
        cout << "----------------------" << endl;
        cout << "Write '1' for Abbruch" << endl;
        cout << "----------------------" << endl;
        int pin;
        cin >> pin;
        if(pin==1){
            karteAuswerfen();
            person.cardEntnehmen();
            break;
        }
        while (pin!=person.get_pin() && versuche <2){
            versuche++;
            cout << "----------------------" << endl;
            cout << "Incorrect Pin" << endl;
            cout << "Versuchen Sie noch mal" << endl;
            cout << "----------------------" << endl;
            cin >> pin;
        }
        if (pin==person.get_pin()){
            betragAuswahl(person);
        }else {
            cout << "-------------------" << endl;
            cout << "Karte is eingezogen" << endl;
            cout << "-------------------" << endl;
            increaseAnzahlKarten();
        }
        break;
    }
    case 2:
    {
        karteAuswerfen();
        person.cardEntnehmen();
        break;
    }
    default:
        karteAuswerfen();
        person.cardEntnehmen();
        break;
    }
}

void Automat::betragAuswahl(Person &person){
    cout << endl << "Options: " << endl;
    cout << "1. Betragauswahl" << endl;
    cout << "2. Abbruch" << endl;
    int option;
    cin >> option;
    switch (option)
    {
        case 1:
        {
            //////////////////////////////////////////
            if(geldAnzahl<=0){
                cout << "Automat hat kein Geld" << endl;
                break;
            }
            cout << "Wahlen Sie Ihre Summe" << endl;
            float summe;
            cin >> summe;
            ////////////////////////////////////////// 
            if(summe>geldAnzahl){
                cout << "Automat hat nicht genug Geld" << endl;
                break;
            }
            cout << summe << " Euro wird ausgebucht" << endl << endl;
            betragAuszahlen(summe, person);
            geldAnzahl-=summe;
            break;
        }
        case 2:
        {
            karteAuswerfen();
            person.cardEntnehmen();
            break;
        }
        default:
        {
            karteAuswerfen();
            person.cardEntnehmen();
            break;
        }
    }
}

void Automat::betragAuszahlen(float summe, Person &person){
    cout << summe << " zahlt Automat Ihnnen" << endl << endl;
    person.geldErhalten(summe);
}