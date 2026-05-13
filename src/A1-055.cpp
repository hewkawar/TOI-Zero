#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    int totalItems = a + b + c;
    int totalPrice = a * 25 + b * 40 + c * 55;
    
    double netPrice = totalPrice;
    if (totalItems >= 3) {
        netPrice = totalPrice * 0.90;
    }

    cout << (int)netPrice << endl;
    
    return 0;
}
