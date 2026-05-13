#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int age;
    char status;
    if (cin >> age >> status) {
        if (age < 18 || status == 's' || status == 'S') {
            cout << 20 << "\n";
        } else {
            cout << 50 << "\n";
        }
    }
    
    return 0;
}
