#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int len;
    cin >> len;

    string s1 = "", s2 = "";
    for (int i = 0; i < len; i++) {
        string t;
        cin >> t;
        s1 += t;
    }
    for (int i = 0; i < len; i++) {
        string t;
        cin >> t;
        s2 += t;
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int strand, pos;
        string new_gene;
        cin >> strand >> pos >> new_gene;
        if (strand == 1) {
            s1[pos] = new_gene[0];
        } else {
            s2[pos] = new_gene[0];
        }
    }

    for (int i = 0; i < len; i++) {
        cout << s1[i] << (i == len - 1 ? "" : " ");
    }
    cout << endl;
    for (int i = 0; i < len; i++) {
        cout << s2[i] << (i == len - 1 ? "" : " ");
    }
    cout << endl;

    int mismatch = 0;
    for (int i = 0; i < len; i++) {
        if ((s1[i] == 'A' && s2[i] == 'T') || (s1[i] == 'T' && s2[i] == 'A') || (s1[i] == 'C' && s2[i] == 'G') || (s1[i] == 'G' && s2[i] == 'C')) {
            // Match
        } else {
            mismatch++;
        }
    }

    cout << mismatch << endl;

    return 0;
}
