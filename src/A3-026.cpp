#include <iostream>
#include <vector>
#include <string>

using namespace std;

int char_to_val(char c) {
    if (c == '-') return 0;
    if (c == '+') return 1;
    if (c == 'x') return 2;
    if (c == '*') return 3;
    return 0;
}

char val_to_char(int v) {
    if (v == 0) return '-';
    if (v == 1) return '+';
    if (v == 2) return 'x';
    if (v == 3) return '*';
    return '-';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;
    
    vector<string> img1(n);
    for (int i = 0; i < n; ++i) {
        cin >> img1[i];
    }
    
    vector<string> img2(n);
    for (int i = 0; i < n; ++i) {
        cin >> img2[i];
    }
    
    for (int i = 0; i < n; ++i) {
        string res = "";
        for (int j = 0; j < m; ++j) {
            int v1 = char_to_val(img1[i][j]);
            int v2 = char_to_val(img2[i][j]);
            res += val_to_char(v1 | v2);
        }
        cout << res << "\n";
    }
    
    return 0;
}
