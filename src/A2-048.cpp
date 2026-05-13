#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    if (n == 0) {
        cout << "0" << endl;
        cout << "0" << endl;
        cout << "0" << endl;
        return 0;
    }

    // Binary
    long long temp = n;
    string bin = "";
    while (temp > 0) {
        bin += (temp % 2 == 0 ? "0" : "1");
        temp /= 2;
    }
    reverse(bin.begin(), bin.end());
    cout << bin << endl;

    // Octal
    temp = n;
    string oct = "";
    while (temp > 0) {
        oct += to_string(temp % 8);
        temp /= 8;
    }
    reverse(oct.begin(), oct.end());
    cout << oct << endl;

    // Hexadecimal
    temp = n;
    string hex = "";
    while (temp > 0) {
        int rem = temp % 16;
        if (rem < 10) {
            hex += to_string(rem);
        } else {
            hex += (char)('A' + rem - 10);
        }
        temp /= 16;
    }
    reverse(hex.begin(), hex.end());
    cout << hex << endl;

    return 0;
}
