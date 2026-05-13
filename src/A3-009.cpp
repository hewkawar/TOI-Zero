#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, k;
    if (!(cin >> n >> k)) return 0;
    
    vector<int> counts(k + 1, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        counts[x]++;
    }
    
    long long remaining = 0;
    for (int i = 1; i <= k; ++i) {
        if (counts[i] == 0) {
            remaining++;
        } else {
            remaining += counts[i] - 1;
        }
    }
    
    cout << remaining << "\n";
    
    return 0;
}
