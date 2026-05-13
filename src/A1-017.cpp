#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int y1, m1, d1, y2, m2, d2;
    if (!(cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2)) return 0;

    if (y1 < y2) {
        cout << 1 << endl;
    } else if (y1 > y2) {
        cout << 2 << endl;
    } else {
        // years are equal
        if (m1 < m2) {
            cout << 1 << endl;
        } else if (m1 > m2) {
            cout << 2 << endl;
        } else {
            // months are equal
            if (d1 < d2) {
                cout << 1 << endl;
            } else if (d1 > d2) {
                cout << 2 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
    
    return 0;
}
