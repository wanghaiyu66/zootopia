#include "Rabbit.H"
Rabbit::Rabbit(const Map& map)
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

Rabbit::Rabbit(const Map& map, const vector<int>& pos)
:
    isAlive_(true),
    isEating_(false),
    map_(map),
    hp_(5.0),
    hpLimit_(5.0),
    starvingRate_(1.0/3600/24),
    eatingRate_(0.1/3600), // 1 hour per grass
    ageLimit_(100),
    age_(0.0),
    pos_(pos)
{
    cout<< "creating a rabbit." << endl;
}

void Rabbit::run()
{
    default_random_engine e;
    uniform_int_distribution<unsigned> u(0, 7);
    
    
}

void Rabbit::view()
{
    vector<int> next(pos_);
    int w = map_.getWidth();

    view_.push_back(pos_); // 0
    next[0] += 1;
    if(next[0]>=0&&next[1]>=0)
    {
        view_.push_back(next); // 1
    }
    next[1] += 1;
    if(next[0]>=0&&next[1]>=0)
    {
        view_.push_back(next); // 2
    }
    next[0] -= 1;
    if(next[0]>=0&&next[1]>=0)
    {
        view_.push_back(next); // 3
    }
    next[0] -= 1;
    if(next[0]>=0&&next[1]>=0)
    {
        view_.push_back(next); // 4
    }
    next[1] -= 1;
    if(next[0]>=0&&next[1]>=0)
    {
        view_.push_back(next); // 5
    }
    next[1] -= 1;
    if(next[0]>=0&&next[1]>=0)
    {
        view_.push_back(next); // 6
    }
    next[0] += 1;
    if(next[0]>=0&&next[1]>=0)
    {
        view_.push_back(next); // 7
    }
    next[0] += 1;
    if(next[0]>=0&&next[1]>=0)
    {
        view_.push_back(next); // 8
    }

    /*for(const auto &row :view_)
    {
        for(int x : row)
        {
            cout<< x << ' ';
        }
        cout<< endl;
    }*/
    
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