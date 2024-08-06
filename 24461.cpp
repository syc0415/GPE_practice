// Sum of Consecutive Prime Numbers
// uva 1210
// AC

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) 
            return false;

    return true;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> prime;
    for (int i = 2; i <= 10000; ++i) {
        if (isPrime(i))
            prime.push_back(i);
    }

    int n;
    while (cin >> n && n) {
        int sum = 0;
        int cur = 0; // cur idx
        int begin = 0; // begin of the adding prime
        int count = 0;
        while (prime[cur] <= n) {
            sum += prime[cur];
            cur++;
            while (sum > n)
                sum -= prime[begin++];
            if (sum == n)
                count++;
        }

        cout << count << '\n';
    }

    return 0;
}