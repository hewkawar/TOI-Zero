#include <iostream>

using namespace std;

#include <cmath>
#include <iomanip>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    double x1, y1, z1, x2, y2, z2;
    if (!(cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2)) return 0;

    double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));

    cout << fixed << setprecision(2) << d << endl;
    
    return 0;
}
