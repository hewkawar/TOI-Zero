#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    int total = a * 10 + b * 25 + c * 3;
    cout << total << endl;

    return 0;
}
