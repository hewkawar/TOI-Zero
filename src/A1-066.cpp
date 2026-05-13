#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x, y;
    if (!(cin >> x >> y)) return 0;

    int total = 0;
    int jumps = 0;
    int currentJump = x;

    while (total < y && currentJump > 0) {
        total += currentJump;
        jumps++;
        currentJump -= 2;
    }

    if (total >= y) {
        cout << jumps << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}
