// Rank the Languages
// uva 10336
// AC

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char map[1000][1000] = {0};
bool visited[1000][1000] = {false};

void DFS(int h, int w) { // floodfill
    visited[h][w] = true;
    if (map[h][w] == map[h - 1][w] && !visited[h - 1][w])
        DFS(h - 1, w);
    if (map[h][w] == map[h + 1][w] && !visited[h + 1][w])
        DFS(h + 1, w);
    if (map[h][w] == map[h][w - 1] && !visited[h][w - 1])
        DFS(h, w - 1);
    if (map[h][w] == map[h][w + 1] && !visited[h][w + 1])
        DFS(h, w + 1);
    
    return;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        // init
        for (int j = 0; j < 1000; j++) {
            for (int k = 0; k < 1000; k++) {
                map[j][k] = 0;
                visited[j][k] = false;
            }
        }
        
        int h, w;
        cin >> h >> w;
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                char c;
                cin >> c;
                map[j][k] = c;
            }
        }

        int letter[26] = {0};
        int maxarea = 0;
        for(int j = 0; j < h; j++) {
            for(int k = 0; k < w; k++) {
                if(!visited[j][k]) {
                    DFS(j, k);
                    letter[map[j][k] - 'a']++;
                    // update max area (for output order)
                    maxarea = max(maxarea, letter[map[j][k] - 'a']);
                }
            }
        }

        cout << "World #" << i << '\n';
        for (int m = maxarea; m >= 1; m--) {
            for (int t = 0; t < 26; t++) {
                if (letter[t] == m) 
                    cout << char(t + 'a') << ": " << letter[t] << '\n';
            }
        }
    }
    
    return 0;
}