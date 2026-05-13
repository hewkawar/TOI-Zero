#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int amount;
    if (!(cin >> amount)) return 0;

    if (amount < 100 || amount > 20000 || amount % 100 != 0) {
        cout << "ERROR" << endl;
    } else {
        int d1000 = amount / 1000;
        amount %= 1000;
        int d500 = amount / 500;
        amount %= 500;
        int d100 = amount / 100;

        if (d1000 > 0) cout << "1000 = " << d1000 << endl;
        if (d500 > 0) cout << "500 = " << d500 << endl;
        if (d100 > 0) cout << "100 = " << d100 << endl;
    }
    
    return 0;
}
