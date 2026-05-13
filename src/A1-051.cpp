#include <iostream>

using namespace std;

#include <string>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    int k;
    if (!(cin >> s >> k)) return 0;

    for (char &c : s) {
        if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + k) % 26 + 'a';
        }
    }

    cout << s << endl;
    
    return 0;
}
