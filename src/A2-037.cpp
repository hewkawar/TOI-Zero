#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num, query;
    cin >> num >> query;

    vector<int> active_stores(1441, 0);

    for (int i = 0; i < num; i++) {
        int start, stop;
        cin >> start >> stop;

        active_stores[start]++;
        if (stop + 1 <= 1440) {
            active_stores[stop + 1]--;
        }
    }

    int current_active = 0;
    vector<int> result(1441);
    for (int i = 0; i <= 1440; i++) {
        current_active += active_stores[i];
        result[i] = current_active;
    }

    for (int i = 0; i < query; i++) {
        int q;
        cin >> q;
        cout << result[q] << (i == query - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
