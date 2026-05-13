#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);

    char type = line1[0];
    char size = line1[2];
    
    char topping = line2[0];
    int topping_amount = 0;
    
    if (topping != 'N') {
        stringstream ss(line2.substr(2));
        ss >> topping_amount;
    }

    int price = 0;
    
    if (type == 'S') {
        if (size == 'R') price = 60;
        else if (size == 'T') price = 80;
    } else if (type == 'M') {
        if (size == 'R') price = 80;
        else if (size == 'T') price = 100;
    } else if (type == 'L') {
        if (size == 'R') price = 100;
        else if (size == 'T') price = 120;
    }

    if (topping == 'P') {
        price += topping_amount * 15;
    } else if (topping == 'E') {
        price += topping_amount * 10;
    }

    cout << price << endl;

    return 0;
}
