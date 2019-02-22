#ifndef Grass_H 
#define Grass_H
class Grass
{
    double hpLimit_;

    double growingRate_; // per sec. 
    bool isSleep_;
public:
    double hp_;
    // constructors
    Grass();
    ~Grass(){};
    // public member functions
    bool isSleep();
    //void beEaten();
};

#endif