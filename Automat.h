#include "Person.h"

class Automat
{
private:
    int geldAnzahl;
public:
    Automat(int Anzahl): geldAnzahl(Anzahl) {};

    int erlaubteCardNummer = 4444;

    int get_geldAnzahl();
    bool checkCard(int);
    void karteAuswerfen();
    void pinEingabeProcess(int versuche, const Person &person);
};

