#include <iostream>

using namespace std;

#include <iomanip>
#include <string>
#include <vector>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;

    for (int i = 0; i < n; ++i) {
        double p, c, g;
        cin >> p >> c >> g;
        double total = p + c + g;

        cout << fixed << setprecision(1) << total;
        if (total > 50) cout << ",Overloaded";
        if (p > 20) cout << ",Check Type Plastic";
        if (c > 20) cout << ",Check Type Can";
        if (g > 20) cout << ",Check Type Glass";
        cout << endl;
    }
    
    return 0;
}
