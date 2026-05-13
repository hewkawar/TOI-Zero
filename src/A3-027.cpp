#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;
    
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        grid[i] = "";
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            grid[i] += c;
        }
    }
    
    vector<string> new_grid = grid;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i-1][j] == '*') {
                new_grid[i][j] = '*';
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << new_grid[i][j] << (j == m - 1 ? "" : " ");
        }
        cout << "\n";
    }
    
    return 0;
}
