#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b, c;
    if (cin >> a >> b >> c) {
        if (a >= 5 && b >= 20 && c >= 25) {
            cout << "pass\n";
        } else {
            cout << "fail\n";
        }
    }
    
    return 0;
}
