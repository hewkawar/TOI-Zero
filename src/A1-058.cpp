#include <iostream>

using namespace std;

#include <iomanip>
#include <algorithm>
#include <vector>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;

    long long sum = 0;
    int maxVal = -1, minVal = 1001;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sum += x;
        if (x > maxVal) maxVal = x;
        if (x < minVal) minVal = x;
    }

    double avg = (double)sum / n;

    cout << sum << endl;
    cout << maxVal << endl;
    cout << minVal << endl;
    cout << fixed << setprecision(1) << avg << endl;
    
    return 0;
}
