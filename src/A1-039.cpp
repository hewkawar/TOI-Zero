#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;

    long long fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }

    cout << fact << endl;
    
    return 0;
}
