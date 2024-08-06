// Robot Instructions
// uva 12503
// AC

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int n, instr[100];
        cin >> n;
        string s;
        getline(cin, s);
        for (int j = 0; j < n; ++j) {
            string move;
            getline(cin, move);
            if (move == "LEFT")
                instr[j] = -1;
            else if (move == "RIGHT")
                instr[j] = 1;
            else {
                int idx = 0;
                for (int k = 8; k < move.length(); k++) {
                    idx *= 10;
                    idx += move[k] - '0';
                }
                
                instr[j] = instr[idx - 1];
            }
        }
        
        int pos = 0;
        for (int t = 0; t < n; ++t)
            pos += instr[t];
        cout << pos << '\n';
    }

    return 0;
}