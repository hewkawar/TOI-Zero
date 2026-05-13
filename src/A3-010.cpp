#include <iostream>

using namespace std;

int main() {
    int n, k, t;
    if (!(cin >> n >> k >> t)) return 0;
    
    long long count = 0;
    long long curr = 1;
    while (true) {
        count++;
        if (curr == t) {
            break;
        }
        curr = (curr + k - 1) % n + 1;
        if (curr == 1) {
            count++; // Because it returned to 1, we count it, but process stops
            break;
        }
    }
    
    cout << count << "\n";
    
    return 0;
}
