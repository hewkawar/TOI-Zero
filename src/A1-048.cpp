#include <iostream>

using namespace std;

#include <iomanip>
#include <algorithm>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;

    double base = 0;
    int remaining = n;

    // 1 to 10
    int tier1 = min(remaining, 10);
    base += tier1 * 5.0;
    remaining -= tier1;

    // 11 to 50
    int tier2 = min(remaining, 40);
    base += tier2 * 7.0;
    remaining -= tier2;

    // 51 to 100
    int tier3 = min(remaining, 50);
    base += tier3 * 10.0;
    remaining -= tier3;

    // 101 to 200
    int tier4 = min(remaining, 100);
    base += tier4 * 12.0;
    remaining -= tier4;

    // 201+
    if (remaining > 0) {
        base += remaining * 15.0;
    }

    double ft = n * 0.50;
    double vat = base * 0.07;
    double total = base + ft + vat;

    cout << fixed << setprecision(2) << total << endl;
    
    return 0;
}
