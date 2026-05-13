#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    // Pattern: 
    // level 1: 1 -> 0
    // level 2: 2 3 4 -> 1
    // level 3: 5 6 7 8 9 -> 2
    // level k: sum(2i-1) for i=1 to k -> 3
    
    long long level = 1;
    long long count = 1;
    while (count < n) {
        level++;
        count += 2 * level - 1;
    }
    
    cout << level - 1 << "\n";
    return 0;
}
