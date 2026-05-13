#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    deque<string> normal_queue;
    deque<string> emergency_queue;

    for (int i = 0; i < q; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "ARRIVE") {
            string name, type;
            cin >> name >> type;
            if (type == "normal") {
                normal_queue.push_back(name);
            } else if (type == "emergency") {
                emergency_queue.push_back(name);
            }
        } else if (cmd == "TREAT") {
            if (!emergency_queue.empty()) {
                emergency_queue.pop_front();
            } else if (!normal_queue.empty()) {
                normal_queue.pop_front();
            }
        } else if (cmd == "SHOW") {
            if (emergency_queue.empty() && normal_queue.empty()) {
                cout << "EMPTY" << endl;
            } else {
                bool first = true;
                for (const string& name : emergency_queue) {
                    if (!first) cout << " ";
                    cout << name;
                    first = false;
                }
                for (const string& name : normal_queue) {
                    if (!first) cout << " ";
                    cout << name;
                    first = false;
                }
                cout << endl;
            }
        }
    }

    return 0;
}
