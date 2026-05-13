#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    string p1 = s1;
    string p2 = s2;
    int max_len = max(p1.length(), p2.length());
    
    int idx1 = 0;
    while (p1.length() < max_len) {
        p1 += s1[idx1 % s1.length()];
        idx1++;
    }
    
    int idx2 = 0;
    while (p2.length() < max_len) {
        p2 += s2[idx2 % s2.length()];
        idx2++;
    }

    string amulet = "";
    int w_count = 0;
    int w_consecutive = 0;
    int max_w_consecutive = 0;

    for (int i = 0; i < max_len; i++) {
        char c1 = tolower(p1[i]);
        char c2 = tolower(p2[i]);
        
        bool match1 = (c1 == 'l' || c1 == 'o' || c1 == 'v' || c1 == 'e');
        bool match2 = (c2 == 'l' || c2 == 'o' || c2 == 'v' || c2 == 'e');
        
        if (match1 || match2) {
            amulet += "w";
            w_count++;
            w_consecutive++;
            max_w_consecutive = max(max_w_consecutive, w_consecutive);
        } else {
            amulet += "$";
            w_consecutive = 0;
        }
    }

    if (w_count % 2 != 0) {
        amulet += to_string(w_count);
    } else {
        if (max_w_consecutive < 2) {
            amulet += "#";
        }
    }

    cout << amulet << endl;

    return 0;
}
