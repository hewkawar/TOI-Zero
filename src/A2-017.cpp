#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char size, type, topping;
    int topping_amount = 0;
    int price = 0;

    if (!(cin >> size >> type)) return 0;

    if (size == 'S') {
        if (type == 'R') price = 60;
        else if (type == 'T') price = 80;
    } else if (size == 'M') {
        if (type == 'R') price = 80;
        else if (type == 'T') price = 100;
    } else if (size == 'L') {
        if (type == 'R') price = 100;
        else if (type == 'T') price = 120;
    }

    cin >> topping;

    if (topping == 'P') {
        cin >> topping_amount;
        price += topping_amount * 15;
    } else if (topping == 'E') {
        cin >> topping_amount;
        price += topping_amount * 10;
    }

    cout << price << "\n";

    return 0;
}