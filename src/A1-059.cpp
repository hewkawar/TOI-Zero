#include <iostream>

using namespace std;

#include <string>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string origin, dest;
    int weight;
    if (!(cin >> origin >> dest >> weight)) return 0;

    int base = 0, rate = 0;
    bool found = false;

    if (origin == "BKK" && dest == "CNX") { base = 10; rate = 30; found = true; }
    else if (origin == "CNX" && dest == "UBP") { base = 15; rate = 40; found = true; }
    else if (origin == "UBP" && dest == "BKK") { base = 20; rate = 40; found = true; }
    else if (origin == "BKK" && dest == "PKT") { base = 25; rate = 50; found = true; }
    else if (origin == "PKT" && dest == "CNX") { base = 30; rate = 60; found = true; }
    else if (origin == "UBP" && dest == "PKT") { base = 40; rate = 70; found = true; }

    if (found) {
        cout << base + (weight * rate) << endl;
    } else {
        cout << "Error" << endl;
    }
    
    return 0;
}
