// Die Game
// uva 10409
// AC

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Dice
{
    int top, bottom, north, east, west, south;
    
    Dice() {
        top = 1;
        north = 2;
        west = 3;
        east = 4;
        south = 5;
        bottom = 6;
    }

    void rotate(string d) {
        if (d == "north") {
            int temp = top;
            top = south;
            south = bottom;
            bottom = north;
            north = temp;
            // west = west
            // east = east
        }
        else if (d == "east") {
            int temp = top;
            top = west;
            west = bottom;
            bottom = east;
            east = temp;
            // north = north 
            // south = south
        }
        else if (d == "west") {
            int temp = top;
            top = east;
            east = bottom;
            bottom = west;
            west = temp;
            // north = north 
            // south = south
        }
        else if (d == "south") {
            int temp = top;
            top = north;
            north = bottom;
            bottom = south;
            south = temp;
            // west = west
            // east = east
        }
    }

};

int main() {
    //   2
    // 3 1 5 (6 in bottom)
    //   4
    int n;
    while (cin >> n && n) {
        Dice D;

        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            D.rotate(s);
        }

        cout << D.top << '\n';
    }
    
    return 0;
}