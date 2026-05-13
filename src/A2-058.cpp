#include <iostream>

using namespace std;

int main() {
    int a, b, d, r;
    cin >> a >> b >> d >> r;
    
    int count = 0;
    for (int x = a; x <= b; ++x) {
        if (x % d == r) {
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}
