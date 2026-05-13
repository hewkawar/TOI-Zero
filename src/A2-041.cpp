#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    int L;
    cin >> L;

    vector<int> cave(n);
    int pos = -1;
    for (int i = 0; i < n; i++) {
        cin >> cave[i];
        if (cave[i] == 1) {
            pos = i;
        }
    }

    string s;
    cin >> s;

    for (char c : s) {
        int next_pos = pos;
        if (c == 'L') next_pos--;
        else if (c == 'R') next_pos++;

        if (next_pos < 0 || next_pos >= n) {
            continue;
        }

        pos = next_pos;

        if (cave[pos] == 2) {
            // Found treasure, stop!
            break;
        }
    }

    // Now construct the final state
    // "1 แทนตำแหน่งน้องโค้ด" -> Update the cave
    for (int i = 0; i < n; i++) {
        if (cave[i] == 1) cave[i] = 0; // clear old position
    }
    cave[pos] = 1;

    for (int i = 0; i < n; i++) {
        cout << cave[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
