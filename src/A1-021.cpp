#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int year;
    if (!(cin >> year)) return 0;

    bool isLeap = false;
    if (year <= 1582) {
        if (year % 4 == 0) isLeap = true;
    } else {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            isLeap = true;
        }
    }

    if (isLeap) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    
    return 0;
}
