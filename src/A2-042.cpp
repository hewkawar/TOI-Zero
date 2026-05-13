#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Block {
    string prev_hash;
    string hash;
};

void check_blockchain(const vector<Block>& chain, int idx, int n) {
    if (idx < 0) return;

    if (n == 1) {
        cout << "1X" << endl;
        return;
    }

    if (idx == n - 1) {
        check_blockchain(chain, idx - 1, n);
        return;
    }

    bool valid = (chain[idx + 1].prev_hash == chain[idx].hash);
    cout << (idx + 1) << (valid ? "P" : "X") << endl;

    check_blockchain(chain, idx - 1, n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Block> chain;
    string prev, h;
    while (cin >> prev >> h) {
        chain.push_back({prev, h});
        if (h == "0") break;
    }

    int n = chain.size();
    if (n > 0) {
        check_blockchain(chain, n - 2, n);
    }

    return 0;
}
