#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;

    int counts[] = {n, n - 2, n - 4};
    for (int i = 0; i < 3; ++i) {
        if (counts[i] >= 1) {
            for (int j = 0; j < counts[i]; ++j) {
                cout << "*";
            }
            cout << endl;
        }
    }
    
    return 0;
}
