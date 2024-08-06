// Luggage
// uva 10664
// AC

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main(){
    int m;
    cin >> m;
    string s;
    getline(cin, s); // getline 會讀到cin的\n

    for (int i = 0; i < m; ++i) {
        getline(cin, s);

        vector<int> weight;
        int sum = 0;
        bool dp[201] = {false};

        stringstream ss;
        ss << s;
        int n;
        while (ss >> n) {
            weight.push_back(n);
            sum += n;
        }

        if (sum % 2 != 0) {
            cout << "NO\n";
            continue;
        }
        
        dp[0] = true;
        for (int j = 0; j < weight.size(); j++) {
            for (int k = sum; k >= weight[j]; k--) {
                if (dp[k - weight[j]] == true)
                    dp[k] = true;
                // 如果 (某特定重量-該行李重) 是可以達成的 (由前面推得)
                // 代表有一組合+該行李就可以達成此特定重
                // 須從後面開始遞迴，避免影響到後面
                // (像是某組合+該行李+該行李=true的情況，此行李被count兩次)
            }
        }

        if (dp[sum / 2] == true)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}