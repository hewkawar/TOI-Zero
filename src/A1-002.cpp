#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int amount;
    if (cin >> amount) {
        cout << "10 = " << amount / 10 << "\n";
        amount %= 10;
        cout << "5 = " << amount / 5 << "\n";
        amount %= 5;
        cout << "2 = " << amount / 2 << "\n";
        amount %= 2;
        cout << "1 = " << amount << "\n";
    }
    
    return 0;
}
