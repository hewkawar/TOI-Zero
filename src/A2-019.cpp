#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    
    if (!(cin >> s)) return 0;

    int n = s.length();
    int max_u_count = 0;
    int first_b_idx = -1;
    
    for (int i = 0; i < n; ++i) {
        if (tolower(s[i]) == 'b') {
            
            if (first_b_idx == -1) {
                first_b_idx = i;
            }
            
            int u_count = 0;
            int j = i + 1;
            while (j < n && tolower(s[j]) == 'u') {
                u_count++;
                j++;
            }
            
            max_u_count = max(max_u_count, u_count);
        }
    }
    
    if (max_u_count >= 2) {
        cout << "Yes " << max_u_count << "\n";
    } else if (first_b_idx != -1) {
        string result = s;
        for (int i = first_b_idx + 1; i < n; ++i) {
            result[i] = 'U';
        }
        cout << result << "\n";
        
    } else {
        string pattern = "BUU";
        for (int i = 0; i < n; ++i) {
            cout << pattern[i % 3];
        }
        cout << "\n";
    }

    return 0;
}