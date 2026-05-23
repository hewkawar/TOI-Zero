#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string to_base(int n, int base) {
    if (n == 0) return "0";
    string res = "";
    string chars = "0123456789ABCDEF";
    while (n > 0) {
        res += chars[n % base];
        n /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    cout << to_base(n, 2) << "\n";
    cout << to_base(n, 8) << "\n";
    cout << to_base(n, 16) << "\n";

    return 0;
}