#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    if (!(cin >> s)) return 0;

    int n = s.length();
    if (n > 3) {
        cout << s.substr(0, n - 3) << "," << s.substr(n - 3) << endl;
    } else {
        cout << s << endl;
    }
    
    return 0;
}
