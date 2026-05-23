#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    if (!(cin >> q)) return 0;

    deque<string> em_q;
    deque<string> norm_q;

    for (int i = 0; i < q; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "ARRIVE") {
            string name, type;
            cin >> name >> type;
            if (type == "emergency") {
                em_q.push_back(name);
            } else {
                norm_q.push_back(name);
            }
        } else if (cmd == "TREAT") {
            if (!em_q.empty()) {
                em_q.pop_front();
            } else if (!norm_q.empty()) {
                norm_q.pop_front();
            }
        } else if (cmd == "SHOW") {
            if (em_q.empty() && norm_q.empty()) {
                cout << "EMPTY\n";
            } else {
                bool first = true;
                for (const string& name : em_q) {
                    if (!first) cout << " ";
                    cout << name;
                    first = false;
                }
                for (const string& name : norm_q) {
                    if (!first) cout << " ";
                    cout << name;
                    first = false;
                }
                cout << "\n";
            }
        }
    }

    return 0;
}