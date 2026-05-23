#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    int L = 0, S = 0;
    for (int i = 0; i < n; ++i) {
        int h_val;
        if (!(cin >> h_val)) break;
        if (h_val > 18) L++;
        else S++;
    }
    
    long long total_days = (long long)n + max(0, L - S - 1);
    cout << total_days << "\n";
    
    return 0;
}
