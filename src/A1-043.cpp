#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int base, bonus, days;
    if (!(cin >> base >> bonus >> days)) return 0;

    double total;
    if (days <= 3) {
        total = base + bonus;
    } else {
        total = (base + bonus) * 1.5;
    }

    int rank;
    if (total >= 1500) rank = 5;
    else if (total >= 1000) rank = 4;
    else if (total >= 500) rank = 3;
    else if (total >= 200) rank = 2;
    else rank = 1;

    int status = 0;
    if (rank == 5 && days >= 7) status = 99;
    else if (rank == 4 && bonus > 300) status = 88;

    cout << (int)total << endl;
    cout << rank << endl;
    cout << status << endl;
    
    return 0;
}
