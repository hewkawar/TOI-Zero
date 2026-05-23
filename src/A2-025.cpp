#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    if (!(cin >> R >> C)) return 0;

    int rr, rc;
    cin >> rr >> rc;

    int N;
    cin >> N;

    vector<vector<int>> grid(R, vector<int>(C, 0));

    for (int k = 0; k < N; ++k) {
        int ir, ic;
        cin >> ir >> ic;

        for (int i = max(0, ir - 2); i <= min(R - 1, ir + 2); ++i) {
            for (int j = max(0, ic - 2); j <= min(C - 1, ic + 2); ++j) {
                int dist = max(abs(i - ir), abs(j - ic));
                int risk = 0;
                
                if (dist == 0) risk = 100;
                else if (dist == 1) risk = 60;
                else if (dist == 2) risk = 20;
                
                grid[i][j] = max(grid[i][j], risk);
            }
        }
    }

    int safe_count = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == 0) {
                safe_count++;
            }
        }
    }

    cout << safe_count << "\n";
    cout << grid[rr][rc] << "%\n";

    return 0;
}