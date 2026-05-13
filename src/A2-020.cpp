#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int r, c;
    cin >> r >> c;

    int k;
    cin >> k;

    vector<vector<int>> grid(n, vector<int>(c, 0));
    for (int i = 0; i < k; i++) {
        int pr, pc;
        cin >> pr >> pc;
        grid[pr][pc]++;
    }

    int max_catch = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 0) {
                int current_catch = 0;
                for (int dr = -1; dr <= 1; dr++) {
                    for (int dc = -1; dc <= 1; dc++) {
                        if (dr == 0 && dc == 0) continue;
                        int nr = i + dr;
                        int nc = j + dc;
                        if (nr >= 0 && nr < n && nc >= 0 && nc < c) {
                            current_catch += grid[nr][nc];
                        }
                    }
                }
                max_catch = max(max_catch, current_catch);
            }
        }
    }

    cout << max_catch << endl;

    return 0;
}
