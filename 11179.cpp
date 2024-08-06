//Wavio Sequence
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long seq[10000];

int bs (int l, int r, int n) {
    int mid = r / 2;
    while (l < r) {
        mid = l + r / 2;
        if (seq[mid] < n)
            l = mid;
        else
            r = mid;
    }

    return r;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int n;
    while (cin >> n && n) {
        if (cin.eof()) return 0;
        
        for (int i = 0; i < n; ++i)
            cin >> seq[i]; 
        
        int Ltail = -1;
        long increase[10000] = {0}
        for (int i = 1; i < n; ++i) {
            if (seq[i] > )
        }





        long decrease[10000] = {0};
        increase[0] = 1; decrease[n - 1] = 1; 
        long inMax = seq[0], deMax = seq[n - 1];
        for (int i = 1; i < n; ++i) {
            if (seq[i] > inMax) {
                increase[i] = increase[i - 1] + 1;
                inMax = seq[i];
            }
            else
                increase[i] = increase[i - 1];
        }

        for (int i = n - 2; i >= 0; --i) {
            if (seq[i] > deMax) {
                decrease[i] = decrease[i + 1] + 1;
                deMax = seq[i];
            }
            else
                decrease[i] = decrease[i + 1];
        }

        long max = 0;
        for (int i = 0; i < n; ++i) {
            if (increase[i] + decrease[i] - 1 > max)
                max = increase[i] + decrease[i] - 1;
        }

        cout << max << '\n';
    }

    return 0;
}