// Bachet's Game
// uva 10404
// AC

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool dp[1000001]; // total stones
    int n, m, k[10];

    while (cin >> n && n) {
        cin >> m;
        for (int i = 0; i < m; i++)
            cin >> k[i]; // available moves
        
        dp[0] = false;
        for (int i = 1; i <= n; i++) {
            dp[i] = false;
            for (int j = 0; j < m; j++)
                if (i >= k[j] && !dp[i - k[j]]) {
                    // lose at (i - k[j]) stones (the other's move ends)
                    // so now is our move, take away k[j] stones can win
                    dp[i] = true;
                    break;
                }
        }
        
        // Stan first, so true = Stan's win
        if (dp[n])
            cout << "Stan wins\n";
        else
            cout << "Ollie wins\n";
    }

    return 0;
}