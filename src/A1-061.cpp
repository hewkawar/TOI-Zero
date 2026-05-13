#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long r, x, y;
    if (!(cin >> r >> x >> y)) return 0;

    long long distSq = x * x + y * y;
    long long rSq = r * r;

    if (distSq < rSq) {
        cout << "IN" << endl;
    } else if (distSq == rSq) {
        cout << "ON" << endl;
    } else {
        cout << "OUT" << endl;
    }
    
    return 0;
}
