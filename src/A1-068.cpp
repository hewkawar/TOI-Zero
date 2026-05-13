#include <iostream>

using namespace std;

#include <iomanip>
#include <vector>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;

    int total = 0;
    bool allAbove50 = true;
    for (int i = 0; i < n; ++i) {
        int s;
        cin >> s;
        total += s;
        if (s < 50) allAbove50 = false;
    }

    double avg = (double)total / n;
    cout << fixed << setprecision(1) << avg << endl;

    if (allAbove50 && avg >= 60.0) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL" << endl;
    }
    
    return 0;
}
