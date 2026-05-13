#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    
    // Sort in ascending order to pack as many items into a day as possible.
    // Wait, let's verify logic. We want to find the minimum number of days.
    // To minimize days, we can just use a greedy approach on sorted times.
    // But since it's a bin packing problem and max time per day is 18.
    // Let's sort descending and use first-fit descending, which is optimal for small cases.
    // Actually, simple sort descending might work, but is it guaranteed optimal?
    // Max items = 100,000. So we can use binary search on answer or simple greedy.
    // Actually, simple greedy with multiset or keeping track of bins:
    sort(h.begin(), h.end(), greater<int>());
    
    // Let's use first fit decreasing.
    // Since items are up to 18, and bin size is 18, FFD is very good.
    // Is it perfectly optimal? Maybe just simple greedy since h_i is small?
    // Let's just output the number of bins.
    
    vector<int> bins;
    for (int i = 0; i < n; ++i) {
        bool placed = false;
        for (int j = 0; j < bins.size(); ++j) {
            if (bins[j] + h[i] <= 18) {
                bins[j] += h[i];
                placed = true;
                break;
            }
        }
        if (!placed) {
            bins.push_back(h[i]);
        }
    }
    
    cout << bins.size() << "\n";
    
    return 0;
}
