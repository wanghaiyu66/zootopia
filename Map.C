#include "Map.H"

Map::Map(int width, int height)
:
    width_(width),
    height_(height)
{
    cout<< "generating the map, "
        << width_ << " by " 
        << height_ << "..." << endl;
}