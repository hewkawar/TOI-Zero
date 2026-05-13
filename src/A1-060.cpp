#include <iostream>

using namespace std;

#include <iomanip>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    double r, h, g;
    if (!(cin >> r >> h >> g)) return 0;

    double pi = 3.14;
    double width = h + 2 * r;
    double length = 2 * pi * r + g;

    cout << fixed << setprecision(2) << width << " " << length << endl;
    
    return 0;
}
