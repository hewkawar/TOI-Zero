#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    cin >> n >> c;

    vector<vector<int>> wins(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> wins[i][j];
        }
    }

    vector<int> current_teams(n);
    for (int i = 0; i < n; i++) {
        current_teams[i] = i + 1;
    }
    
    bool c_used = false;

    while (current_teams.size() > 1) {
        vector<int> next_teams;
        for (size_t i = 0; i < current_teams.size(); i += 2) {
            int t1 = current_teams[i];
            int t2 = current_teams[i+1];
            int winner = wins[t1][t2];
            
            if (c > 0 && !c_used) {
                if (t1 == c && winner != c) {
                    winner = c;
                    c_used = true;
                } else if (t2 == c && winner != c) {
                    winner = c;
                    c_used = true;
                }
            }
            
            next_teams.push_back(winner);
        }
        current_teams = next_teams;
    }

    cout << current_teams[0] << endl;

    return 0;
}
