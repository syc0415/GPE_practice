// The Hotel with Infinite Rooms
// uva 10170
// AC

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long s, d;
    while (cin >> s >> d) {
        while (d > 0) {
            d -= s;
            s++;
        }
        s--;

        cout << s << '\n';
        
        // d -= s
        // if(d <= 0) {
        //     cout << s << endl;
        //     break;
        // }
        // else
        //     s++;
    }
    
    return 0;
}