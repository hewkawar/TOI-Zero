#include <iostream>

using namespace std;

#include <iomanip>
#include <cmath>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    char member;
    int n;
    if (!(cin >> member >> n)) return 0;

    double total = 0;
    for (int i = 0; i < n; ++i) {
        double price;
        cin >> price;
        total += price;
    }

    double discount = 0;
    if (member == 'Y') {
        discount = total * 0.05;
    } else if (member == 'N' && total >= 500) {
        discount = total * 0.03;
    }

    double net = total - discount;
    cout << fixed << setprecision(2) << net << endl;
    
    return 0;
}
