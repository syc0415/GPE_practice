// Oil Deposits
// uva 572
// AC

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char grid[100][100];
int m, n;
bool visited[100][100];

void dfs (int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n) // out of bounds
        return;

    if (grid[x][y] != '@' || visited[x][y]) // not a deposit or already visited
        return;

    visited[x][y] = true;
    grid[x][y] = '*'; // not necessary

    dfs(x - 1, y - 1);
    dfs(x - 1, y);
    dfs(x - 1, y + 1);
    dfs(x, y - 1);
    dfs(x, y + 1);
    dfs(x + 1, y - 1);
    dfs(x + 1, y);
    dfs(x + 1, y + 1);

    return;
}

int main() {
    while (1) {
        cin >> m >> n;
        if (m == 0 && n == 0)
            break;
        
        // init
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 100; ++j) {
                grid[i][j] = 0;
                visited[i][j] = false;
            }
        }

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                cin >> grid[i][j];

        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '@' && !visited[i][j]) {
                    count++;
                    dfs (i, j);
                }
            }
        }

        cout << count << '\n';
    }
    
    return 0;
}