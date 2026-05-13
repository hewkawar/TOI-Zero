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

    for (int j = 0; j < n; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < n; i++) {
                grid[i][j] = current++;
            }
        } else {
            for (int i = n - 1; i >= 0; i--) {
                grid[i][j] = current++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j];
            if (j < n - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
