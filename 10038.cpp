// Disk Tree
// uva 1556
// AC 但不會

#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
const int maxn = 50005;

struct Tire {
    int size;
    map<string, int> disk[maxn]; // name, depth
 
    void init();
    void insert(string s);
    void put(int u, int d);
};

Tire tree;

void Tire::init() {
    size = 1;
    disk[0].clear();
}
 
void Tire::insert(string s) {
    int u = 0;
    string word = "";
 
    for (int i = 0; i < s.length(); i++) {
        while (s[i] != '\\') { // actually means '\'
            word += s[i];
            i++;
        }

        if (!disk[u].count(word)) { // first appearance
            disk[size].clear();
            disk[u][word] = size++;
        }

        u = disk[u][word];
        word = "";
    }
}
 
void Tire::put (int u, int d) {
    for (auto i = disk[u].begin(); i != disk[u].end(); i++) {
        for (int j = 0; j < d; j++)
            cout << " ";
        cout << i->first << endl;
        put(i->second, d + 1);
    }
}

int main () {
    int n;
    string s;
    while (cin >> n && n) {
        tree.init();
        for (int i = 0; i < n; i++) {
            cin >> s;
            s += '\\';
            tree.insert(s);
        }
        tree.put(0, 0);
        cout << '\n';
    }
     
    return 0;
}