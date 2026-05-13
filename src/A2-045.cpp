#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        
        string s_lower = s;
        for (char& c : s_lower) c = tolower(c);
        
        bool has_hello = false;
        regex re_hello("\\b(hello|hi)\\b");
        if (regex_search(s_lower, re_hello)) {
            has_hello = true;
        }

        // Check condition 2: "bye" or "goodbye" as whole word
        bool has_bye = false;
        regex re_bye("\\b(bye|goodbye)\\b");
        if (regex_search(s_lower, re_bye)) {
            has_bye = true;
        }

        // Check condition 3: ends with '?'
        bool ends_with_q = false;
        if (!s.empty() && s.back() == '?') {
            ends_with_q = true;
        }

        // Check condition 4: contains at least one digit
        bool has_digit = false;
        for (char c : s) {
            if (isdigit(c)) {
                has_digit = true;
                break;
            }
        }

        // Check condition 5: length > 19 without whitespace
        int no_ws_len = 0;
        for (char c : s) {
            if (!isspace(c)) {
                no_ws_len++;
            }
        }
        bool is_long = (no_ws_len > 19);

        // Apply rules in order of priority
        if (has_hello) {
            cout << "Hello! How can I help you?" << endl;
        } else if (has_bye) {
            cout << "Goodbye! Have a nice day!" << endl;
        } else if (ends_with_q) {
            cout << "That's an interesting question!" << endl;
        } else if (has_digit) {
            cout << "I see some numbers there!" << endl;
        } else if (is_long) {
            cout << "That's quite a long message!" << endl;
        } else {
            cout << "I understand." << endl;
        }
    }

    return 0;
}
