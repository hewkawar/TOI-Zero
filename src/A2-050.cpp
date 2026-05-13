#include <iostream>
#include <string>
#include <cmath>

using namespace std;

char get_char(char k, int d) {
    if (k == '#') return '#';
    if (k >= 'a' && k <= 'z') k = k - 'a' + 'A';
    int v = (k - 'A') + d;
    v = v % 50;
    if (v <= 25) return 'A' + v;
    else return 'A' + (50 - v);
}

int main() {
    int x;
    char k;
    cin >> x >> k;
    
    for (int r = 0; r < x; ++r) {
        int d = (r < x / 2 + x % 2) ? (x - 1) / 2 - r : r - x / 2;
        int left = d;
        int right = x - 1 - d;
        for (int c = 0; c < x; ++c) {
            if (c == left || c == right) {
                cout << get_char(k, d);
            } else {
                cout << '-';
            }
        }
        cout << "\n";
    }
    
    return 0;
}
