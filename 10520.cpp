// Conformity
// uva 11286
// AC

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n;
    while (cin >> n && n) {
        map<string, int> combination; // 不同組合的計數
        
        for (int i = 0; i < n; i++) {
            vector<string> course(5);
            for (int j = 0; j < 5; j++)
                cin >> course[j];

            sort(course.begin(), course.end());
            
            string s = "";
            for (int j = 0; j < 5; ++j) 
                s += course[j];
            
            combination[s]++;
        }

        int max = 0;
        int total = 0;
        for (auto it = combination.begin(); it != combination.end(); it++) {
            if (it->second > max) {
                max = it->second;
                total = max;
            }
            else if (it->second == max) // 有可能兩種組合都是最大
                total += max;
        }

        cout << total << '\n';
    }
    
    return 0;
}