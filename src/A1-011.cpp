#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    if (cin >> s) {
        int count = 1;
        for (size_t i = 1; i <= s.length(); ++i) {
            if (i < s.length() && s[i] == s[i - 1]) {
                count++;
            } else {
                cout << count << s[i - 1];
                count = 1;
            }
        }
        cout << "\n";
    }
    
    return 0;
}
