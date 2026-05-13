#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    int current = 1;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = current++;
            }
        } else {
            for (int j = n - 1; j >= 0; j--) {
                grid[i][j] = current++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[j][i];
            if (j < n - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
