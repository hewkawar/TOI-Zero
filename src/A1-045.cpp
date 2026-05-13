#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;

    int fare = 0;
    if (n <= 1) {
        fare = 35;
    } else if (n <= 10) {
        fare = 35 + (n - 1) * 5;
    } else {
        fare = 35 + (9 * 5) + (n - 10) * 8;
    }

    cout << fare << endl;
    
    return 0;
}
