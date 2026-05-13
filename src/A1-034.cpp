#include <iostream>

using namespace std;

#include <algorithm>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;

    int minVal;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (i == 0) minVal = x;
        else minVal = min(minVal, x);
    }

    cout << minVal << endl;
    
    return 0;
}
