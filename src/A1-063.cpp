#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;

    int a, n;
    while (cin >> a >> n) {
        if (a < 15) {
            cout << -1 << endl;
        } else if (n > t) {
            cout << -2 << endl;
        } else {
            int pricePerTicket = 150;
            if (a >= 15 && a <= 22) {
                pricePerTicket = 120; // 150 * 0.8
            } else if (a >= 60) {
                pricePerTicket = 75; // 150 * 0.5
            }
            
            int total = pricePerTicket * n;
            t -= n;
            cout << total << " " << t << endl;
        }
    }
    
    return 0;
}
