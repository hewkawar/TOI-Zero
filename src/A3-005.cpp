#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;
    
    vector<int> diff(n + 2, 0);
    for (int i = 0; i < m; ++i) {
        int s, t;
        cin >> s >> t;
        diff[s]++;
        if (t + 1 <= n + 1) {
            diff[t + 1]--;
        }
    }
    
    int current = 0;
    int max_overlap = 0;
    for (int i = 1; i <= n; ++i) {
        current += diff[i];
        if (current > max_overlap) {
            max_overlap = current;
        }
    }
    
    cout << max_overlap << "\n";
    return 0;
}
