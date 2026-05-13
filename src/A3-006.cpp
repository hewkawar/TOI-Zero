#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (!(cin >> n)) return 0;
    
    vector<long long> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    
    vector<long long> slots;
    for (int i = 1; i <= 200; ++i) {
        slots.push_back(i);
        for (int j = 0; j < 9; ++j) {
            slots.push_back(2 * i);
        }
    }
    
    sort(x.rbegin(), x.rend());
    sort(slots.begin(), slots.end());
    
    long long total_energy = 0;
    for (int i = 0; i < n; ++i) {
        total_energy += x[i] * slots[i];
    }
    
    cout << total_energy << "\n";
    return 0;
}
