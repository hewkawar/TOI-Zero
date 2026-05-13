#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort descending
    sort(a.rbegin(), a.rend());
    
    long long total_dist = 0;
    long long current_len = 0;
    for (int i = 0; i < n; ++i) {
        current_len += a[i];
        total_dist += 2 * current_len;
    }
    
    cout << total_dist << "\n";
    return 0;
}
