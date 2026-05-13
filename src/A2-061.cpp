#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Team {
    string name;
    int points;
};

bool compareTeams(const Team& a, const Team& b) {
    if (a.points != b.points) {
        return a.points > b.points;
    }
    return a.name < b.name;
}

int main() {
    vector<Team> teams = {
        {"CHE", 0},
        {"LIV", 0},
        {"MUN", 0},
        {"NEW", 0}
    };
    
    int pairs[6][2] = {
        {0, 1},
        {0, 2},
        {0, 3},
        {1, 2},
        {1, 3},
        {2, 3}
    };
    
    for (int i = 0; i < 6; ++i) {
        int a, b;
        cin >> a >> b;
        int t1 = pairs[i][0];
        int t2 = pairs[i][1];
        if (a > b) {
            teams[t1].points += 3;
        } else if (a < b) {
            teams[t2].points += 3;
        } else {
            teams[t1].points += 1;
            teams[t2].points += 1;
        }
    }
    
    sort(teams.begin(), teams.end(), compareTeams);
    
    for (int i = 0; i < 4; ++i) {
        cout << i + 1 << ". " << teams[i].name << " " << teams[i].points << "\n";
    }
    
    return 0;
}
