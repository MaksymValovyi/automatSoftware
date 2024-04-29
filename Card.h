#include <iostream>
#include <ctime>
using namespace std;

class Card
{
private:
    int pin;
public:
    Card(int randomPin): pin(randomPin) {};

    int get_pin();
};


