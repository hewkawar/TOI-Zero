#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;

    for (int i = 1; i <= n; ++i) {
        if (i % 5 == 0) cout << "X";
        else cout << "*";
    }
    cout << endl;
    
    return 0;
}
