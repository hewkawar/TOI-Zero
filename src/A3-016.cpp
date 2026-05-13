#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;
    
    vector<vector<int>> rules(n + 1); // target -> list of rules
    vector<int> target(m);
    vector<int> counts(m); // remaining conditions
    
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        counts[i] = k;
        for (int j = 0; j < k; ++j) {
            int s;
            cin >> s;
            rules[s].push_back(i);
        }
        cin >> target[i];
    }
    
    vector<bool> on(n + 1, false);
    queue<int> q;
    
    on[1] = true;
    q.push(1);
    
    int total_on = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        total_on++;
        
        for (int r_idx : rules[u]) {
            counts[r_idx]--;
            if (counts[r_idx] == 0) {
                int t = target[r_idx];
                if (!on[t]) {
                    on[t] = true;
                    q.push(t);
                }
            }
        }
    }
    
    cout << total_on << "\n";
    return 0;
}
