#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, s;
    if (!(cin >> n >> s)) return 0;
    
    vector<int> target(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> target[i];
    }
    
    vector<bool> visited(n + 1, false);
    int current = s;
    int count = 0;
    
    while (current != 0 && !visited[current]) {
        visited[current] = true;
        count++;
        current = target[current];
    }
    
    cout << count << "\n";
    
    return 0;
}
