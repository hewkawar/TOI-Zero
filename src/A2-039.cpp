#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long fire_total = 0;
    long long water_total = 0;
    long long earth_total = 0;

    for (int i = 0; i < n; i++) {
        long long f1, w1, e1, f2, w2, e2;
        cin >> f1 >> w1 >> e1 >> f2 >> w2 >> e2;

        long long sum1 = f1 + w1 + e1;
        long long sum2 = f2 + w2 + e2;

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

    long long total_score = fire_total + water_total + earth_total;

    cout << total_score << endl;
    cout << fire_total << " " << water_total << " " << earth_total << endl;
    
    if (fire_total > water_total + earth_total) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
