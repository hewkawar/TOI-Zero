#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;

    long long sum = 0;
    int even = 0, odd = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sum += x;
        if (x % 2 == 0) even++;
        else odd++;
    }

    cout << "SUM " << sum << endl;
    cout << "EVEN " << even << endl;
    cout << "ODD " << odd << endl;
    
    return 0;
}
