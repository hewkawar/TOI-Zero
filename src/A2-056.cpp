#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        counts[x]++;
    }
    vector<int> unique_codes;
    for (auto const& [code, count] : counts) {
        if (count == 1) {
            unique_codes.push_back(code);
        }
    }
    
    if (unique_codes.empty()) {
        cout << "\n";
    } else {
        for (size_t i = 0; i < unique_codes.size(); ++i) {
            cout << unique_codes[i] << (i + 1 == unique_codes.size() ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}
