#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, w, l;
    if (!(cin >> n >> w >> l)) return 0;
    
    vector<vector<int>> holes(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        holes[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> holes[i][j];
        }
    }
    
    vector<int> valid_count(w + 1, 0);
    
    for (int i = 0; i < n; ++i) {
        vector<bool> piece_valid(w + 1, false);
        for (int h : holes[i]) {
            int start = max(1, h - l);
            int end = min(w, h + l);
            for (int p = start; p <= end; ++p) {
                piece_valid[p] = true;
            }
        }
        for (int p = 1; p <= w; ++p) {
            if (piece_valid[p]) {
                valid_count[p]++;
            }
        }
    }
    
    bool possible = false;
    for (int p = 1; p <= w; ++p) {
        if (valid_count[p] == n) {
            possible = true;
            break;
        }
    }
    
    if (possible) cout << 1 << "\n";
    else cout << 0 << "\n";
    
    return 0;
}
