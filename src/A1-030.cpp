#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;

    vector<int> maxes;
    int total = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        int m = max(a, b);
        maxes.push_back(m);
        total += m;
    }

    if (n == 1) {
        cout << maxes[0] << endl;
    } else {
        for (int i = 0; i < n; ++i) {
            cout << maxes[i] << (i == n - 1 ? " = " : " + ");
        }
        cout << total << endl;
    }
    
    return 0;
}
