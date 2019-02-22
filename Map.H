#include <iostream>
using namespace std;

class Map
{
    int width_;
    int height_;
public:
    // constructor
    Map(int width, int height);
    ~Map(){};
    
    // public member function
    int getWidth() const
    {
        return width_;
    }

    int getHeight() const
    {
        return height_;
    }
};