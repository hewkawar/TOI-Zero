#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    int k;
    cin >> k;

    vector<vector<int>> grid(n, vector<int>(m, 0));

    for (int i = 0; i < k; ++i) {
        int r, c;
        cin >> r >> c;
        grid[r][c]++;
    }

    int max_caught = 0;
    
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 0) {
                int current_caught = 0;
                for (int d = 0; d < 8; ++d) {
                    int ni = i + dr[d];
                    int nj = j + dc[d];
                    
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        current_caught += grid[ni][nj];
                    }
                }
                max_caught = max(max_caught, current_caught);
            }
        }
    }

    cout << max_caught << "\n";

    return 0;
}