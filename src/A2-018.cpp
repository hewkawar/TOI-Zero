#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    bool found_buu = false;
    string s_upper = s;
    for (char& c : s_upper) c = toupper(c);
    
    if (s_upper.find("BUU") != string::npos) {
        found_buu = true;
    }
    
    if (found_buu) {
        int max_u = 0;
        for (int i = 0; i < s_upper.length(); i++) {
            if (s_upper[i] == 'B') {
                int u_count = 0;
                for (int j = i + 1; j < s_upper.length(); j++) {
                    if (s_upper[j] == 'U') {
                        u_count++;
                    } else {
                        break;
                    }
                }
                max_u = max(max_u, u_count);
            }
        }
        cout << "Yes " << max_u << endl;
    } else {
        if (s_upper.find('B') != string::npos) {
            int first_b_idx = s_upper.find('B');
            string result = s;
            for (int i = first_b_idx + 1; i < result.length(); i++) {
                result[i] = 'U';
            }
            cout << result << endl;
        } else {
            string result = "";
            string buu = "BUU";
            for (int i = 0; i < s.length(); i++) {
                result += buu[i % 3];
            }
            cout << result << endl;
        }
    }

    return 0;
}
