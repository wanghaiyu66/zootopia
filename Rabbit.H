#ifndef Rabbit_H 
#define Rabbit_H

#include <iostream>
#include "Map.H"
#include "Grass.H"
using namespace std;

class Rabbit
{
    bool isAlive_;
    bool isEating_;
    const Map& map_;
    double hpLimit_;
    double hp_;
    double starvingRate_; // per sec
    double eatingRate_;
    int ageLimit_; // days
    double age_;   // seconds
public:
    // constructors
    Rabbit(Map map);

    ~Rabbit()
    {
        cout<< "destoying a Rabbit class." << endl;
    };

    // public member functions
    bool isAlive();
    void starving();
    void eat(Grass& grass);
};


#endif 