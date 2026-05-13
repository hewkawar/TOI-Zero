#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;

    int not_nine = 0;
    for (int i = 0; i < n; i++) {
        int d1 = s1[i] - '0';
        int d2 = s2[i] - '0';
        if (d1 + d2 != 9) {
            not_nine++;
        }
    }

    if (not_nine == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO " << not_nine << endl;
    }

    return 0;
}
