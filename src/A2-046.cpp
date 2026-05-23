#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_vowel(char c) {
    char lc = tolower(c);
    return (lc == 'a' || lc == 'e' || lc == 'i' || lc == 'o' || lc == 'u');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    cin.ignore(); 

    for (int i = 1; i <= t; ++i) {
        string line;
        getline(cin, line);

        int total_vowels = 0;
        int max_consec = 0;
        int current_consec = 0;

        for (char c : line) {
            if (is_vowel(c)) {
                total_vowels++;
                current_consec++;
                max_consec = max(max_consec, current_consec);
            } else {
                current_consec = 0;
            }
        }

        cout << "Line " << i << ": vowels = " << total_vowels << ", max_consecutive = " << max_consec << "\n";
    }

    return 0;
}