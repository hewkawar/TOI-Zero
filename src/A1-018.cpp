#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;

    if (n < 0) {
        cout << "Error : Please input positive number" << endl;
    } else if (n == 0 || n > 9) {
        cout << "Error : Out of range" << endl;
    } else {
        string roman[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        cout << roman[n] << endl;
    }
    
    return 0;
}
