// A mid-summer night’s dream
// uva 10057
// AC

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n && n) {
        vector<int> numbers(n);
        for (int i = 0; i < n; i++)
            cin >> numbers[i];
        
        sort(numbers.begin(), numbers.end());
        
        int mid1, mid2;
        if (n % 2 == 0) {
            mid1 = numbers[(n - 1) / 2];
            mid2 = numbers[n / 2];
        }
        if (n % 2 == 1) {
            mid1 = numbers[n / 2];
            mid2 = mid1;
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (numbers[i] == mid1 || numbers[i] == mid2)
                count++;
        }

        int diff;
        diff = mid2 - mid1 + 1;

        cout << mid1 << " " << count << " " << diff << '\n';
    }


    return 0;
}