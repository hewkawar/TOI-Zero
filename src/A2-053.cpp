#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    while (!s.empty() && s.back() == '\r') s.pop_back();
    
    int len = s.length();
    char first = toupper(s[0]);
    char last = toupper(s[len - 1]);
    
    int results[10];
    for (int i = 1; i <= 10; ++i) {
        int vi = i - 1;
        int val;
        if (i % 2 != 0) {
            val = (int)first + vi;
        } else {
            val = (int)last - vi;
        }
        val = val % len;
        if (val > 9) val %= 10;
        results[i - 1] = val;
    }
    
    for (int i = 3; i <= 8; ++i) {
        cout << results[i - 1] << (i == 8 ? "" : " ");
    }
    cout << "\n";
    
    return 0;
}
