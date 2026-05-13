#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m = 0, f = 0;
    int n;
    while (cin >> n && n >= 0) {
        if (n % 2 == 0) f++;
        else m++;
    }

    cout << m << " " << f << " " << m + f << endl;
    
    return 0;
}
