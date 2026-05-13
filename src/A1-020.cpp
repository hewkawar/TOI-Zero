#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    if (a < b && b < c) {
        cout << "increasing" << endl;
    } else if (a > b && b > c) {
        cout << "decreasing" << endl;
    } else {
        cout << "neither" << endl;
    }
    
    return 0;
}
