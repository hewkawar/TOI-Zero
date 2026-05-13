#include <iostream>

using namespace std;

#include <string>
#include <cmath>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    if (!(cin >> s)) return 0;

    int x = 0, y = 0;
    for (char c : s) {
        if (c == 'N') y++;
        else if (c == 'S') y--;
        else if (c == 'E') x++;
        else if (c == 'W') x--;
    }

    int d = abs(x) + abs(y);
    cout << x << " " << y << " " << d << endl;
    
    return 0;
}
