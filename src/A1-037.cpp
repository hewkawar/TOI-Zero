#include <iostream>

using namespace std;

#include <string>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;

    struct Roman {
        int val;
        string sym;
    };

    Roman romans[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
        {1, "I"}
    };

    string result = "";
    for (const auto& r : romans) {
        while (n >= r.val) {
            result += r.sym;
            n -= r.val;
        }
    }

    cout << result << endl;
    
    return 0;
}
