#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    double p;
    cin >> n >> p;
    
    vector<vector<int>> grid(n, vector<int>(n));
    vector<int> badTilesCol(n, 0);
    vector<int> badPointsCol(n, 0);
    
    int totalBadTiles = 0;
    int totalBadPoints = 0;
    
    for (int i = 0; i < n; ++i) {
        int badTilesRow = 0;
        int badPointsRow = 0;
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            cout << grid[i][j] << " ";
            if (grid[i][j] > 0) {
                badTilesRow++;
                badPointsRow += grid[i][j];
                badTilesCol[j]++;
                badPointsCol[j] += grid[i][j];
                totalBadTiles++;
                totalBadPoints += grid[i][j];
            }
        }
        cout << badTilesRow << " " << badPointsRow << "\n";
    }
    
    for (int j = 0; j < n; ++j) {
        cout << badTilesCol[j] << (j == n - 1 ? "" : " ");
    }
    cout << "\n";
    
    for (int j = 0; j < n; ++j) {
        cout << badPointsCol[j] << (j == n - 1 ? "" : " ");
    }
    cout << "\n";
    
    double totalFine = totalBadPoints * p;
    cout << totalBadTiles << " " << totalBadPoints << " " << fixed << setprecision(2) << totalFine << "\n";
    
    return 0;
}
