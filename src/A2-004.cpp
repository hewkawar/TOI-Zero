#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    multiset<int> stacks;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        auto it = stacks.upper_bound(x);
        if (it != stacks.end()) {
            stacks.erase(it);
        }
        stacks.insert(x);
    }

    cout << stacks.size() << endl;

    return 0;
}
