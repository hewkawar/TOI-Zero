#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    if (a == b && b == c) {
        cout << "all the same" << endl;
    } else if (a != b && b != c && a != c) {
        cout << "all different" << endl;
    } else {
        cout << "neither" << endl;
    }
    
    return 0;
}
