//Zipf's Law
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main() {
    int n;
    while (cin >> n && n) {
        string line;
        getline(cin, line); // empty \n
        map <string, int> times;
        while (getline(cin, line)) {
            if (line == "EndOfText") break;
            
            string tmp = "";
            int l = line.length();
            for (int i = 0; i < l; ++i) {
                if (isalpha(line[i])) {
                    if (isupper(line[i]))
                        line[i] = tolower(line[i]);
                
                    tmp += line[i];
                }
                else if (tmp.length() > 0) {
                    times[tmp]++;
                    tmp = "";
                }
            }    
        }

        bool flag = false;
        for (auto it = times.begin(); it != times.end(); ++it) {
            if (it->second == n) {
                cout << it->first << '\n';
                flag = true;
            }
        }
        if (flag == false)
            cout << "There is no such word.\n";
        
        cout << '\n';
    }
    
    return 0;
}