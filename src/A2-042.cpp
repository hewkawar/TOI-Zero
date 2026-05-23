#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string cmd;
    map<string, int> stock;
    vector<string> outputs;

    while (cin >> cmd) {
        if (cmd == "END") {
            break;
        } else if (cmd == "ADD") {
            string name;
            int qty;
            cin >> name >> qty;
            stock[name] += qty;
        } else if (cmd == "REMOVE") {
            string name;
            int qty;
            cin >> name >> qty;
            
            if (stock.find(name) == stock.end()) {
                outputs.push_back("Not enough stock for " + name);
            } else {
                if (qty > stock[name]) {
                    outputs.push_back("Not enough stock for " + name);
                    stock[name] = 0;
                } else {
                    stock[name] -= qty;
                }
                
                if (stock[name] == 0) {
                    stock.erase(name);
                }
            }
        } else if (cmd == "CHECK") {
            bool found = false;
            for (auto const& [name, qty] : stock) {
                if (qty < 5) {
                    outputs.push_back(name);
                    found = true;
                }
            }
            if (!found) {
                outputs.push_back("All stocks are sufficient");
            }
        } else if (cmd == "REPORT") {
            for (auto const& [name, qty] : stock) {
                if (qty > 0) {
                    outputs.push_back(name + ": " + to_string(qty));
                }
            }
        }
    }

    for (const string& out : outputs) {
        cout << out << "\n";
    }

    return 0;
}