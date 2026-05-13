#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int total = 0;
    int choice;
    while (cin >> choice && choice != 5) {
        if (choice == 1) total += 100;
        else if (choice == 2) total += 120;
        else if (choice == 3) total += 200;
        else if (choice == 4) total += 60;
    }

    cout << "Bye Bye" << endl;
    cout << "Total Calories: " << total << endl;
    
    return 0;
}
