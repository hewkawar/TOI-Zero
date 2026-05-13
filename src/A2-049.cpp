#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a[3][3];
    int b[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> b[i][j];
        }
    }

    int mod_val = (1 << 15) + 9; // 2^15 + 9

    long long c[3][3] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                long long term = ((long long)a[i][k] * b[k][j]) % mod_val;
                if (term < 0) term += mod_val;
                c[i][j] = (c[i][j] + term) % mod_val;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << c[i][j] << (j == 2 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}
