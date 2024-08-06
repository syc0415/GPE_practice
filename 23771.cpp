//Lexicographic Order
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long factorial[21] = {1};
    for (int i = 1; i < 21; ++i)
        factorial[i] = factorial[i - 1] * i;
    
    int n;
    cin >> n;
    int cases = 0;
    while (n--) {
        string s;
        int k;
        cin >> s >> k;
        sort(s.begin(), s.end());

        int l = s.length();
        char alphabet[20];
        int used[20] = {}, ans[20] = {};
        for (int i = 0;  i < l; ++i) {
            int cnt = 0;
            while (k > factorial[l - i - 1]) {

            }
        }

        cout << "Case " << cases++ << ': ' << 0;


    }
    return 0;
}