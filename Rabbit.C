#include "Rabbit.H"
Rabbit::Rabbit(Map map)
:
    isAlive_(true),
    isEating_(false),
    map_(map),
    hp_(5.0),
    hpLimit_(5.0),
    starvingRate_(1.0/3600/24),
    eatingRate_(0.1/3600), // 1 hour per grass
    ageLimit_(100),
    age_(0.0)
{
    cout<< "creating a rabbit." << endl;
}

bool Rabbit::isAlive()
{
    if(hp_<=0.0 || age_/(24*3600)>=ageLimit_)
    {
        isAlive_ = false;
    }

    return isAlive_;
}

void Rabbit::starving()
{
    hp_ -= starvingRate_;
}

void Rabbit::eat(Grass& grass)
{
    if (hp_ < hpLimit_ && !grass.isSleep())
    {
        hp_ += eatingRate_;
        grass.hp_ -= eatingRate_;
        //cout<< grass.hp_ << endl;
    }
    if (hp_ >= hpLimit_)
    {
        hp_ = hpLimit_;
    }
}