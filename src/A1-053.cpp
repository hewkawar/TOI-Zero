#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int r1, g1, b1, r2, g2, b2;
    if (!(cin >> r1 >> g1 >> b1 >> r2 >> g2 >> b2)) return 0;

    cout << (r1 + r2) / 2 << " " << (g1 + g2) / 2 << " " << (b1 + b2) / 2 << endl;
    
    return 0;
}
