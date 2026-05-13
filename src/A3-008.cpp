#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    if (!(cin >> n >> k)) return 0;
    
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    
    map<int, int> counts;
    int distinct = 0;
    long long total_segments = 0;
    int left = 0;
    
    for (int right = 0; right < n; ++right) {
        if (counts[c[right]] == 0) {
            distinct++;
        }
        counts[c[right]]++;
        
        while (distinct >= k) {
            total_segments += (n - right);
            counts[c[left]]--;
            if (counts[c[left]] == 0) {
                distinct--;
            }
            left++;
        }
    }
    
    cout << total_segments << "\n";
    
    return 0;
}
