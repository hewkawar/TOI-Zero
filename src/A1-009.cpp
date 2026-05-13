#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b;
    if (cin >> a >> b) {
        int total = a + b;
        cout << total << "\n";
        if (total >= 50) {
            cout << "pass\n";
        } else {
            cout << "fail\n";
        }
    }
    
    return 0;
}
