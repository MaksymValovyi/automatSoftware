#include <iostream>
#include <unistd.h>

#include "Automat.cpp"
#include "Card.cpp"
#include "Person.cpp"

using namespace std;

int Anzahl = 1000;
int option;

int random_number(){
    srand(time(NULL));
    int randomNumber = rand() % 9000 + 1000;
    return randomNumber;
}

int main(int argc, char const *argv[])
{
    Automat automat(Anzahl);
    /*
    cout << "-----------Admin Message-----------" << endl;
    cout << "Geld in Automat: " << automat.get_geldAnzahl() << endl;
    cout << "---------End Admin Message---------" << endl;
    */

    while (1==1){
    cout << "-----------Admin Message-----------" << endl;
    cout << "Geld in Automat: " << automat.get_geldAnzahl() << endl;
    cout << "---------End Admin Message---------" << endl;
    //////////////////////////////////////////////
    if(automat.get_geldAnzahl() == 0){
        cout << "Automat ist leer" << endl;
        exit(0);
        break;
    }
    cout  << endl << "1. Card Einfuehren" << endl;
    cout << "2. Ruhe" << endl;
    cout << "3. Exit" << endl;
    cin >> option;
        switch(option){
            case 1:
            {
                //Card bankCard(random_number());
                Person *person = new Person(random_number());
                cout << endl << "-----------Admin Message-----------" << endl;
                cout << "Pin code is : " << person->get_pin() << endl;
                cout << "---------End Admin Message---------" << endl << endl;
                

                cout << endl << "Karte Einfuehren ? " << endl;
                cout << "1. Ja" << endl;
                cout << "2. Nein" << endl;
                cin >> option;
                switch(option){
                    case 1:
                    {
                        person->cardEinfuehren();
                        int result = automat.checkCard(person->getCardErlaubteNummer());
                        if(result == true){
                            int versuch=0;
                            cout << "------------------" << endl;
                            cout << "Pruefung bestanden" << endl;
                            cout << "------------------" << endl;
                            automat.pinEingabeProcess(versuch, *person);

                            person->amountCash();
                        }else{
                            automat.karteAuswerfen();
                            person->cardEntnehmen();
                        }
                        break;
                    }    
                    case 2:
                    {
                        break;
                    }       
                }
                break;
            }
            case 2:
            {
                cout << "--------------Ruhe---------------" << endl;
                //sleep(50);
                break;
            }
            case 3:
            {
                cout << "---------------Bye---------------" << endl;
                exit(0);
                break;
            }
            default :
            {
                cout << endl << "Incorrect Variable" << endl << endl;
                break;
            }
        }
    }
    return 0;
}


