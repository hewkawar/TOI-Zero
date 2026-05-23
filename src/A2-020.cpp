#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<bool> visited(n + 1, false);
    int max_cycle = 0;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            int length = 0;
            int curr = i;

            while (!visited[curr]) {
                visited[curr] = true;
                curr = a[curr];
                length++;
            }

            max_cycle = max(max_cycle, length);
        }
    }

    cout << max_cycle << "\n";

    return 0;
}