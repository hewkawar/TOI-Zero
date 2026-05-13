#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int temp;
    char unit;
    if (!(cin >> temp >> unit)) return 0;

    if (unit == 'C' || unit == 'c') {
        if (temp <= 0) cout << "solid" << endl;
        else if (temp < 100) cout << "liquid" << endl;
        else cout << "gas" << endl;
    } else if (unit == 'F' || unit == 'f') {
        if (temp <= 32) cout << "solid" << endl;
        else if (temp < 212) cout << "liquid" << endl;
        else cout << "gas" << endl;
    }
    
    return 0;
}
