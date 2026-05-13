#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    
    map<char, int> counts;
    for (char c : s) {
        char lc = tolower(c);
        if (lc == 'a' || lc == 'e' || lc == 'i' || lc == 'o' || lc == 'u') {
            counts[lc]++;
        }
    }
    
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    for (char v : vowels) {
        if (counts[v] > 0) {
            cout << v << ": " << counts[v] << "\n";
        }
    }
    
    return 0;
}
