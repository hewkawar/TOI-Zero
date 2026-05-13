#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    if (!(cin >> s)) return 0;

    string rank, suit;
    char suitChar;

    if (s.length() == 3 && s.substr(0, 2) == "10") {
        rank = "10";
        suitChar = s[2];
    } else {
        char r = toupper(s[0]);
        if (r == 'A') rank = "ace";
        else if (r == 'J') rank = "jack";
        else if (r == 'Q') rank = "queen";
        else if (r == 'K') rank = "king";
        else rank = string(1, s[0]);
        suitChar = s[1];
    }

    char sc = toupper(suitChar);
    if (sc == 'D') suit = "diamonds";
    else if (sc == 'H') suit = "hearts";
    else if (sc == 'S') suit = "spades";
    else if (sc == 'C') suit = "clubs";

    cout << rank << " of " << suit << endl;
    
    return 0;
}
