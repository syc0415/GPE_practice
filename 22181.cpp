// Dollars
// uva 147
// AC

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    long long dp[30005] = {0};
    int currency[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
    // {100, 50, 20, 10, 5, 2, 1, 0.5, 0.2, 0.1, 0.05};
    // index要是整數，所以全部x100

    dp[0] = 1;
    for (int i = 0; i < 11; i++) {
        for (int j = currency[i]; j <= 30000; j += 5) { // !! j+=5
            dp[j] += dp[j - currency[i]];
        }
    }

    double money;
    while (cin >> money && money) {
        long n = 100 * money + 0.5; // !!important!!
        cout << fixed << setprecision(2) << setw(6) << money;
        cout << setw(17) << dp[n] << '\n';
    }
    
    return 0;
}