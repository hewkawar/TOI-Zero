#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    
    int meet_count = 0;
    int prev_a = 1, prev_b = 1;
    for (int i = 0; i < n; ++i) {
        int curr_a = a[i];
        int curr_b = b[i];
        
        int u1 = prev_a, v1 = curr_a;
        int u2 = prev_b, v2 = curr_b;
        
        if ((u1 == u2 && v1 == v2) || (u1 == v2 && v1 == u2)) {
            meet_count++;
        } else if (u1 != u2 && u1 != v2 && v1 != u2 && v1 != v2) {
            int x = u1, y = v1;
            if (x > y) swap(x, y);
            bool u2_in = (x < u2 && u2 < y);
            bool v2_in = (x < v2 && v2 < y);
            if (u2_in != v2_in) {
                meet_count++;
            }
        }
        
        prev_a = curr_a;
        prev_b = curr_b;
    }
    
    cout << meet_count << "\n";
    return 0;
}
