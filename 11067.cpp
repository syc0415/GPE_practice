// Cola
// uva 11150
// AC

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while (cin >> n && n) {
        int total = n;
        while (n / 3 >= 1) {
            total += n / 3;
            n = (n / 3) + (n % 3);
        }

        if (n == 2) // 可以借一瓶
            total++;

        cout << total << '\n';
    }

    return 0;
}