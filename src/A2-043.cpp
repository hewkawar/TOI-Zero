#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> cave(n);
    int player_pos = -1;

    for (int i = 0; i < n; ++i) {
        cin >> cave[i];
        if (cave[i] == 1) {
            player_pos = i;
        }
    }

    string s;
    cin >> s;

    for (char cmd : s) {
        int next_pos = player_pos;
        if (cmd == 'L') {
            next_pos--;
        } else if (cmd == 'R') {
            next_pos++;
        }

        if (next_pos >= 0 && next_pos < n) {
            cave[player_pos] = 0;
            if (cave[next_pos] == 2) {
                cave[next_pos] = 1;
                break;
            }
            cave[next_pos] = 1;
            player_pos = next_pos;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << cave[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}