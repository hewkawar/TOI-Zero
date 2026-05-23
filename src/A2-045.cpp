#include <iostream>

using namespace std;

int check_blockchain(int current_id, bool &only_one) {
    int prev_hash, hash;
    if (!(cin >> prev_hash >> hash)) return -1;

    if (hash == 0) {
        if (current_id == 1) {
            only_one = true;
        }
        return prev_hash;
    }

    int next_prev_hash = check_blockchain(current_id + 1, only_one);

    if (next_prev_hash == hash) {
        cout << current_id << "P\n";
    } else {
        cout << current_id << "X\n";
    }

    return prev_hash;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool only_one = false;
    check_blockchain(1, only_one);
    
    if (only_one) {
        cout << "1X\n";
    }

    return 0;
}