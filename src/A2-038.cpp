#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int fire_total = 0;
    int water_total = 0;
    int earth_total = 0;

    for (int i = 0; i < n; ++i) {
        int f1, w1, e1, f2, w2, e2;
        cin >> f1 >> w1 >> e1 >> f2 >> w2 >> e2;

        int sum1 = f1 + w1 + e1;
        int sum2 = f2 + w2 + e2;

        if (sum1 >= sum2) {
            fire_total += f1;
            water_total += w1;
            earth_total += e1;
        } else {
            fire_total += f2;
            water_total += w2;
            earth_total += e2;
        }
    }

    int total_score = fire_total + water_total + earth_total;

    cout << total_score << "\n";
    cout << fire_total << " " << water_total << " " << earth_total << "\n";
    
    if (fire_total > water_total + earth_total) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}