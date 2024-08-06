// Bee Maja
// uva 10182
// AC

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define SIZE 100000

struct point {
    int x, y;
};

struct point p[SIZE + 1];
int index;

void create() {
    p[1].x = 0, p[1].y = 0;

    int step; // 要走幾步，或是第幾圈
    int curX = 0, curY = 0;
    for (step = 1, index = 2; index <= SIZE; step++) {
        for (int count = 0; count < step && index <= SIZE; count++, index++) { // 往下
            p[index].x = curX;
            p[index].y = ++curY;
        }
        for (int count = 0; count < step - 1 && index <= SIZE; count++, index++) { // 往左下
            p[index].x = --curX;
            p[index].y = ++curY;
        }
        for (int count = 0; count < step && index <= SIZE; count++, index++) { // 往左上
            p[index].x = --curX;
            p[index].y = curY;
        }
        for (int count = 0; count < step && index <= SIZE; count++, index++) { // 往上
            p[index].x = curX;
            p[index].y = --curY;
        }
        for (int count = 0; count < step && index <= SIZE; count++, index++) { // 往右上
            p[index].x = ++curX;
            p[index].y = --curY;
        }
        for (int count = 0; count < step && index <= SIZE; count++, index++) { // 往右下
            p[index].x = ++curX;
            p[index].y = curY;
        }
        // 繞完當前一圈
    }
}

int main() {
    create();
    
    int n;
    while (cin >> n && n)
        cout << p[n].x << " " << p[n].y << '\n';

    return 0;
}