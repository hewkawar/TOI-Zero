#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int even = 0, odd = 0;
    for (int i = 0; i < 3; ++i) {
        int n;
        if (!(cin >> n)) break;
        if (n % 2 == 0) even++;
        else odd++;
    }

    cout << "even " << even << endl;
    cout << "odd " << odd << endl;
    
    return 0;
}
