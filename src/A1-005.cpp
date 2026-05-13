#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int month, day;
    if (cin >> month >> day) {
        string season;
        if (month == 1 || month == 2 || (month == 3 && day < 21) || (month == 12 && day >= 21)) {
            season = "winter";
        } else if (month == 4 || month == 5 || (month == 6 && day < 21) || (month == 3 && day >= 21)) {
            season = "spring";
        } else if (month == 7 || month == 8 || (month == 9 && day < 21) || (month == 6 && day >= 21)) {
            season = "summer";
        } else if (month == 10 || month == 11 || (month == 12 && day < 21) || (month == 9 && day >= 21)) {
            season = "fall";
        }
        cout << season << "\n";
    }
    
    return 0;
}
