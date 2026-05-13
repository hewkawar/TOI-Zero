#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int g, r;
    if (!(cin >> g >> r)) return 0;

    if (g < 1 || g > 6 || r < 1 || r > 6) {
        cout << "Invalid" << endl;
    } else if (g == r) {
        cout << "Correct!" << endl;
    } else {
        cout << "Wrong!" << endl;
    }
    
    return 0;
}
