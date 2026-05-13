#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, l;
    if (!(cin >> n >> l)) return 0;
    
    vector<int> h(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    
    vector<int> max_front(n + 1, 0);
    int current_max = 0;
    for (int i = 1; i <= n; ++i) {
        max_front[i] = current_max;
        if (h[i] > current_max) {
            current_max = h[i];
        }
    }
    
    for (int i = 0; i < l; ++i) {
        int a;
        cin >> a;
        if (max_front[a] <= h[a]) {
            cout << 0 << "\n";
        } else {
            cout << max_front[a] - h[a] + 1 << "\n";
        }
    }
    
    return 0;
}
