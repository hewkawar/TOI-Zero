#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_pairs(const vector<int>& U, const vector<int>& V, int T) {
    int pairs = 0;
    int l = 0;
    int r = V.size() - 1;
    while (l < U.size() && r >= 0) {
        if (U[l] + V[r] <= T) {
            pairs++;
            l++;
            r--;
        } else {
            r--;
        }
    }
    return pairs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> u1(n), u2(n), v1(n), v2(n);
    
    for (int i = 0; i < n; ++i) cin >> u1[i];
    for (int i = 0; i < n; ++i) cin >> u2[i];
    for (int i = 0; i < n; ++i) cin >> v1[i];
    for (int i = 0; i < n; ++i) cin >> v2[i];

    sort(u1.begin(), u1.end());
    sort(u2.begin(), u2.end());
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int low = 0;
    int high = 2000000;
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int pairs1 = get_pairs(u1, v1, mid);
        int pairs2 = get_pairs(u2, v2, mid);

        if (pairs1 + pairs2 >= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}