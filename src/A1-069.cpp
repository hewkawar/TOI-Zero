#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;

    int adultRows;
    if (n % 2 == 0) {
        adultRows = n / 2;
    } else {
        adultRows = (n + 1) / 2;
    }

    for (int i = 1; i <= n; ++i) {
        char seatType = (i <= adultRows ? 'A' : 'K');
        for (int j = 1; j <= m; ++j) {
            cout << seatType << (j == m ? "" : " ");
        }
        cout << endl;
    }
    
    return 0;
}
