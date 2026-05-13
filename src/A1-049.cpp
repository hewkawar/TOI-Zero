#include <iostream>

using namespace std;

#include <string>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    if (!(cin >> s)) return 0;

    int d[6];
    for (int i = 0; i < 5; ++i) {
        d[i+1] = s[i] - '0';
    }

    // Floor
    int floor = 13;
    if (d[1] > 5) floor = 9;
    else if (d[2] > 5) floor = 10;
    else if (d[3] > 5) floor = 11;
    else if (d[4] > 5) floor = 12;
    else if (d[5] > 5) floor = 14;

    // Palindrome check
    bool isPalin = (d[1] == d[5] && d[2] == d[4]);

    // First Digit
    int r1 = 0;
    if (isPalin) {
        if (d[1] + d[5] > 5) r1 = 1;
        else if (d[2] * d[4] > 5) r1 = 2;
    } else {
        if (d[5] != 0 && d[1] / d[5] > 5) r1 = 1;
        else if (d[2] - d[5] > 5) r1 = 2;
    }

    // Second Digit
    int r2 = 0;
    int sum = d[1] + d[2] + d[3] + d[4] + d[5];
    long long prod = (long long)d[1] * d[2] * d[3] * d[4] * d[5];
    if (sum > 25) r2 = 1;
    else if (prod > 55) r2 = 2;

    cout << floor << r1 << r2 << endl;
    
    return 0;
}
