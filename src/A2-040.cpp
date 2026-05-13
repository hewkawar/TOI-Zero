#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Item {
    string name;
    int qty;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Item> stock;
    string cmd;

    while (cin >> cmd && cmd != "END") {
        if (cmd == "ADD") {
            string name;
            int qty;
            cin >> name >> qty;
            bool found = false;
            for (auto& item : stock) {
                if (item.name == name) {
                    item.qty += qty;
                    found = true;
                    break;
                }
            }
            if (!found) {
                stock.push_back({name, qty});
            }
        } else if (cmd == "REMOVE") {
            string name;
            int qty;
            cin >> name >> qty;
            bool found = false;
            for (auto it = stock.begin(); it != stock.end(); ++it) {
                if (it->name == name) {
                    found = true;
                    if (it->qty < qty) {
                        cout << "Not enough stock for " << name << endl;
                        it->qty = 0;
                        stock.erase(it);
                    } else {
                        it->qty -= qty;
                        if (it->qty == 0) {
                            stock.erase(it);
                        }
                    }
                    break;
                }
            }
            if (!found) {
                cout << "Not enough stock for " << name << endl;
            }
        } else if (cmd == "CHECK") {
            vector<string> low_stock;
            for (auto& item : stock) {
                if (item.qty < 5) {
                    low_stock.push_back(item.name);
                }
            }
            if (low_stock.empty()) {
                cout << "All stocks are sufficient" << endl;
            } else {
                for (size_t i = 0; i < low_stock.size(); i++) {
                    for (size_t j = i + 1; j < low_stock.size(); j++) {
                        if (low_stock[i] > low_stock[j]) {
                            swap(low_stock[i], low_stock[j]);
                        }
                    }
                }
                for (auto& name : low_stock) {
                    cout << name << endl;
                }
            }
        } else if (cmd == "REPORT") {
            vector<Item> report_stock = stock;
            for (size_t i = 0; i < report_stock.size(); i++) {
                for (size_t j = i + 1; j < report_stock.size(); j++) {
                    if (report_stock[i].name > report_stock[j].name) {
                        swap(report_stock[i], report_stock[j]);
                    }
                }
            }
            for (auto& item : report_stock) {
                if (item.qty > 0) {
                    cout << item.name << ": " << item.qty << endl;
                }
            }
        }
    }

    return 0;
}
