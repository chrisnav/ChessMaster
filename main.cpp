#include <vector>
#include <iostream>
#include "src\\pieces.h"
using namespace std;


int main()
{
    std::vector<Piece*> vec;

    King p = King(0, 0);

    Piece* test = &p;

    vec.push_back(test);

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {   
            if(i != 0 && i != 0)
                p.move(i, j);

            p.generate_possible_moves();

            cout << "King at (" << i << "," << j << ")" << endl;

            int n = p.possible_x.size();
            for (int i = 0; i < n; ++i)
            {
                cout << "\t"
                     << "(" << p.possible_x[i] << "," << p.possible_y[i] << ")" << endl;
            }
            cout << endl;
        }
    }
}