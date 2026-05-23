#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int grid[5][5];
    int row_sum[5] = {0};
    int col_sum[5] = {0};

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> grid[i][j];
            row_sum[i] += grid[i][j];
            col_sum[j] += grid[i][j];
        }
    }

    int anomaly_row = -1;
    int anomaly_col = -1;

    for (int i = 0; i < 5; ++i) {
        if (row_sum[i] % 2 != 0) {
            anomaly_row = i;
        }
        if (col_sum[i] % 2 != 0) {
            anomaly_col = i;
        }
    }

    cout << anomaly_row << " " << anomaly_col << "\n";

    return 0;
}