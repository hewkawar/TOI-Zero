#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (!(cin >> n)) return 0;
    
    vector<long long> u(n), v(n);
    for (int i = 0; i < n; ++i) {
        long long x, y;
        cin >> x >> y;
        u[i] = x + y;
        v[i] = x - y;
    }
    
    sort(u.begin(), u.end());
    sort(v.begin(), v.end());
    
    long long u_med = u[n / 2];
    long long v_med = v[n / 2];
    
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += abs(u[i] - u_med);
        ans += abs(v[i] - v_med);
    }
    
    cout << ans << "\n";
    return 0;
}
