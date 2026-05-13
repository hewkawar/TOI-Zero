#include <iostream>

using namespace std;

#include <vector>

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int s, e;
    if (!(cin >> s >> e)) return 0;

    vector<int> primes;
    for (int i = s; i <= e; ++i) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }

    for (int i = 0; i < (int)primes.size(); ++i) {
        cout << primes[i] << (i == (int)primes.size() - 1 ? "" : " ");
    }
    cout << endl;
    cout << "Total primes: " << primes.size() << endl;
    
    return 0;
}
