#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    map<int, int> counts;
    int max_count = 0;
    for (int i = 0; i < n; i++) {
        int x;
        if (!(cin >> x)) break;
        counts[x]++;
        if (counts[x] > max_count) {
            max_count = counts[x];
        }
    }

    cout << max_count << endl;

    return 0;
}
