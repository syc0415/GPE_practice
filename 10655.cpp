// sumsets
// uva 10125
// AC

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sol(vector<int>& set) {
    for (int d = set.size() - 1; d >= 0; d--) {
        // find the largest d, so begin from back
        for (int a = 0; a < set.size(); a++) {
            for (int b = a + 1; b < set.size(); b++) {
                for (int c = b + 1; c < set.size(); c++) {
                    // b = a + 1, c = b + 1, 這樣就不會重複
                    // (但還是要注意d)
                    if ((set[d] == set[a] + set[b] + set[c]) 
                        && a != d && b != d && c != d)
                        return set[d];
                }
            }
        }
    }

    return -9999999;
}

int main() {
    int n;
    while (cin >> n && n) {
        vector<int> set(n);
        for (int i = 0; i < n; i++)
            cin >> set[i];

        sort(set.begin(), set.end());

        // find d = a + b + c
        int d = sol(set);
        if (d == -9999999)
            cout << "no solution\n";
        else
            cout << d << "\n";
    }

    return 0;
}