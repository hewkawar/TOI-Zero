#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L, N;
    if (!(cin >> L >> N)) return 0;

    vector<int> count(L + 1, 0);

    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        for (int j = a; j < b; ++j) {
            count[j]++;
        }
    }

    int max_bridges = 0;
    for (int i = 0; i < L; ++i) {
        max_bridges = max(max_bridges, count[i]);
    }

    cout << max_bridges << "\n";

    return 0;
}