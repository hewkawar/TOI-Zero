#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    
    unordered_set<long long> possible_sums;
    for (int i = 0; i < n; ++i) {
        long long current_sum = 0;
        for (int j = i; j < n; ++j) {
            current_sum += p[j];
            possible_sums.insert(current_sum);
        }
    }
    
    cout << possible_sums.size() << "\n";
    
    return 0;
}
