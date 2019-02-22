#include "Grass.H"
Grass::Grass()
:
    hpLimit_(0.1),
    hp_(0.1),
    growingRate_(0.1/24/3600), //recover full hp in 1 day
    isSleep_(false)
{}

bool Grass::isSleep()
{
    if (hp_ <= 0.0)
    {
        isSleep_ = true;
    }
    return isSleep_;
}

/*void Grass::beEaten()// need the type of eater
{
    if (!isSleep_)
    {
        hp_ -= 
    }
}*/