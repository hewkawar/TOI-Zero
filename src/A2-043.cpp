#include <iostream>
#include <string>
#include <vector>

using namespace std;

int count_vowels(const string& s) {
    int count = 0;
    for (char c : s) {
        char lc = tolower(c);
        if (lc == 'a' || lc == 'e' || lc == 'i' || lc == 'o' || lc == 'u') {
            count++;
        }
    }
    return count;
}

int max_consecutive_vowels(const string& s) {
    int max_consec = 0;
    int current_consec = 0;
    for (char c : s) {
        char lc = tolower(c);
        if (lc == 'a' || lc == 'e' || lc == 'i' || lc == 'o' || lc == 'u') {
            current_consec++;
            max_consec = max(max_consec, current_consec);
        } else {
            current_consec = 0;
        }
    }
    return max_consec;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    cin.ignore();

    for (int i = 1; i <= t; i++) {
        string line;
        getline(cin, line);
        
        int vowels = count_vowels(line);
        int max_consec = max_consecutive_vowels(line);
        
        cout << "Line " << i << ": vowels = " << vowels << ", max_consecutive = " << max_consec << endl;
    }

    return 0;
}
