#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;

    int score = 0;
    for (int i = 0; i < n; ++i) {
        char op;
        if (cin >> op) {
            if (op == '+') score += 10;
            else if (op == '-') score -= 5;
        }
    }

    cout << score << endl;
    
    return 0;
}
