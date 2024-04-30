#include "Person.h"

class Automat
{
private:
    int geldAnzahl;
    int anzahlGesperrteKarten = 0;
public:
    Automat(int Anzahl): geldAnzahl(Anzahl) {};

    int erlaubteCardNummer = 4444;

    void increaseAnzahlKarten();
    int get_geldAnzahl(){
        return geldAnzahl;
    }
    bool checkCard(int);
    void karteAuswerfen();
    void pinEingabeProcess(int versuche, Person &person);
    void betragAuswahl(Person &person);
    void betragAuszahlen(float, Person &person);
};

