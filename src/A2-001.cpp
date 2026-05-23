#include <iostream>
#include <vector>
#include <numeric>
#include <set>
#include <cmath>

using namespace std;

long long get_gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<long long> r(n + 1, 0), b(m + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> r[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];

    set<pair<long long, long long>> intersections;
    
    intersections.insert({0, 1}); 

    for (int i = 1; i <= n; ++i) {
        long long R_start = r[i - 1];
        long long R_end = r[i];
        long long y_R_start = (i - 1) % 2;
        long long dy_R = (i % 2) - ((i - 1) % 2);
        long long dx_R = R_end - R_start;

        for (int j = 1; j <= m; ++j) {
            long long B_start = b[j - 1];
            long long B_end = b[j];
            long long y_B_start = (j - 1) % 2;
            long long dy_B = (j % 2) - ((j - 1) % 2);
            long long dx_B = B_end - B_start;

            long long x_min = max(R_start, B_start);
            long long x_max = min(R_end, B_end);

            if (x_min > x_max) continue; 

            long long num = dx_R * dx_B * (y_B_start - y_R_start) + dy_R * dx_B * R_start - dy_B * dx_R * B_start;
            long long den = dy_R * dx_B - dy_B * dx_R;

            if (den == 0) continue; 

            if (den < 0) {
                num = -num;
                den = -den;
            }

            if (num >= x_min * den && num <= x_max * den) {
                long long g = get_gcd(abs(num), abs(den));
                intersections.insert({num / g, den / g});
            }
        }
    }
    
    cout << intersections.size() << "\n";

    return 0;
}