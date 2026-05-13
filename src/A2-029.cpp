#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i || i == n - 1) {
                cout << 0 << (j == i ? "" : " ");
            } else {
                cout << 1 << (j == i ? "" : " ");
            }
        }
        cout << endl;
    }

    return 0;
}
