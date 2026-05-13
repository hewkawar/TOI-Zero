#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vector<bool>> dp(n, vector<bool>(n, false));

    if (grid[n - 1][n - 1] == '.') {
        dp[n - 1][n - 1] = true;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (grid[i][j] == 'X') continue;

            if (j + 1 < n && dp[i][j + 1]) {
                dp[i][j] = true;
            }

            if (i + 1 < n && dp[i + 1][j]) {
                dp[i][j] = true;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j]) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
