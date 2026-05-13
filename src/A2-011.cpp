#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums;
    set<int> seen;

    for (int i = 0; i < 10; i++) {
        int x;
        if (!(cin >> x)) break;
        if (seen.find(x) == seen.end()) {
            seen.insert(x);
            nums.push_back(x);
        }
    }

    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i] << (i == nums.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
