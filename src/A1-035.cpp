#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    if (!(cin >> n)) return 0;

    long long sum = 0;
    for (long long i = 1; i <= n; ++i) {
        sum += i * i;
    }

    cout << sum << endl;
    
    return 0;
}
