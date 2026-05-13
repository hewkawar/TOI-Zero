#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> pass_to(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> pass_to[i];
    }

    vector<int> held(n + 1);
    for (int i = 1; i <= n; i++) {
        held[i] = i;
    }

    vector<bool> received_original(n + 1, false);
    int received_count = 0;
    int rounds = 0;

    while (received_count < n) {
        rounds++;
        vector<int> next_held(n + 1);
        
        for (int i = 1; i <= n; i++) {
            next_held[pass_to[i]] = held[i];
        }
        
        for (int i = 1; i <= n; i++) {
            held[i] = next_held[i];
            if (held[i] == i && !received_original[i]) {
                received_original[i] = true;
                received_count++;
            }
        }
    }

    cout << rounds << endl;

    return 0;
}
