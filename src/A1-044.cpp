#include <iostream>

using namespace std;

#include <string>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int age;
    string day;
    if (!(cin >> age >> day)) return 0;

    int price = 0;
    if (age < 5) {
        price = 0;
    } else if (age <= 18) {
        price = 100;
    } else {
        price = 150;
    }

    if (day == "Wed") {
        price /= 2;
    }

    cout << price << endl;
    
    return 0;
}
