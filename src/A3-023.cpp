#include <iostream>
#include <vector>

using namespace std;

const int MAX_VAL = 15000;
bool is_prime[MAX_VAL + 1];

void sieve() {
    for (int i = 0; i <= MAX_VAL; ++i) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= MAX_VAL; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= MAX_VAL; i += p)
                is_prime[i] = false;
        }
    }
}

int main() {
    sieve();
    int a, b;
    if (!(cin >> a >> b)) return 0;
    
    long long count = 0;
    for (int x = a; x <= b; ++x) {
        for (int y = x; y <= b; ++y) {
            for (int z = y; z <= b; ++z) {
                int sum = x + y + z;
                if (sum <= MAX_VAL && is_prime[sum]) {
                    count++;
                }
            }
        }
    }
    
    cout << count << "\n";
    return 0;
}
