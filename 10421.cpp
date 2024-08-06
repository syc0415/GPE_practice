// All You Need Is Love
// uva 10193
// AC

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binaryStringToInt(string s) {
    int num = 0;
    for(int i = 0; i < s.length(); ++i) {
        num *= 2;
        num += s[i] - '0';
    }
    return num;
}

int gcd(int a, int b) {
    // 永遠讓 a是被除數、b是除數 (a > b)
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }

    return a; // b一定是0
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        int n1 = binaryStringToInt(s1);
        int n2 = binaryStringToInt(s2);

        int love = gcd(n1, n2);
        cout << "Pair #" << i + 1 << ": ";
        if (love != 1)
            cout << "All you need is love!\n";
        else
            cout << "Love is not all you need!\n";
        
    }
    
    return 0;
}