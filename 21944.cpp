// Power Crisis
// uva 151
// AC

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // f(n) = [f(n-1) + m] % n
    int N;
    while (cin >> N && N) {
        for (int m = 1; m < N; m++) {
            // m 是間隔
            /* 
            每經過一輪，最終活下里的那個人，他的編號就會往前 m 個
            反過來想，人數每增加一個，活下來的那個人的編號就要往後 + m，
            因爲是循環的形式，所以我們 % n。
            */
            int turnoff = 0; // 被選的那個
            for (int n = 1; n < N; n++) // 總共N人 只會有N-1輪
                turnoff = (turnoff + m) % n;
            
            if (turnoff == 11) { 
                // 最後一個是region 13 (index = 11)
                // 扣掉第一個不算(必關), region 13的index是11
                cout << m << '\n';
                break;
            }       
        }   
    }

    return 0;
}