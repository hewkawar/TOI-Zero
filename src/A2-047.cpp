#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;


string to_lower(string s) {
    for (char &c : s) {
        c = tolower(c);
    }
    return s;
}


vector<string> get_tokens(const string& s) {
    vector<string> tokens;
    stringstream ss(s);
    string token;
    while (ss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

void process_chatbot(const string& line) {
    vector<string> tokens = get_tokens(line);
    bool has_hello_hi = false;
    bool has_bye_goodbye = false;

    for (const string& t : tokens) {
        string lt = to_lower(t);
        if (lt == "hello" || lt == "hi") {
            has_hello_hi = true;
        }
        if (lt == "bye" || lt == "goodbye") {
            has_bye_goodbye = true;
        }
    }

    if (has_hello_hi) {
        cout << "Hello! How can I help you?\n";
        return;
    }

    if (has_bye_goodbye) {
        cout << "Goodbye! Have a nice day!\n";
        return;
    }

    string trimmed = line;
    while (!trimmed.empty() && isspace(trimmed.back())) {
        trimmed.pop_back();
    }

    if (!trimmed.empty() && trimmed.back() == '?') {
        cout << "That's an interesting question!\n";
        return;
    }

    bool has_digit = false;
    int non_ws_count = 0;
    for (char c : line) {
        if (!isspace(c)) {
            non_ws_count++;
            if (isdigit(c)) {
                has_digit = true;
            }
        }
    }

    if (has_digit) {
        cout << "I see some numbers there!\n";
        return;
    }

    if (non_ws_count > 19) {
        cout << "That's quite a long message!\n";
        return;
    }

    cout << "I understand.\n";
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    cin.ignore(); 

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        process_chatbot(line);
    }

    return 0;
}