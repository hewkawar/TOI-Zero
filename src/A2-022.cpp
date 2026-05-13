#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n < 0 || n > 32768) {
        return 0; 
    }

    if (isPrime(n)) {
        cout << "Yes" << endl;
        vector<int> primes;
        for (int i = 2; i <= n; i++) {
            if (isPrime(i)) {
                primes.push_back(i);
            }
        }
        for (size_t i = 0; i < primes.size(); i++) {
            cout << primes[i] << (i == primes.size() - 1 ? "" : " ");
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
