#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    int n = s.length();
    bool only_t_i = true;
    
    for (int i = 0; i < n; i++) {
        char c = toupper(s[i]);
        if (c != 'T' && c != 'I') {
            only_t_i = false;
            break;
        }
    }

    if (only_t_i) {
        cout << "unknown " << n << "\n";
        return 0;
    }

    int max_a = 0;
    int curr_a = 0;

    for (int i = 0; i < n; i++) {
        char c = toupper(s[i]);

        if (c != 'R' && c != 'A' && c != 'B' && c != 'I' && c != 'T') {
            cout << "no " << i << "\n";
            return 0;
        }

        if (i > 0) {
            char prev = toupper(s[i - 1]);
            if (prev == 'R' && c != 'A') {
                cout << "no " << i << "\n";
                return 0;
            }
            if (prev == 'B' && c != 'I' && c != 'T') {
                cout << "no " << i << "\n";
                return 0;
            }
        }

        if (c == 'A') {
            if (i == 0) {
                cout << "no " << i << "\n";
                return 0;
            }
            char prev = toupper(s[i - 1]);
            if (prev != 'R' && prev != 'A') {
                cout << "no " << i << "\n";
                return 0;
            }
            curr_a++;
            max_a = max(max_a, curr_a);
        } else {
            curr_a = 0;
        }
    }

    char last_c = toupper(s[n - 1]);
    if (last_c == 'R' || last_c == 'B') {
        cout << "no " << n - 1 << "\n";
        return 0;
    }

    cout << "yes " << max_a << "\n";
    return 0;
}