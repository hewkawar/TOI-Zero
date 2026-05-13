#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char first_color;
    int n;
    cin >> first_color >> n;

    vector<string> colors = {"Red", "Green", "Blue"};
    int start_idx = 0;
    
    if (first_color == 'R') start_idx = 0;
    else if (first_color == 'G') start_idx = 1;
    else if (first_color == 'B') start_idx = 2;

    for (int i = 0; i < n; i++) {
        cout << colors[(start_idx + i) % 3] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
