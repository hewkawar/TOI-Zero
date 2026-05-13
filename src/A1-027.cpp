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

    reverse(s.begin(), s.end());
    for (char &c : s) {
        c = tolower(c);
    }

    cout << s << endl;
    
    return 0;
}
