#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    char pos;
    int a, s;
    if (!(cin >> pos >> a >> s)) return 0;

    int base = 0;
    double rate = 0;

    if (pos == 'M') {
        base = 1500;
        if (a < 5) rate = 0.06;
        else if (a < 10) rate = 0.08;
        else rate = 0.10;
    } else if (pos == 'B') {
        base = 1000;
        if (a < 5) rate = 0.05;
        else if (a < 10) rate = 0.06;
        else rate = 0.07;
    } else if (pos == 'G') {
        base = 500;
        if (a < 5) rate = 0.04;
        else if (a < 10) rate = 0.05;
        else rate = 0.06;
    } else {
        cout << 0 << endl;
        return 0;
    }

    int total = base + (int)(rate * s);
    cout << total << endl;
    
    return 0;
}
