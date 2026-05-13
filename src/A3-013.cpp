#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    long long s;
    if (!(cin >> n >> s)) return 0;
    
    long long sum1 = 0; // min distance
    long long sum2 = 0; // max distance
    
    for (int i = 0; i < n; ++i) {
        long long h;
        cin >> h;
        
        bool t1 = false, t2 = false;
        if (h % 3 == 0) t1 = true;
        if (h % 4 == 0) t2 = true;
        
        long long d1 = 0, d2 = 0;
        if (t1) {
            long long k = h / 3;
            d1 = 2 * 5 * k;
        }
        if (t2) {
            long long k = h / 4;
            d2 = 2 * 5 * k;
        }
        
        if (t1 && !t2) {
            sum1 += d1;
            sum2 += d1;
        } else if (!t1 && t2) {
            sum1 += d2;
            sum2 += d2;
        } else if (t1 && t2) {
            sum1 += min(d1, d2);
            sum2 += max(d1, d2);
        }
    }
    
    cout << s - sum2 << " " << s - sum1 << "\n";
    return 0;
}
