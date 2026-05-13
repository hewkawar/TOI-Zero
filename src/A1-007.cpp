#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    char c;
    if (cin >> c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    
    return 0;
}
