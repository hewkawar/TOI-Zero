#include <iostream>
#include <vector>

using namespace std;

struct Block {
    int id;
    int prev_hash;
    int hash;
};

void check_blockchain(int current_id, int next_prev_hash, int total_blocks) {
    int prev_hash, hash;
    if (!(cin >> prev_hash >> hash)) return;

    if (hash == 0) {
        return;
    }

    check_blockchain(current_id + 1, prev_hash, total_blocks);

    if (next_prev_hash == hash) {
        cout << current_id << "P\n";
    } else {
        cout << current_id << "X\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int prev_hash, hash;
    if (!(cin >> prev_hash >> hash)) return 0;

    if (hash == 0) {
        cout << "1X\n";
    } else {
        check_blockchain(1, prev_hash, 1);
    }

    return 0;
}