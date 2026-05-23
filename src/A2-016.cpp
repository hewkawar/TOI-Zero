#include <iostream>
#include <string>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char win_char, my_char;
    string win_num, my_num;

    if (!(cin >> win_char >> win_num)) return 0;

    if (!(cin >> my_char >> my_num)) return 0;

    int prize = 0;

    bool char_match = (win_char == my_char);
    bool num_match = (win_num == my_num);

    bool last3_match = (win_num.substr(2, 3) == my_num.substr(2, 3));
    bool last2_match = (win_num.substr(3, 2) == my_num.substr(3, 2));

    if (num_match && char_match) {
        prize = 1000000;
    } else if (num_match && !char_match) {
        prize = 100000;
    } else if (last3_match && char_match) {
        prize = 2000;
    } else if (last2_match && char_match) {
        prize = 1000;
    } else if (last3_match && !char_match) {
        prize = 200;
    } else if (last2_match && !char_match) {
        prize = 100;
    } else if (char_match) {
        prize = 20;
    } else {
        prize = 0;
    }

    cout << prize << "\n";

    return 0;
}