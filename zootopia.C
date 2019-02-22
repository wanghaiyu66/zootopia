#include "Grass.H"
#include "Rabbit.H"
#include <iostream>

int main()
{
    // parameters
    int nDays = 10;

    Map map(100, 100);
    vector<int> pos={1,0};
    Rabbit a(map, pos);
     a.view();
    Grass g;
    // days
    for (int i = 0; i < nDays; i++)
    {
        for (int j = 0; j < 24; j++)
        {
            for (int k = 0; k < 3600; k++)
            {
                a.starving();
                a.eat(g);
               
                a.run();
                if (!a.isAlive())
                {
                    cout<< "The rabbit died in day "
                        << i << " " << j << "h " << k << "s."
                        << endl;
                    i = nDays+1;
                    j = 25;
                    k = 3601;
                }
            }
        }
    }
    

    return 0;
}