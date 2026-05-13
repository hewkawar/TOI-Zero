#include <iostream>

using namespace std;

#include <string>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string result = "";
    for (int i = 0; i < 5; ++i) {
        int n;
        if (!(cin >> n)) break;

        if (n == 0) {
            result += "-";
        } else {
            int th = (n / 1000) % 10;
            int hu = (n / 100) % 10;
            int te = (n / 10) % 10;
            int un = n % 10;

            if (th > 0) result += "#";
            if (hu > 0) result += "/";
            if (te > 0) result += "+";
            if (un > 0) result += "*";
        }
    }

    cout << result << endl;
    
    return 0;
}
