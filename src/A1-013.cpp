#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    char c;
    string num;
    if (cin >> c >> num) {
        bool char_ok = (c == 'H');
        bool num_ok = (num == "4567");
        
        if (char_ok && num_ok) {
            cout << "safe unlocked\n";
        } else if (char_ok && !num_ok) {
            cout << "safe locked - change digit\n";
        } else if (!char_ok && num_ok) {
            cout << "safe locked - change char\n";
        } else {
            cout << "safe locked\n";
        }
    }
    
    return 0;
}
