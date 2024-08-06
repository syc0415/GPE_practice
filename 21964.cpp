// Fill the Containers
// uva 11413
// AC

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
 
int capacity[1000];
 
int container_num(int total, int curCapacity) {
	int sum = 0, count = 1;
	for (int i = 0; i < total; i++) {
		if (sum + capacity[i] > curCapacity) {
			sum = capacity[i];
			count ++;
		}
        else
			sum += capacity[i];
	}

	return count;
}
 
int main()
{
	int n, m;
	while (cin >> n >> m) {
        for (int i = 0; i < 1000; i++)
            capacity[i] = 0;
        
		int sum = 0, largest = 0;
		for (int i = 0; i < n; i++) {
			cin >> capacity[i];
			sum += capacity[i];

			if (largest < capacity[i]) 
				largest = capacity[i];
		}
		
		int l = largest, r = sum; // current container's capacity
		while (l < r) {
			int mid = (l + r) / 2;
			if (container_num(n, mid) > m) 
                l = mid + 1;
            else 
				r = mid;
		}
		
		cout << l << '\n';
	}

	return 0;
}