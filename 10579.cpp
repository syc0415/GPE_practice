// Hay Points
// uva 10295
// AC

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    map<string, int> HayPoint;

	string point;
	int value;
	for(int i = 0; i < m; i++) {
		cin >> point >> value;
        // cout << point << value << endl;
		HayPoint[point] = value;
	}

	for (int i = 0; i < n; i++) {
        string s;
		long long salary = 0;
		while (cin >> s) {
            // cout << s << endl;
            if (s == ".")
                break;
			if (HayPoint[s])
                salary += HayPoint[s];
		}

		cout << salary << '\n';
	}	    

    return 0;
}