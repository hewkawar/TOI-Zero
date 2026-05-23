#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num, query;
    if (!(cin >> num >> query)) return 0;

    vector<int> diff(1500, 0);

    for (int i = 0; i < num; ++i) {
        int start, stop;
        cin >> start >> stop;
        diff[start]++;
        diff[stop + 1]--;
    }

    vector<int> open_stores(1500, 0);
    int current = 0;
    for (int i = 0; i <= 1440; ++i) {
        current += diff[i];
        open_stores[i] = current;
    }

    for (int i = 0; i < query; ++i) {
        int q;
        cin >> q;
        if (i > 0) cout << " ";
        if (q >= 0 && q <= 1440) {
            cout << open_stores[q];
        } else {
            cout << 0;
        }
    }
    cout << "\n";

    return 0;
}