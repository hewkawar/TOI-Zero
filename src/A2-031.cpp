#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int start = 1;
    for (int i = 0; i < n; i++) {
        int current = start;
        for (int j = 0; j < n; j++) {
            cout << current;
            if (j < n - 1) cout << " ";
            current += n;
        }
        cout << endl;
        start++;
    }

    return 0;
}
