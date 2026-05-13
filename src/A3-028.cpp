#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;
    
    int b;
    cin >> b;
    
    vector<vector<char>> grid(n, vector<char>(m, '0'));
    for (int i = 0; i < b; ++i) {
        int r, c;
        cin >> r >> c;
        if (r >= 0 && r < n && c >= 0 && c < m) {
            grid[r][c] = 'x';
        }
    }
    
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'x') {
                cout << 'x';
            } else {
                int count = 0;
                for (int k = 0; k < 8; ++k) {
                    int ni = i + dr[k];
                    int nj = j + dc[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        if (grid[ni][nj] == 'x') {
                            count++;
                        }
                    }
                }
                cout << count;
            }
            if (j < m - 1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
