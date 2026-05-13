#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long L, N;
    if (!(cin >> L >> N)) return 0;
    
    long long left = 1, right = 2000000000LL;
    long long D = -1;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (mid * (mid + 1) / 2 >= N) {
            D = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    long long band = (D + L - 1) / L;
    cout << band << "\n";
    
    return 0;
}
