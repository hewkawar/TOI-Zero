#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        bool good = true;
        if (i > 0 && h[i - 1] > h[i]) good = false;
        if (i < n - 1 && h[i + 1] > h[i]) good = false;
        if (good) count++;
    }

    cout << count << endl;

    return 0;
}
