#include <iostream>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    if (isPrime(n)) {
        cout << "Yes\n";
        bool first = true;
        for (int i = 2; i <= n; ++i) {
            if (isPrime(i)) {
                if (!first) cout << " ";
                cout << i;
                first = false;
            }
        }
        cout << "\n";
    } else {
        cout << "No\n";
    }

    return 0;
}